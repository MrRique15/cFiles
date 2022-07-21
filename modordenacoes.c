#include <stdio.h>

#define maxvet 100

typedef int tipovetor[maxvet];


void selectionSort(tipovetor A, int tam)
{   int posOrd, posProc, posMenor, aux;

    for(posOrd = 0; posOrd < tam-1; posOrd++){
      posMenor = posOrd;
      for(posProc = posOrd+1; posProc < tam; posProc++){
        if(A[posMenor] > A[posProc]){
          posMenor=posProc;
        }
      }
      aux = A[posOrd];
      A[posOrd] = A[posMenor];
      A[posMenor] = aux;
    }
}

void bubbleSort(tipovetor A, int tam)
{   int posComp, ultimo, aux, posTroca;

    ultimo = tam-1;

    while(ultimo > 0){
      posTroca = 0;
      for(posComp=0; posComp < ultimo; posComp++){

        if(A[posComp] > A[posComp+1]){

          aux = A[posComp];
          A[posComp] = A[posComp+1];
          A[posComp+1] = aux;
          posTroca=posComp;
        }
      }
      ultimo = posTroca;
    }
}

int insertionSort(tipovetor A, int tam)
{   int ultimo, prox, ant, aux;

    for(ultimo=0; ultimo < tam-1; ultimo++){

        prox = ultimo+1;
        aux = A[prox];
        ant = ultimo;
        while((aux < A[ant] )&& (ant >= 0)){

          A[ant+1] = A[ant];
          ant--;
        }
        A[ant+1] = aux;
      }
}

//merge 18/01/20
void divide(tipovetor A, int tam, tipovetor aux1, tipovetor aux2, int *tam1, int *tam2)
{
    int meio, i;

    meio = tam/2;

    for(i = 0; i < meio; i++)
    {
        aux1[i] = A[i];
    }
    for(i = meio; i < tam; i++){
        aux2[i-meio] = A[i];
    }

    (*tam1) = meio;
    (*tam2) = (tam - meio);
}

void fundiVet(tipovetor aux1, tipovetor aux2, int tam1, int tam2, tipovetor A)
{
    int g, i, j, k;

    g = (abs(aux1[tam1-1])+abs(aux2[tam2-1])+1); //sentinela

    aux1[tam1] = g;
    aux2[tam2] = g;

    for (k = 0; k < (tam1+tam2); k++)
    {
       if (aux1[i] < aux2[j])
       {
           A[k] = aux1[i];
           i++;
       }
       else
       {
           A[k] = aux2[j];
           j++;
       }
    }
}

void mergeSort(tipovetor A, int tam)
{
    tipovetor aux1, aux2;
    int tam1, tam2;

    if(tam > 1)
    {
        divide(A, tam, aux1, aux2, &tam1, &tam2);
        mergeSort(aux1, tam1);
        mergeSort(aux2, tam2);
        fundiVet(aux1, aux2, tam1, tam2, A);
    }
}

//shell 18/01/20
void shellSort(tipovetor A, int tam)
{
    int prox, posinser, aux, desloc;

    desloc = tam/2;

    while (desloc > 0)
    {
        for(prox = desloc; prox < tam; prox += desloc){

            aux = A[prox];
            posinser = prox - desloc;

            while ((aux < A[posinser]) && (posinser > -1))
            {
                A[posinser + desloc] = A[posinser];
                posinser = posinser - desloc;
            }
            A[posinser + desloc] = aux;
        }
        desloc = desloc/2;
    }
}

//heap 18/01/20
void reorgHeap(tipovetor A, int raiz, int tam)
{
    int aux, posmaior;

    if(tam > ((2*raiz)-1))
    {
        posmaior = 2*raiz;

        if (tam > 2*raiz)
        {
            if (A[2*raiz] > A[(2*raiz)+1])
            {
                posmaior = (2*raiz);
            }
            else
            {
                posmaior = ((2*raiz)+1);
            }
        }

        if (A[posmaior] > A[raiz])
        {
            aux = A[raiz];
            A[raiz] = A[posmaior];
            A[posmaior] = aux;
            reorgHeap(A, posmaior, tam);
        }       
    }
}

void criaHeap(tipovetor A, int tam)
{
    int i;
    for(i = tam/2; i>0; i--)
    {
        reorgHeap(A, i, tam);
    }
}

void heapSort(tipovetor A, int tam)
{
    int i, n, aux;

    for (i = tam-1; i > -1; i--)
    {
        A[i+1] = A[i];
    }

    criaHeap(A, tam);
    n = tam;

    while (n > 1)
    {
        aux = A[1];
        A[1] = A[n];
        A[n] = aux;
        n--;
        reorgHeap(A, 1, n);
    }//ordenado de 1 a N, precisa voltar de 0 a tam-1
    
    for(i = 0; i<tam; i++)
    {
        A[i] = A[i+1];
    }
}

//quick 20/01/20
int particiona(tipovetor A, int ini, int fim)
{
    int divisor, i, menor, aux;
    divisor = A[fim];
    menor = ini;
    for(i = ini; i < fim; i++)
    {
        if(A[i] < divisor)
        {
            aux = A[menor];
            A[menor] = A[i];
            A[i] = aux;
            menor++;
        }
    }
    A[fim] = A[menor];
    A[menor] = divisor;
    return(menor);
}

void quickSort(tipovetor A, int ini, int fim)
{
    int divisor;
    if(fim > ini)
    {
        divisor = particiona(A, ini, fim);
        quickSort(A, ini, (divisor-1));
        quickSort(A, (divisor+1), fim);
    }
}

//--------------------------------------------------------------FIM----------------------------------