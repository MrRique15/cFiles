#define maxfila 50

typedef int tipoDado;

typedef struct{
    tipoDado fila[maxfila + 1];
    int primeiro;
    int ultimo;
    int total;
}tipoFila;

void criafila(tipoFila *F){
    F->total = 0;
    F->ultimo = 0;
    F->primeiro = 1;
}

int proxposfila(int pos){
    return ((pos+1)%(maxfila+1));  //retorna a posicao 0 se atingir o final da fila
}

int filavazia(tipoFila F){
    return (proxposfila(F.ultimo)==F.primeiro);  //retorna verdadeiro ou falso
}

int filacheia(tipoFila F){
    int aux;
    aux = proxposfila(F.ultimo);
    return (proxposfila(aux)==F.primeiro);
}

int totalfila(tipoFila F){
    return (F.total);
}

void inserefila(tipoFila *F, tipoDado x){
    F->ultimo = proxposfila(F->ultimo);
    F->total++;
    F->fila[F->ultimo] = x;
}

void removefila(tipoFila *F, tipoDado *x){
    *x = F->fila[F->primeiro];
    F->primeiro = proxposfila(F->primeiro);
    F->total--;
}

tipoDado primeirofila(tipoFila F){
    return (F.fila[F.primeiro]);
}

tipoDado ultimofila(tipoFila F){
    return (F.fila[F.ultimo]);
}