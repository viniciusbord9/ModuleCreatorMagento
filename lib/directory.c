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

int set_path(char* path){
    module_name = path;
}

char* get_path(){
    return module_name
}
