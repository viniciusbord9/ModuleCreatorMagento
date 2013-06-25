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
    if(!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
    {
        return 0;
    }

    cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */
    return;
}

char* get_folder_template(){
    return cCurrentPath;
}

char* get_template_config_path(){
    char* relative_config_path = "/Template/Simples/etc/config.xml";
    int size_path = sizeof(cCurrentPath) + sizeof(relative_config_path);
    char config_path[size_path];
    strcat(config_path,cCurrentPath);
    strcat(config_path,relative_config_path);
    return config_path;
}
