#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int num, resposta, op, resultado;
    int pe = 1, pa = 2, te = 3;

    char resp[10];
    char pedra[] = "pedra";
    char papel[] = "papel";
    char tesoura[] = "tesoura";
    char resp2[10];

    op = 1;

    while (op != 0)
    {
        printf("\nEscolhas:\nPedra\nPapel\nTesoura");
        printf("\nInsira sua escolha: ");
        setbuf(stdin, NULL);
        fgets(resp, 10, stdin);
        resp[strlen(resp)-1] = '\0';
        
        if(strcmp(resp, pedra) == 0)
        {
            resposta = 1;
        }
        else if (strcmp(resp, papel) == 0)
        {
            resposta = 2;
        }
        else if (strcmp(resp, tesoura) == 0)
        {
            resposta = 3;
        }
        else
        {
            printf("\nEscolha incorreta...\n");
            return 0;
        }

        srand( (unsigned)time(NULL) );
        num = rand() % 10;
        if (num < 2)
        {
            strcpy(resp2, pedra);
            num = 1;
        }
        else if ((num > 2) && (num < 6))
        {
            strcpy(resp2, papel);
            num = 2;
        }
        else
        {
            strcpy(resp2, tesoura);
            num = 3;
        }

        if(resposta == 1)
        {
            if(num == 1)
            {
                resultado = 0;  //empate
            }
            else if (num == 2)
            {
                resultado = 3;  //perdeu
            }
            else if (num == 3)
            {
                resultado = 1;  //ganhou
            }
        }
        else if (resposta == 2)
        {
            if(num == 1)
            {
                resultado = 1;
            }
            else if (num == 2)
            {
                resultado = 0;
            }
            else if (num == 3)
            {
                resultado = 3;
            }
        }
        else if (resposta == 3)
        {
            if(num == 1)
            {
                resultado = 3;
            }
            else if (num == 2)
            {
                resultado = 1;
            }
            else if (num == 3)
            {
                resultado = 0;
            }
        }

        if(resultado == 0)
        {
            printf("\nEMPATE, você escolheu %s e eu escolhi %s... =/", resp, resp2);
        }
        else if (resultado == 1)
        {
            printf("\nGANHOU, você escolheu %s e eu escolhi %s... =)", resp, resp2);
        }
        else if (resultado == 3)
        {
            printf("\nPERDEU, você escolheu %s e eu escolhi %s... =(", resp, resp2);
        }

        printf("\nDeseja jogar novamente? 1 (sim) 0 (não): ");
        scanf("%d", &op);
        system("clear");
    }
    
    return 0;
}