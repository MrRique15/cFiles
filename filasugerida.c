#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include "moduloFilaDin.c"

tipoFila F;

void imp(tipoFila F){
    tipoElem *aux;
    aux = F;  
    while(aux != NULL){
        printf("%d ", aux->Dado);
        aux = aux->prox;
    }printf("\n");
}

int main(){
    int n=0, i, resp;
    tipoDado x;
    criafilaDin(&F);
    x = rand()%10;
    for(n=0;n<150;n++){
        x = rand()%10;
        if(x<6){
            inserefilaDin(&F, x);
            sleep(2);
            imp(F);
        }else if(x=6||x>6){ 
            if(!filavaziaDin(F)){
                removefilaDin(&F,&x);
            }
            sleep(2);
            imp(F);
        }
    }
    return 0;
}