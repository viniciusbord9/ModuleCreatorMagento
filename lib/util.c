#include "util.h"


int copy_files(FILE* origin, FILE* destiny){
    char leitor[1000];
    int i = 0;
    while(fgets(leitor,1000,origin) != NULL){
        fputs(leitor,destiny);
    }
    return 1;

}

char* concat_string(char* first, char* second){
    int count_first = strlen(first);
    int count_second = strlen(second);
    char* aux = (char*) malloc((count_first)*sizeof(char));
    if(aux != NULL){
        int i = 0;
        int j = 0;
        for(i = 0; i < (count_first+count_second);i++){
            if(i < count_first){
                aux[i]= first[i];
            }else{
                aux[i] = second[j];
                j++;
            }
        }
    }
    return aux;
}

