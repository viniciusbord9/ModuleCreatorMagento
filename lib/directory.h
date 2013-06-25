#ifndef DIRECTORY_H_INCLUDED
#define DIRECTORY_H_INCLUDED
#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
 #endif
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char *module;
char *name_space;
char *project;
char *template_folder;
char *path;
char cCurrentPath[FILENAME_MAX];

bool verified_project(char *project);

int verified_folder(char* path);

int set_path(char* path);

int create_folder(char* path);

char* get_path();

int set_name_space(char* name_space);

int set_module(char* module);

char* get_name_space();

char* get_module();

int set_folder_template();

char* get_folder_template();

char* get_template_config_path();

#endif // DIRECTORY_H_INCLUDED
