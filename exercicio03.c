//--------------------------//
// Henrique Ribeiro Favaro  //
//       RA: 115.408        //
//--------------------------//
//ESCRITA DE DADOS EM ARQUIVO SEPARADOS POR "|" COM NUMERO DE BYTES NA FRENTE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    char resp[40];
    char sobrenome[20];
    char buffer[200];
    int tamreg = 0;

    FILE *saida;
    saida = fopen("registros2.txt","a");

    if (saida == NULL)
    {
        saida = fopen("registros2.txt","w");
        if (saida == NULL)
        {
            printf("\nErro na criação do arquivo!\n");
            return 0;
        }
    }

    setbuf(stdin,NULL);
    printf("\nInsira o Sobrenome: ");
    fgets(sobrenome,20,stdin);
    sobrenome[strlen(sobrenome) - 1] = '\0';

    while (strlen(sobrenome) > 0)
    {
        tamreg = 0;
        buffer[0] = '\0';

        strcat(buffer, sobrenome);
        strcat(buffer, "|");

        for(i=0; i<5; i++)
        {
            if (i==0)
            {
                printf("\nInsira o Nome: ");
            }
            else if (i==1)
            {
                printf("\nInsira o Endereço: ");
            }
            else if (i==2)
            {
                printf("\nInsira a Cidade: ");
            }
            else if (i==3)
            {
                printf("\nInsira o Estado: ");
            }
            else if (i==4)
            {
                printf("\nInsira o CEP: ");
            }
            resp[0] = '\0';
            setbuf(stdin, NULL);
            fgets(resp,40,stdin);
            resp[strlen(resp) - 1] = '\0';
            strcat(buffer, resp);
            strcat(buffer, "|");
            
        }

        tamreg = strlen(buffer);

        fprintf(saida,"%d",tamreg);
        //fwrite(&(tamreg), sizeof(int), 1, saida);   //fwrite não está escrevendo os inteiros, buga o txt//
        fwrite(buffer, 1, tamreg, saida);

        system("clear");

        setbuf(stdin,NULL);
        printf("\nInsira o Sobrenome: ");
        fgets(sobrenome,20,stdin);
        sobrenome[strlen(sobrenome) - 1] = '\0';
    }

    fclose(saida);
    return 0;
}