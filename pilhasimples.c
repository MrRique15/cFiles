#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "PilhaDinamica.c"

TipoDado x;
TipoPilha p;

int main(){
    int i;
    CriaPilha(&p);
    for(i=10;i<50;i++){
        x=i;
        InserePilha(&p,x);
    }
    while(!PilhaVazia(p)){
        RemovePilha(&p,&x);
        printf("\nx = %d", x);
    }
    return 0;
}   