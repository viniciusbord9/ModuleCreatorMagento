#include "template.h"
#include "util.h"

int create_template(option){
    if(option == 1){
        if(create_config()==0){
            set_config();
        }
    }
}

int create_config(){
   mkdir("etc");
    if(chdir("etc") == 0){
        set_config();
        return 1;
        //FILE* destiny = fopen("config.xml","w");
        //copy_files(origin,destiny);
        //fclose(destiny);
        //fclose(origin);
        return 0;
    }else{
        printf("erro ao entrar na pasta etc");
    }

    return 0;
}

void set_config(){
    char* path_config = "C:\\Users\\vinicius\\Documents\\ModuleCreatorMagento\\Templates\\Simples\\etc\\config.xml";
    FILE* origin = fopen(path_config,"r");
    FILE* config = fopen("config.xml","w");
    char ch;
    if(config == NULL){
        printf("ERROR: Não foi possível abrir o arquivo de configuração");
        return;
    }
    int status = 0;
    int count_char = 0;
    int position = 0;
    char *options = NULL;
    char *aux  = NULL;
    char *buffer = NULL;
    while((ch = fgetc(origin)) != EOF){
        if(ch =='{'){
            status = 1;
            printf("\n");
        }

        if(status){
            printf("%c",ch);
            count_char++;
            aux = (char*)realloc(options,count_char*sizeof(char));
            if(aux != NULL){
                options = aux;
                options[count_char-1] = ch;
            }
        }

        if(ch =='}'){
            status = 0;
            char tag[count_char];
            strncpy(tag,options,count_char);
            if(strncmp(tag,"{Module}",count_char-1)==0){
                //fseek(config, ftell(origin)-8,SEEK_SET);
                fputs("Teste",config);
            }

            if(strncmp(tag,"{Alias_Module}",count_char-1)==0){
                //fseek(config, ftell(origin)-14,SEEK_SET);
                fputs("teste_teste",config);
            }

            if(strncmp(tag,"{Front_Name}",count_char-1)==0){
                //fseek(config, ftell(origin)-11,SEEK_SET);
                fputs("FirstModule",config);
            }

            printf("%d",count_char);
            printf("%s",options);
            count_char = 0;
        }

        if(!status && ch!='}' && ch !='{'){
            fputc(ch,config);
        }

    }
    fclose(config);
    return;


}

