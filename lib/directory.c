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
    module = path;
}

char* get_path(){
    return module;
}

int set_name_space(char* name_space){
    name_space = name_space;
}

int set_module(char* module){
    module = module;
}

char* get_name_space(){
    return name_space;
}

char* get_module(){
    return module;
}

int set_folder_template(){
    char* path = _fullpath(NULL, ".", 0);
    char* folder = "\\Template";
    char* aux = (char*) malloc (sizeof(path));
    strcpy(aux,path);
    strcat(aux,folder);
    template_folder = aux;
    free(&folder);
    return;
}

char* get_folder_template(){
    return template_folder;
}
