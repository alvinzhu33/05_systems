#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

void totalSize(DIR *stream){  
  printf("Size: ");
  int size;
  while(readdir(stream)){
    struct stat info;
    struct dirent *file = readdir(stream);
    stat(file->d_name, &info);
    size += info.st_size;
    /*if(size >= 1000000000){
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
      }*/
  }
}

void ls(DIR *stream){
  while(readdir(stream)){
    struct dirent *file = readdir(stream);
    printf("%s ", file->d_name);
    if(file->d_type==4){
      printf("[REPO]");
    }
    printf("\n");
  }
}

int main(){
  DIR *stream = opendir(".");
  ls(stream);
  totalSize(stream);
  
  return 0;
}
