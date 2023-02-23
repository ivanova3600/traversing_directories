#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

void printDir(const char *name){
    DIR *dir = opendir(name);
    if(!dir) {
       printf("Can't open directory %s\n", name);
       return;
    }

    struct dirent *tmp;
    while((tmp = readdir(dir)) != NULL){
        if(tmp->d_type == DT_DIR){
            if (strcmp(tmp->d_name, ".") == 0 || strcmp(tmp->d_name, "..") == 0)
                continue;
            char buf[1024];
            snprintf(buf, sizeof(buf), "%s/%s", name, tmp->d_name);
            printf("%s\n", tmp->d_name);

            printDir(buf);
            
        }
        else{
            printf("%s\n", tmp->d_name);
        }
    }

    closedir(dir);
}

int main(){
    char dir[1024];
    printf("Iput directory ");
    scanf("%s", dir);

    printDir(dir);

    return 0;
}