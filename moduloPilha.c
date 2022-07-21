#include<stdio.h>
#include<stdlib.h>

#define max 100

typedef char tipoDado;
typedef struct{
    tipoDado pilha[max];
    int topo;
}tipoPilhaEst;

void criaPilhaEst(tipoPilhaEst *p){
    p->topo = -1;
}

int pilhaVazia(tipoPilhaEst p){
    return (p.topo==-1);
}

int pilhaCheia(tipoPilhaEst p){
    return (p.topo== max-1);
}

tipoDado topo(tipoPilhaEst p){
    return (p.pilha[p.topo]);
}

void inserePilhaEst(tipoPilhaEst *p, tipoDado x){
    p->topo++;
    p->pilha[p->topo] = x;
}

void removePilhaEst(tipoPilhaEst *p, tipoDado *x){
    (*x) = p->pilha[p->topo - 1];
    p->topo--;
}