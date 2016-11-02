#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

//Thanks to stackoverflow for these colors!!!
#define GRN "\x1B[32m"
#define RESET "\x1B[0m"
#define GRY "\x1B[36m"

void printEverything(char directory[256]){
    DIR *stream = opendir(directory);
    printf(GRY "\nInfo for: " RESET "%s\n", directory);

    int size;
    struct dirent *file;
    char directories[256]="";
    char files[256]="";
    while(file = readdir(stream)){
        if(file->d_type==4){
            strcat(directories, "\t");
            strcat(directories, file->d_name);
            strcat(directories, "\n");
            //printf(GRN "%s [DIRECTORY]" RESET, file->d_name);
        }else{
            strcat(files, "\t");
            strcat(files, file->d_name);
            strcat(files, "\n");
            //printf("%s ", file->d_name);
        }

        struct stat info;
        stat(file->d_name, &info);
        int bytes = info.st_size;
        //printf("%d\n", bytes);
        size += info.st_size;
    }

    printf(GRY "Total Size: " RESET);
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

    printf(GRY "Directories: \n" RESET);
    printf(GRN "%s" RESET, directories);
    printf(GRY "\nFiles: \n" RESET);
    printf("%s\n", files);
}

int main(){
    printEverything(".");

    return 0;
}
