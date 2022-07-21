#include<stdio.h>
//pega 2 elementos iguais em um vetor e printa;
int main(){
    int A[12], B[15], i, j;
    for(i=0;i<12;i++){
        scanf("%i", &A[i]);
    } printf("\n");
    for(i=0;i<15;i++){
        scanf("%i", &B[i]);
    }
    for(i=0;i<12;i++){
        for(j=0;j<15;j++){
            if(A[i]==B[j]){
                printf("%i ", A[i]);
            }
        }
    }

    return 0;
}


//--------------------------------------------------------------------------------------------------------------------------


#include<stdio.h>
//soma de todos os elementos de uma matriz;
int main(){
    int M[6][5], soma=0, i, j;

    for(i=0;i<6;i++){
        for(j=0;j<5;j++){
            scanf("%i", &M[i][j]);
            soma += M[i][j];
        }
    }
    printf("%i", soma);
    
}


//--------------------------------------------------------------------------------------------------------------------------

//Coleta de elementos de uma matriz
#include<stdio.h>
int main(){
    int M[5][5], i, j, maior;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            scanf("%i", &M[i][j]);
        }
    } printf("\n");

    maior = M[0][0];
    //Achando o maior elemento da matriz
    for(i=0;i<5;i++){
        if(M[i][i]>maior){
            maior = M[i][i];
        }
    }
    printf("%i", maior);
    printf("\n");
    //dividir todos os elementos pelo maior da matriz
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            M[i][j] = (M[i][j] / maior);
            printf("%i ", M[i][j]);
        } printf("\n");
    }
    
}


//--------------------------------------------------------------------------------------------------------------------------


#include<stdio.h>
//funcao rescursiva para fatorial;
long int fat(long int n){
    if(n==0){
        return 1;
    }
    else {
        return n*fat(n-1);
    }
}
int main(){
    long int n, result;
    printf("Insira o numero pra ser calculado seu fatorial: ");
    scanf("%li", &n);
    result = fat(n);
    printf("%li! = %li\n", n, result);
}


//--------------------------------------------------------------------------------------------------------------------------


#include<stdio.h>
//funcao rescursiva para maior numero de um vetor;
int maior(int n, int v[]){
   int x;
   if (n == 1){
    x = v[0];
   }
   else {
    x = maior (n-1, v); 
        if(x < v[n-1]){
            x = v[n-1];
        }
   }
   return x;
}
void preenche(int v[], int n){
    int i;
    for(i=0;i<n;i++){
        scanf("%d", &v[i]);
    }
}
int main(){
    int n, maiorr;
    printf("Insira o tamanho do vetor: ");
    scanf("%i", &n);
    int v[n];
    preenche(v,n);
    maiorr = maior(n,v);
    printf("%i é o maior numero do vetor\n", maiorr);
}


//--------------------------------------------------------------------------------------------------------------------------


#include<stdio.h>
//Funcao pra calcular multiplicacao pela soma N vezes
int mult(int a, int b){
    int x;
    if(b==1){
        return a;
    }
    else{
        x = a+mult(a,b-1);
    }
    return x;
}
int main(){
    int a, b, result;
    printf("Insira os numeros a serem multiplicados: ");
    scanf("%i%i", &a, &b);
    result = mult(a,b);
    printf("%i\n", result);
    return 0;
}

//--------------------------------------------------------------------------------------------------------------------------


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Inversao de uma string (erro de duplicidade no print)
void inv(char *string){
   if(*string){
	  inv(string+1);
	  putchar(*string);
   }
   printf("%s\n", string);
}
int main(){
    char nome[30], x;
    fgets(nome,30,stdin);
    inv(nome);
    return 0;
}


//--------------------------------------------------------------------------------------------------------------------------


#include<stdio.h>
//Multiplicacao de N numeros de um vetor
void preenche(int v[], int n){
    int i;
    for(i=0;i<n;i++){
        scanf("%i", &v[i]);
    }
}
int mult(int n, int v[]){
    if(n==1){
        return v[0];
    }
    else return v[n-1]*mult(n-2,v);
}
int main(){
    int n, x, y;
    scanf("%i", &n);
    int v[n];
    preenche(v,n);
    x = mult(n,v);
    printf("%i", x);
    return 0;
}


//--------------------------------------------------------------------------------------------------------------------------


#include<stdio.h>
//criação, impressão dentro e fora do arquivo
int main(){
    FILE *fp; //declara um FilePoint, vetor que direciona ao arquivo
    int a,b;
    char str[10];
    fp = fopen("arquivo.txt", "w+"); //cria o arquivo e abre ele pra escrever dentro no mesmo diretorio que esse codigo esta salvo
    //se o arquvio for criado em "w+b", o arquivo sera criado em BINARIO porem funciona somente em Windows
    if (fp==NULL){
        printf("Erro na criação do arquivo\n"); //mostra erro se o arquivo n for criado
    }

    a=10;

    fprintf(fp,"%s\n", "teste"); //imprime dentro do arquivo fp, com uma quebra de linha
    fprintf(fp,"%i", a);

    rewind(fp); //volta ao inicio do arquivo, quando for fazer leitura ou algo do tipo
    fgets(str,10,fp); //coleta do arquivo fp, e grava na variavel str
    fscanf(fp,"%i",&b); //coleta do arquivo fp o valor %i e salva em &b
    printf("%s", str);
    printf("%i\n", b);
    fclose(fp); //fecha a edicao do arquivo, sempre colocar no final
    return 0;
}


//--------------------------------------------------------------------------------------------------------------------------


//compara se o vetor é palindromo
for(i=0;i<aux2;i++){
    if(A[i]!=A[(n-1)-i]){
        aux++;
    }
}
if (aux==0){
    printf("\nO vetor é palindromo!\n");
}
else printf("\nO vetor não é palindromo\n");


//--------------------------------------------------------------------------------------------------------------------------


#include<stdio.h>
#include<stdlib.h>

void fatorial(double *fat, int n){
    if(n==0){
        *fat = 1;
    }
    else{
        fatorial(fat,n-1);
        *fat = n*(*fat);
    }
}

int main(){
    int n, cont;
    double fat=0;
    //programa para calculo de fatorial por referencia e parametro
    do{
        printf("\nInsira um numero para calcular seu fatorial: ");
        scanf("%d", &n);
        fatorial(&fat,n);
        printf("\nFatorial de %d é: %.0f\n", n, fat);
        printf("Deseja continuar? <1>Sim <0>Nao\n");
        scanf("%d", &cont);
    }while(cont);
    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------

//Programa para calcular soma de elementos de um vetor por parametros e recursao
#include<stdio.h>
#include<stdlib.h>

int somavet(int v[], int n){
    if(n==0){
        return v[0];
    }
    else{
        return(v[n]+somavet(v,n-1));
    }
}

int main(){
    int cont;
    int tamanho;
    int i, soma;
    do{
        printf("\nInsira o tamanho do vetor: ");
        scanf("%d", &tamanho);
        int v[tamanho];
        for(i=0;i<tamanho;i++){
            printf("[%d]: ", i);
            scanf("%d", &v[i]);
        }
        tamanho = tamanho-1;
        soma = somavet(v,tamanho);
        printf("Soma dos elementos = %d\n", soma);
        printf("Deseja continuar? <1>Sim <0>Nao\n");
        scanf("%d", &cont);
    } while(cont);
}