//--------------------------//
// Henrique Ribeiro Favaro  //
//       RA: 115.408        //
//--------------------------//
//LEITURA DOS REGISTROS DE ARQUIVO SEPARADOS POR "|"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM_STR '|'
#define TAM_STR 50

int leitura(FILE *entr, char *campo, int tamanho)
{
    int i = 0;
    char ch = fgetc(entr);
    while(ch != EOF && ch != DELIM_STR && ch != '\n')
    {
        if (tamanho > 1)
        {   
            campo[i] = ch;
            i++;
            tamanho--;
        }
        ch = fgetc(entr);
    }
    campo[i] = '\0';
    return i;
}

int main()
{
    char campo[TAM_STR];
    int tam;
    int contador;
    int regcont = 1, regcont2 = 1;

    FILE *entrada;
    entrada = fopen("registros.txt","r");

    if (entrada == NULL)
    {
        printf("\nO arquivo não existe!\n");
        return 0;
    }
    contador = 0;
    tam = leitura(entrada, campo, TAM_STR);

    while (tam > 0)
    {
        if (regcont == 7 || regcont == 1)
        {
            printf("\nRegistro #%d: ", regcont2);
            regcont2++;
            regcont = 1;
        }
        printf("\n\t\tCampo #%d: %s", ++contador, campo);
        tam = leitura(entrada, campo, TAM_STR);
        regcont++;
    }
    printf("\n\nFInal da leitura dos Dados...\n");
    fclose(entrada);
    return 0;
}