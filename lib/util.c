#include "util.h"


int copy_files(FILE* origin, FILE* destiny){
    char leitor[1000];
    int i = 0;
    while(fgets(leitor,1000,origin) != NULL){
        fputs(leitor,destiny);
    }
    return 1;

}

