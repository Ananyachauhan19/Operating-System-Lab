#include<stdio.h>
#include<dirent.h>

int main(){
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");
    if(dir == NULL){
        printf("Error\n");
        return 1;
    }
    while((entry = readdir(dir)) != NULL){
        printf("%s\n", entry->d_name);
    }
    printf("\n");
    closedir(dir);
    return 0;
}