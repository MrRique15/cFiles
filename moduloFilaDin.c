#include<stdlib.h>
#include<stdio.h>

typedef int tipoDado;

typedef struct{
    tipoDado Dado;
    struct tipoElem *prox;
}tipoElem;

typedef tipoElem *tipoFila;

void criafilaDin(tipoFila *f){
    (*f) = NULL;
}

int filavaziaDin(tipoFila f){
    return (f==NULL);
}

void inserefilaDin(tipoFila *f, tipoDado x){
    tipoElem *aux;
    aux = malloc(sizeof(tipoElem));
    aux->Dado = x;
    aux->prox = (*f);
    (*f) = aux;         //fila aponta para o novo elemento
}

void removefilaDin(tipoFila *f, tipoDado *x){      //remove o que aponta para NULL, a ponta começo da fila
    tipoElem *ant, *post;
    post = (*f);
    ant = NULL;
    while(post->prox != NULL){      //caminha na fila para chegar em quem quer remover
        ant = post;
        post = ant->prox;
    }
    if(ant==NULL){          //deixa a fila vazia caso so tenha 1 elemento
        (*f)=NULL;
    }
    else ant->prox = NULL;
    (*x)=post->Dado;
    free(post);     //devolve memoria ja utilizada
}

int totalfilaDin(tipoFila f){
    tipoElem *aux; int total;
    total = 0;
    aux = f;
    while(aux!=NULL){
        total++;
        aux = aux->prox;
    }
    return (total);
}

tipoDado primeirofilaDin(tipoFila f){
    tipoElem *aux;
    aux = f;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    return (aux->Dado);
}

tipoDado ultimofilaDin(tipoFila f){
    return (f->Dado);
}