#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "modordenacoes.c"

void vetor(tipovetor A, tipovetor B, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("\nInsira o numero na posicao[%d]: ", i+1);
        scanf("%d", &A[i]);
        B[i] = A[i];
    }
    printf("\nVetor inserido: \n");
    for (i = 0; i < tam; i++)
    {
        printf("%d, ", A[i]);
    }
    
    
}

void imprime(tipovetor A, int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        printf("%d, ", A[i]);
    }
}

int main(){
    tipovetor A, B;
    int tam, op = 1, i, ini, fim;

    printf("\nQuantos elementos deseja inserir para ordenálos?\n");
    scanf("%d", &tam);

    vetor(A, B, tam);

    system("clear");

    while (op != 0)
    {
        printf("\n\t\t--Menu de Opcoes--\n");
        printf("\n\t\t[1]SelectionSort\n\t\t[2]BubbleSort\n\t\t[3]InsertionSort\n\t\t[4]MergeSort\n\t\t[5]ShellSort\n\t\t[6]HeapSort\n\t\t[7]QuickSort\n\t\t[0]Sair\n[Escolha]: ");
        scanf("%d", &op);
        system("clear");

        switch (op)
        {
            case 1:
                printf("\nOriginal: ");
                imprime(A, tam);
                printf("\n");
                selectionSort(A, tam);
                printf("\nOrdenado: ");
                imprime(A, tam);
                printf("\n");
            break;
            
            case 2:
                printf("\nOriginal: ");
                imprime(A, tam);
                printf("\n");
                bubbleSort(A, tam);
                printf("\nOrdenado: ");
                imprime(A, tam);
                printf("\n");
            break;

            case 3: 
                printf("\nOriginal: ");
                imprime(A, tam);
                printf("\n");
                insertionSort(A, tam);
                printf("\nOrdenado: ");
                imprime(A, tam);
                printf("\n");
            break;

            case 4: 
                printf("\nOriginal: ");
                imprime(A, tam);
                printf("\n");
                mergeSort(A, tam);
                printf("\nOrdenado: ");
                imprime(A, tam);
                printf("\n");
            break;

            case 5: 
                printf("\nOriginal: ");
                imprime(A, tam);
                printf("\n");
                shellSort(A, tam);
                printf("\nOrdenado: ");
                imprime(A, tam);
                printf("\n");
            break;

            case 6: 
                printf("\nOriginal: ");
                imprime(A, tam);
                printf("\n");
                heapSort(A, tam);
                printf("\nOrdenado: ");
                imprime(A, tam);
                printf("\n");
            break;

            case 7: 
                ini = 0;
                fim = tam-1;
                printf("\nOriginal: ");
                imprime(A, tam);
                printf("\n");
                quickSort(A, ini, fim);
                printf("\nOrdenado: ");
                imprime(A, tam);
                printf("\n");
            break;

            default:
            system("clear");
            printf("\n\t\t[Programa Finalizado]\n\n");
            break;
        }
    }
}