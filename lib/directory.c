#include "directory.h"

int create_folder(char *m){

    if(mkdir(m,0777) == 0){
        module = m;
        return 1;
    }
    return 0;
}

int verified_folder(char *path){

    if(chdir(path) == 0 ){
        project = path;
        return 1;
    }
    return 0;
}

void create_template(){
    return;
}
