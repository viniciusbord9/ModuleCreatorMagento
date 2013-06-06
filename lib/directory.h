#ifndef DIRECTORY_H_INCLUDED
#define DIRECTORY_H_INCLUDED
#include <stdbool.h>

char *module;
char *project;

bool verified_project(char *project);

int verified_folder(char* path);

int set_path(char* path);

int create_folder(char* path);

char* get_path();

void create_template();


#endif // DIRECTORY_H_INCLUDED
