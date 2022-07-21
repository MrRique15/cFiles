#include<stdio.h>
#include<stdlib.h>

double fibbonacci(int n){
    if(n==1||n==2){
        return 1;
    }
    else{
        return fibbonacci(n-1)+fibbonacci(n-2);
    }
}
int main(){
    int n, cont;
    double result;
    do{
        printf("Insira o n-esimo elemento a a ser calculado da sequencia de Fibbonnaci: ");
        scanf("%d", &n);
        result = fibbonacci(n);
        printf("\nO %d numero da sequencia de Fibbonacci é: %.0lf\n", n, result);
        printf("Deseja continuar? <1>Sim <0>Nao\n");
        scanf("%d", &cont);
    }while(cont);
    return 0;
}