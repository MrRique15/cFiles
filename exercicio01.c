//--------------------------//
// Henrique Ribeiro Favaro  //
//       RA: 115.408        //
//--------------------------//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leitura(FILE *entr, int tam, int cont)
{
    int i = 0;
    char str[30];
    char letra = '\0';
    letra = fgetc(entr);
    while( (letra != EOF) && (letra != '|') )
    {
        if (tam > 0)
        {   
            str[strlen(str)] = letra;
            i++;
            tam--;
        }
        letra = fgetc(entr);
    }
    str[strlen(str)] = '\0';
    printf("\nCampo #%d: %s", cont, str);
    return i;
}

int main()
{
    char campo[30];
    int comp_campo = 0;
    char nome_arq[30];
    int contador = 1;

    FILE *entrada;
    entrada = fopen("registros.txt","r");

    if (entrada == NULL)
    {
        printf("\nO arquivo não existe!\n");
        return 0;
    }

    comp_campo = leitura(entrada, 30, 1);

    while (comp_campo > 0)
    {
       //printf("\nCampo #%d: %s", contador, campo);
       contador++;
       printf("\n%d", contador);
       comp_campo = leitura(entrada, 30, contador);
    }

    fclose(entrada);
    return 0;
}