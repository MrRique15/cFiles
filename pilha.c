#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "PilhaDinamica.c"

TipoDado x;
TipoPilha p;

int main(){
    char conta[200];
    int i, z, aux;
    CriaPilha(&p);
    printf("Digite sua expressão matematica\n");
    scanf("%s", conta);
    z = strlen(conta);
    for(i=0;i<=z;i++){
        x = conta[i];
        if(conta[i]=='('){
            x=1;
            InserePilha(&p, x);
        }
        else if(conta[i]==')'){
            if(PilhaVazia(p)){
                printf("\nFaltando ( na expressão\n");
                return 0;
            } else {
                RemovePilha(&p,&x);
            }
        }
    }
    if(!PilhaVazia(p)){
        printf("\nFaltando parenteses na conta\n");
    }
    else if(PilhaVazia(p)){
        printf("\nA expressao esta correta\n");
    }
}   