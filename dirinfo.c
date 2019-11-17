#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>

int main(){

  DIR *dir;
  struct dirent * file;
  
  dir = opendir("./");
  //printf("errno: %d error %s\n", errno, strerror(errno));
  
  printf("Statistics for: .\n");
  
  int size;
  file = readdir(dir);
  struct stat buff;
  stat(file->d_name, &buff);
  
  printf("Directories:\n");
  while (file != NULL){
    
    while (S_ISDIR(buff.st_mode)){
      printf("\t%s\n", file->d_name);
      file = readdir(dir);
      stat(file->d_name, &buff);
    }
    file = readdir(dir);
    stat(file->d_name, &buff);
    
  }
  
  closedir(dir);
  dir = opendir("./");
  file = readdir(dir);
  stat(file->d_name, &buff);
  
  printf("Regular files:\n");
  while (file != NULL){
    
    while(S_ISREG(buff.st_mode) && file != NULL){
      printf("\t%s\n", file->d_name);
      size += buff.st_size;
      file = readdir(dir);
      stat(file->d_name, &buff);
    }
    if (file != NULL){
      file = readdir(dir);
      stat(file->d_name, &buff);
    }
  }
  closedir(dir);

  printf("Total Directory Size: %d Bytes\n", size);
  
}
