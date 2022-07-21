#include<stdio.h>

//operacoes basicas iniciais com arquivo

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