//--------------------------//
// Henrique Ribeiro Favaro  //
//       RA: 115.408        //
//--------------------------//
//ESCRITA DE DADOS EM ARQUIVO SEPARADOS POR "|" COM NUMERO DE BYTES NA FRENTE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leia_reg(FILE *fp, char *string, int tam)
{
    int tamreg;
    int dez, dec;
    int aux;
    //int tamreg3, tamreg2;
    //int aux2;
    //int aux3;
    printf("\nInicio da FREAD...");

    aux = fread(&tamreg, sizeof(int), 1, fp);
    //aux2 = fread(&tamreg2, sizeof(int), 1, fp);
    //aux3 = fread(&tamreg3, sizeof(int), 1, fp);
    if( aux != 1)
    {
        printf("\nErro na leitura do arquivo...\n");
        exit(1);
    }
    //tamreg = 49;
    printf("\nFREAD executada... tamreg = %d, aux: %d", tamreg, aux);
    //printf("\nFREAD executada... tamreg = %d, aux: %d", tamreg2, aux2);
    //printf("\nFREAD executada... tamreg = %d, aux: %d", tamreg3, aux3);

    if (feof(fp)) 
    {
        return 0;
    }
    if (tamreg < tam)
    {
        fread(string, tamreg, 1, fp);
        strcat(string, "\0");
        return tamreg;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int i = 1;
    char buffer[200];
    int tamreg = 0;
    int cont;
    char *campo;

    printf("\nPrograma Iniciado...");

    FILE *entrada;
    entrada = fopen("registros2.txt","r");

    if (entrada == NULL)
    {
        printf("\nErro na abertura do arquivo!\n");
        return 0;
    }

    printf("\nArquivo aberto...");

    tamreg = leia_reg(entrada, buffer, 200);

    while (tamreg > 0)
    {
        campo = strtok(buffer, "|");
        cont = 0;

        printf("´\n[Registro #%d]:", i);
        i++;

        while (campo != NULL)
        {   
            if (cont==0)
            {
                printf("\n\t\tSobrenome: %s", campo);
            }
            else if (cont==1)
            {
                printf("\n\t\tNome: %s", campo);
            }
            else if (cont==2)
            {
                printf("\n\t\tEndereço: %s", campo);
            }
            else if (cont==3)
            {
                printf("\n\t\tCidade: %s", campo);
            }
            else if (cont==4)
            {
                printf("\n\t\tEstado: %s", campo);
            }
            else if (cont==5)
            {
                printf("\n\t\tCEP: %s", campo);
            }
            cont++;
            campo = strtok(NULL, "|");
        }

        tamreg = leia_reg(entrada, buffer, 200);
    }

    printf("\nFechando o programa...\n");

    fclose(entrada);
    return 0;
}