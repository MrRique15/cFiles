#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char nome[50];
    long int rg;
    int idade;
    int serie;
    int ra;
    char curso[20];
} aluno;

aluno p[40];
int quantidade=0;
void imp(int i){
    printf("\n");
    printf("NOME: %s\n", p[i].nome);
    printf("CPF: %li\n", p[i].rg);
    printf("IDADE: %d\n",p[i].idade);
    printf("SERIE: %d\n",p[i].serie);
    printf("RA: %d\n",p[i].ra);
    printf("CURSO: %s\n",p[i].curso);
    printf("\n");
}
void cadastro(int i){
    system("clear");
    setbuf(stdin,NULL);
    printf("Nome: ");
    fgets(p[i].nome, 50, stdin);
    p[i].nome[strlen(p[i].nome)-1] = '\0';
    printf("CPF(somente numeros): ");
    scanf("%li", &p[i].rg);
    printf("IDADE: ");
    scanf("%d", &p[i].idade);
    printf("SERIE: ");
    scanf("%d", &p[i].serie);
    printf("RA: ");
    scanf("%d", &p[i].ra);
    setbuf(stdin,NULL);
    printf("CURSO: ");
    fgets(p[i].curso,20,stdin);
    p[i].curso[strlen(p[i].curso)-1] = '\0';
    quantidade++;

}
void remocao(int x){
    int i, j, k;
    int aux, aux2;
    int tamanho1, tamanho2;
    aux2 = quantidade;
    aux = (quantidade-1);
    for(i=0;i<quantidade;i++){
        if(x==p[i].ra){
            quantidade--;
            for(j=i;j<aux;j++){
                strcpy(p[j].nome,p[j+1].nome);
                p[j].rg = p[j+1].rg;
                p[j].idade = p[j+1].idade;
                p[j].serie = p[j+1].serie;
                p[j].ra = p[j+1].ra;
                strcpy(p[j].curso,p[j+1].curso);
            }
        }
    }
    if(aux2=quantidade){
        printf("\nNenhum Cadastro existente com o RA inserido\n");
    }
}
void listagem(int a){
    int i;
    system("clear");
    for(i=0;i<a;i++){
        if(p[i].ra!=0){
            imp(i);
        }
    } printf("[%d cadastros existentes]\n", quantidade);
}
void consra(int ra){
    int i;
    system("clear");
    for(i=0;i<quantidade;i++){
        if(ra==p[i].ra){
            imp(i);
        }
    }
}
void consserie(int s){
    int i;
    system("clear");
    for(i=0;i<quantidade;i++){
        if(s==p[i].serie){
            imp(i);
        }
    }
}
void conscurso(char *c){
    int i, x;
    system("clear");
    for(i=0;i<quantidade;i++){
        x = strcmp(c,p[i].curso);
        if(x==0){
            imp(i);
        }
    }
}
void atidade(int ra){
    int i;
    system("clear");
    for(i=0;i<quantidade;i++){
        if(ra==p[i].ra){
            printf("Insira a Idade atualizada: ");
            scanf("%d", &p[i].idade);
            system("clear");
            printf("Atualizacao realizada.\n");
            imp(i);
        }
    }
}
void atserie(int ra){
    int i;
    system("clear");
    for(i=0;i<quantidade;i++){
        if(ra==p[i].ra){
            printf("Insira a Serie atualizada: ");
            scanf("%d", &p[i].serie);
            system("clear");
            printf("Atualizacao realizada.\n");
            imp(i);
        }
    }
}
void atcurso(int ra){
    int i;
    system("clear");
    for(i=0;i<quantidade;i++){
        if(ra==p[i].ra){
            printf("Insira o novo curso: ");
            setbuf(stdin,NULL);
            fgets(p[i].curso,20,stdin);
            p[i].curso[strlen(p[i].curso)-1] = '\0';
            system("clear");
            printf("Atualizacao realizada.\n");
            imp(i);
        }
    }
}
void salvar(FILE *fp){
    int i;
    for(i=0;i<quantidade;i++){
        fprintf(fp,"%s\n",p[i].nome);  //printar no arquivo o NOME
        fprintf(fp,"%li\n",p[i].rg);
        fprintf(fp,"%i\n",p[i].idade);
        fprintf(fp,"%i\n",p[i].serie);
        fprintf(fp,"%i\n",p[i].ra);
        fprintf(fp,"%s\n",p[i].curso);  //printar no arquivo o CURSO
    }
}
void leitura(FILE *fp){
    int i = quantidade;
    char lixo;
    while(!feof(fp)){
        fgets(p[i].nome,50,fp);
        p[i].nome[strlen(p[i].nome)-1] = '\0';
        fscanf(fp,"%li",&p[i].rg);
        fscanf(fp,"%i",&p[i].idade);
        fscanf(fp,"%i",&p[i].serie);
        fscanf(fp,"%i",&p[i].ra);
        fscanf(fp,"%c", &lixo);
        fgets(p[i].curso,20,fp);
        p[i].curso[strlen(p[i].curso)-1] = '\0';
        i++;
    }
    if(p[i].rg==0){
        i--;
    }
    quantidade = i;
}
int main(){
    int n, i=0, op=1, op2=1, opx=1;
    int ra, serie, idade;
    char c[20], cur[20], nome[50];  
    long int rg;

    FILE *fp;
    fp = fopen("trabalho.txt", "r+");
    if(fp == NULL){
        fp = fopen("trabalho.txt", "w+");
    }
    leitura(fp);

    while(op!=0){
        printf("\n\t\t[1]CADASTRAR\n\t\t[2]REMOVER CADASTRO\n\t\t[3]LISTAR CADASTROS\n\t\t[4]CONSULTAS\n\t\t[5]ATUALIZACOES\n\t\t[0]SAIR\n");
        scanf("%d", &op);

        switch(op){
            case 1: cadastro(quantidade);
            break;
            case 2: printf("Insira o RA: ");
                    scanf("%d", &ra);
                    remocao(ra);
            break;
            case 3: listagem(quantidade);
            break;
            case 4: op2=1;
                    system("clear");
                    while(op2!=0){
                        printf("\n\t\t--Consultas Disponiveis--\n");
                        printf("\t\t[1]ALUNO POR RA\n\t\t[2]ALUNOS DE CADA SERIE\n\t\t[3]ALUNOS DE CADA CURSO\n\t\t[0]SAIR\n");
                        scanf("%d", &op2);
                        switch(op2){
                            case 1: printf("Insira o RA: ");
                                    scanf("%d", &ra);
                                    consra(ra);
                                    break;
                            case 2: printf("Insira a serie: ");
                                    scanf("%d", &serie);
                                    consserie(serie);
                            break;
                            case 3: printf("Insira o Curso: ");
                                    setbuf(stdin,NULL);
                                    fgets(c,20,stdin);
                                    c[strlen(c)-1] = '\0';
                                    conscurso(c);
                            break;
                            default: system("clear");
                            break;
                        }
                    }
            break;
            case 5: opx=1;
                    system("clear");
                    while(opx!=0){
                        printf("\n\t\t--Atualizacoes Disponiveis--\n");
                        printf("\t\t[1]IDADE\n\t\t[2]SERIE\n\t\t[3]CURSO\n\t\t[0]SAIR\n");
                        scanf("%d", &opx);
                        switch(opx){
                            case 1: printf("Insira o RA do aluno a ser atualizado: ");
                                    scanf("%d", &ra);
                                    atidade(ra);
                            break;
                            case 2: printf("Insira o RA do aluno a ser atualizado: ");
                                    scanf("%d", &ra);
                                    atserie(ra);
                            break;
                            case 3: printf("Insira o RA do aluno a ser atualizado: ");
                                    scanf("%d", &ra);
                                    atcurso(ra);
                            break;
                            default: system("clear");
                            break;
                        }

                    }
            break;
            default:system("clear");
                    fp = fopen("trabalho.txt", "w+");
                    salvar(fp);
                    fclose(fp);
            break;
        }
    }
    printf("\n\t\t[Cadastramento Finalizado]\n\n");
    return 0;
}
