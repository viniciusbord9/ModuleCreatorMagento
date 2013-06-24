#include <stdio.h>
#include <stdlib.h>
#include "lib/directory.h"
#include "lib/template.h"

int verified_namespace(char *n_space);

int main(int arg, char *args[])
{
    /*set_folder_template();*/
    if(args[1]!=NULL)
    {
        printf("Projeto: %s \n",args[1]);
        if(args[2]!=NULL && verified_folder(args[1]))
        {
            path = args[1];
            printf("Namespace: %s\n",args[2]);
            int verified = verified_namespace(args[2]);
            if(verified==1)
            {
                name_space = args[2];
                printf("criando pasta do modulo \n");
                if(create_folder(args[3]))
                {
                    module = args[3];
                    printf("pasta criada \n");
                    char* option;
                    scanf("tipo do modulo %s\n",&option);
                    printf("%s\n",option);
                }
                else
                {
                    printf("erro ao criar o folder \n");
                }
            }
            else
            {
                printf("não existe namespace com esse nome \n ");
                if(args[2]!=NULL && verified == 0)
                {
                    printf("criando o namespace \n");
                    if(create_folder(args[2]))
                    {
                        name_space = args[2];
                        chdir(args[2]);
                        printf("criando pasta do modulo \n");
                        if(create_folder(args[3]))
                        {
                            printf("pasta criada \n");
                            chdir(args[3]);
                            set_module(args[3]);
                            printf("selecione a opção de módulo que você deseja\n");
                            printf("1. simples(etc/config.xml, diretório controller e Block ).\n2. básico (todos os diretórios e também o arquivo de configuração). \n");
                            int option;
                            printf("escolha o tipo do módulo:\n");
                            scanf("%d",&option);
                            printf("opção escolhida %d\n",option);
                            printf("criando template");
                            create_template(option);
                        }
                        else
                        {
                            printf("erro ao criar o folder \n");
                        }
                    }else{
                        printf("erro ao criar o namespace \n");
                    }
                }else{
                    printf("verifique a estrutura de seu projeto \n");
                }

            }
        }
        else
            printf("Nenhum namespace foi  especificado \n");
    }
    else
    {
        printf("Nenhum Projeto foi especificado \n");
    }
    return 0;
}

int verified_namespace(char *n_space)
{
    if(chdir("app")!= 0)
    {
        printf("não existe o diretório app no projeto \n");
        return -1;
    }
    else
    {
        if(chdir("code")!= 0)
        {
            printf("não existe o diretório code no projeto \n");
            return -1;
        }
        else
        {
            if(chdir("local")!= 0)
            {
                printf("não existe o diretório local no projeto \n");
                return -1;
            }
        }

    }

    if(chdir(n_space) == 0 )
    {
        name_space = n_space;
        return 1;
    }
    return 0;
}


