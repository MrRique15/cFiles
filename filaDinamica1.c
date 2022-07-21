#include<stdio.h>
#include<stdlib.h>
#include "moduloFilaDin.c"

tipoFila f;

void imp(){
    int aux;
    printf("\nPrimeiro elemento = %d", aux = primeirofilaDin(f));
    printf("\nUltimo elemento = %d", aux = ultimofilaDin(f));
    printf("\nTotal de elementos = %d", aux = totalfilaDin(f));
}

int main(){
    int n, i, resp;
    tipoDado x;
    criafilaDin(&f);
    do{
        printf("\nQuantos elementos deseja inserir?");
        scanf("%d", &n);
        for(i=1;i<=n;i++){
            inserefilaDin(&f,(2*i));
        }
        imp();
        printf("\nQuantos elemento deseja remover?");
        scanf("%d", &n);
        for(i=0;i<n;i++){
            removefilaDin(&f,&x);
            printf("\nElemento removido: %d", x);
        }
        imp();
        printf("\nDeseja Continuar? <1>Sim <0>Nao");
        scanf("%d", &resp);

    }while(resp);
    return 0;
}