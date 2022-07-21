#include<stdio.h>
int resp;
void main(void){
    printf("Programa de contratação Numero 2 \n\n");
    printf("Possui Graduação em informática 1-Sim 0-Nao? \n\n");
    scanf("%d", &resp);
    if(resp==1){
        printf("Sabe Programar 1-Sim 0-Nao? \n\n");
        scanf("%d", &resp);
        if(resp==1){
            printf("Conhece Linguagem C 1-Sim 0-Nao? \n\n");
            scanf("%d", &resp);
            if(resp==1){
                printf("Tem nocoes de Administracao 1-Sim 0-Nao? \n\n");
                scanf("%d", &resp);
                if(resp==1){
                    printf("Qualificado para Analista de Sistemas! \n\n");
                }
                else{
                    printf("Tem nocoes de Redes 1-Sim 0-Nao? \n\n");
                    scanf("%d", &resp);
                    if(resp==1){
                        printf("Qualificado para Analista de Suporte! \n\n");
                    }
                    else{
                        printf("Qualificado para Programador! \n\n");
                    }
                }
            }
            else{
                printf("Fazer curso de Linguagem C! \n\n");
            }
        }
        else{
            printf("Sabe Teoria 1-Sim 0-Nao? \n\n");
            scanf("%d", &resp);
            if(resp==1){
                printf("Fazer Curso de Algoritimo/Programacao! \n\n");
            }
            else{
                printf("Qualificado para Atendente! \n\n");
            }
        }
    }
    else{
        printf("Tem curso tecnico em Informatica 1-Sim 0-Nao? \n\n");
        scanf("%d", &resp);
        if(resp==1){
            printf("Qualificado para reparador de Computador! \n\n");
        }
        else{
            printf("Sabe digitar 1-Sim 0-Nao? \n\n");
            scanf("%d", &resp);
            if(resp==1){
                printf("Qualificado para Digitador! \n\n");
            }
            else{
                printf("Sabe cozinhar 1-Sim 0-Nao? \n\n");
                scanf("%d", &resp);
                if(resp==1){
                    printf("Qualificado para Cozinheiro! \n\n");
                }
                else{
                    printf("Qualificado para Ajudante Geral! \n\n");
                }
            }
        }
    }
}