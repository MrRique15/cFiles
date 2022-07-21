#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int ra;
    char nome[30];
} aluno;

void cadastro(aluno *a){
    //cadastro com passagem de struct por referencia
    printf("Insira o RA: ");
    scanf("%i", &a->ra);
    setbuf(stdin,NULL);
    printf("Insira o NOME: ");
    fgets(a->nome,30,stdin);
}

void print(aluno *a){
    printf("RA: %i\n", a->ra); //indica para printar o ra dentro da struct a
    printf("NOME: %s\n", a->nome);
}

int main(){
    aluno a[5];
    int i;
    for(i=0;i<5;i++){
        //passagem de struct por referencia com posicao
        cadastro(&a[i]);
    }
    system("clear");
    
    for(i=0;i<5;i++){
        print(&a[i]);
    }
    return 0;
}