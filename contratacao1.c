#include <stdio.h>
int resp;
void main(void){ 
    printf("Programa de Controle de Contratacao 1 \n\n");
    printf("Possui mais de 40 anos <1>Sim ou <0>Nao? \n\n");
    scanf("%d",&resp);
 if (resp==1){ 
    printf("Possui experiencia com publico <1>Sim ou <0>Nao? \n\n");
    scanf("%d",&resp);
    if (resp==1){ 
        printf("Fala Ingles <1>Sim ou <0>Nao? \n\n");
        scanf("%d",&resp);
        if (resp==1)
            printf("Qualificado para ser Secretario! \n\n");
        else
        printf("Qualificado para ser Atendente! \n\n");
    }
    else{ 
        printf("Possui Carteira de Motorista <1>Sim ou <0>Nao? \n\n");
        scanf("%d",&resp);
        if (resp==1)
            printf("Qualificado para ser Motorista! \n\n");
        else
        printf("Qualificado para ser Almoxarife! \n\n");
    }
 }
 else{
    printf("Possui mais de 25 anos <1>Sim ou <0>Nao? \n\n");
    scanf("%d", &resp);
    if(resp==1){
        printf("Possui curso de Administracao <1>Sim ou <0>Nao? \n\n");
        scanf("%d",&resp);
        if (resp==1){
            printf("Possui Pos-Graduacao <1>Sim ou <0>Nao? \n\n");
            scanf("%d",&resp);
            if (resp==1)
                printf("Qualificado para ser Diretor Administrativo! \n\n");
            else
                printf("Qualificado para ser Coordenador de RH! \n\n");
        }
        else{ 
            printf("Possui curso de Contabilidade <1>Sim ou <0>Nao? \n\n");
            scanf("%d",&resp);
            if (resp==1)
                printf("Qualificado para ser Contador! \n\n");
            else
                printf("Qualificado para ser Auxiliar Operacional! \n\n");
        }
    }
    else{
        printf("Possui carteira de motorista de moto <1>Sim <0>Nao? \n\n");
        scanf("%d", &resp);
        if(resp==1)
            printf("Qualificado para ser entregador! \n\n");
        else
            printf("Qualificado para ser Porteiro! \n\n");
    }
 }
}