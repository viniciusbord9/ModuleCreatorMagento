#include "template.h"
#include "util.h"

int create_template(option,name_space,module_name){
    if(option ==1){
        if(create_config()==0){
            set_config();
        }
    }
}

int create_config(){
    FILE* origin = fopen("/home/pontocom/ModuleCreatorMagento/Templates/Simples/etc/config.xml","r");
    if(origin == NULL){
        printf("ERROR: arquivo não encontrado na pasta Template");
        return 1;
    }else{
        mkdir("etc",0777);
        if(chdir("etc") == 0){
            FILE* destiny = fopen("config.xml","w");
            copy_files(origin,destiny);
            fclose(destiny);
            fclose(origin);
            return 0;
        }else{
            printf("erro ao entrar na pasta etc");
        }
    }
    return 1;
}

void set_config(){
    FILE* config = fopen("config.xml","r+");
    char ch;
    if(config == NULL){
        printf("ERROR: Não foi possível abrir o arquivo de configuração");
        return;
    }
    int position = 0;
    int status = 0;
    int count_char = 0;
    char *options = NULL;
    char *aux  = NULL
    while((ch = fgetc(config)) != EOF){
        if(ch =='{'){
            position = ftell(config);
            status = 1;
            printf("\n");
        }

        if(status){
            printf("%c",ch);
            count_char++;
            aux = (char*)realloc(option,count_char*sizeof(char));
            if(aux != NULL){
                options = aux;
                options[count_char-1] = ch
            }
        }

        if(ch =='}'){
            status = 0;
            printf("%d",count_char);
            printf("%s",options);
            count_char = 0;
        }

    }
    fclose(config);
    return;


}

