#include<stdio.h>
#include<stdlib.h>
void insert(int v[], int n){
    int i;
    for(i=0;i<n;i++){
        scanf("%i", &v[i]);
    }

}
void print(int v[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%i ", v[i]);
    } printf("\n");
}
void intercala(int v1[], int v2[], int n){
    int x, i, aux=0;
    x=2*n;
    int vetor[x];
    for(i=0;i<x;i+=2){
        vetor[i]=v1[aux];
        vetor[i+1]=v2[aux];
        aux++;
    }
    printf("Intercalado: ");
    for(i=0;i<x;i++){
        printf("%i ", vetor[i]);
    }printf("\n");
}
int main(){
    int x, i;
    printf("Insira o tamanho de seu vetor: ");
    scanf("%i", &x);
    int v1[x], v2[x];
    insert(v1,x);
    insert(v2,x);
    print(v1,x);
    print(v2,x);
    intercala(v1,v2,x);
    
    return 0;
}