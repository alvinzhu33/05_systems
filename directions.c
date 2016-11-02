#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

//Thanks to stackoverflow for these colors!!!
#define GRN "\x1B[32m"
#define RESET "\x1B[0m"


int main(){
    DIR *stream = opendir(".");
    printf("\nEverything in THIS directory:\n");

    int size;
    struct dirent *file;
    while(file = readdir(stream)){
        if(file->d_type==4){
            printf(GRN "%s [REPO]" RESET, file->d_name);
        }else{
            printf("%s ", file->d_name);
        }
        printf("\n");

        struct stat info;
        stat(file->d_name, &info);
        int bytes = info.st_size;
        //printf("%d\n", bytes);
        size += info.st_size;
    }
    printf("\nTotal Size: ");

    if(size >= 1000000000){
        printf("%d.%d GB\n", size/1000000000, size%1000000000/1000000);
    }else{
        if(size >= 1000000){
            printf("%d.%d MB\n", size/1000000, size%1000000/1000);
        }else{
            if(size >= 1000){
                printf("%d.%d KB\n", size/1000, size%1000);
            }else{
                printf("%d B\n", size);
            }
        }
    }
    printf("\n");

    return 0;
}
