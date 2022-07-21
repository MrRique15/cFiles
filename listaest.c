#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "modlistaest.c"


void insere(tipolista *l)
{
    int res; 
    tiporeg reg;
    system("clear");
    if(!listacheia(*l))
    {
        printf("\nInsira o nome: ");
        setbuf(stdin,NULL);
        fgets(reg.nome, 50, stdin);
        reg.nome[strlen(reg.nome)-1] = '\0';

        printf("\nInsira a idade: ");
        scanf("%d", &reg.idade);
        setbuf(stdin,NULL);

        printf("\nInsira o genero (m/f): ");
        scanf("%c", &reg.genero);

        printf("\nInsira o CPF (somente numeros): ");
        scanf("%s", reg.cpf);

        printf("\nInsira o telefone (99999-9999): ");
        setbuf(stdin,NULL);
        fgets(reg.tel,15,stdin);
        reg.tel[strlen(reg.tel)-1] = '\0';

        res = inserelista(l,reg);

        if(res==regjaexiste)
        {
            system("clear");
            printf("\nRegistro ja existe\n");
        }

        else
        {
            system("clear");
            printf("\nRegistro foi inserido\n");
        }
    }

    else
    {
        system("clear");
        printf("\nA lista está cheia\n");
    }
}

void remover(tipolista *l)
{
    int res;
    tiporeg reg;
    system("clear");
    if(!listavazia(*l))
    {
        printf("\nInsira o nome a ser removido: ");
        setbuf(stdin,NULL);
        fgets(reg.nome, 50, stdin);
        reg.nome[strlen(reg.nome)-1] = '\0';

        res = removelista(l,&reg);

        if(res==regnaoexiste)
        {
            system("clear");
            printf("\nRegistro não existe\n");
        }

        else
        {
            system("clear");
            printf("\nO Registro foi removido");
            printf("\nNome: %s",reg.nome);
            printf("\nIdade: %d",reg.idade);
            printf("\nGenero: %c", reg.genero);
            printf("\nCPF: %s", reg.cpf);
            printf("\nTelefone: %s", reg.tel);
        }
    }

    else{
        system("clear");
        printf("\nA lista está vazia\n");
    }
}

void consultar(tipolista l)
{
    int res;
    tiporeg reg;
    int posant;
    system("clear");
    if(!listavazia(l))
    {
        printf("\nInsira o nome a ser consultado: ");
        setbuf(stdin,NULL);
        fgets(reg.nome, 50, stdin);
        reg.nome[strlen(reg.nome)-1] = '\0';

        res = consultalista(l,&reg);

        if(res==regjaexiste)
        {
            system("clear");
            printf("\nNome: %s", reg.nome);
            printf("\nIdade: %d", reg.idade);
            printf("\nGenero: %c", reg.genero);
            printf("\nCPF: %s", reg.cpf);
            printf("\nTelefone: %s", reg.tel);
        }
        else
        {
            system("clear");
            printf("\nRegistro não existe\n");
        }
    }
    else
    {
        system("clear");
        printf("\nA lista está vazia\n");
    }
}

void atualizar(tipolista *l)
{
    tiporeg reg;
    int res, res2;
    if(!listavazia(*l))
    {
        system("clear");
        printf("\nInsira o nome a ser atualizado: ");
        setbuf(stdin,NULL);
        fgets(reg.nome, 50, stdin);
        reg.nome[strlen(reg.nome)-1] = '\0';

        res = consultalista(*l,&reg);

        if(res==regnaoexiste)
        {
            system("clear");
            printf("\nRegistro nao existe\n");
        }
        else
        {
            printf("\nInsira a idade atualizada: ");
            scanf("%d", &reg.idade);

            printf("\nInsira o telefone atualizado: ");
            setbuf(stdin,NULL);
            fgets(reg.tel,15,stdin);
            reg.tel[strlen(reg.tel)-1] = '\0';

            res2 = atualizalista(l,reg);

            if(res2==regjaexiste)
            {
                system("clear");
                printf("\nRegistro atualizado\n");
                printf("\nNome: %s", reg.nome);
                printf("\nIdade: %d", reg.idade);
                printf("\nGenero: %c", reg.genero);
                printf("\nCPF: %s", reg.cpf);
                printf("\nTelefone: %s", reg.tel);
            }

            else
            {
                system("clear");
                printf("\nRegistro não existe\n");
            }
        }
    }

    else
    {
        system("clear");
        printf("\nA lista está vazia\n");
    }
}

void listar(tipolista l)
{
    int i=1, pos=1;
    tiporeg reg;
    l.total;
    system("clear");
    if(!listavazia(l))
    {
        while(i<=l.total)
        {
            reg = consultaregnaposicao(l,pos);
            printf("\n[%d]", i);
            printf("\nNome: %s", reg.nome);
            printf("\nIdade: %d", reg.idade);
            printf("\nGenero: %c", reg.genero);
            printf("\nCPF: %s", reg.cpf);
            printf("\nTelefone: %s", reg.tel);
            printf("\n");
            i++;
            pos++;
        }
    }

    else
    {
        system("clear");
        printf("\nA lista está vazia\n");
    }
}

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    int i, op=1;

    char resp;

    tipolista l;

    tiporeg reg;

    crialista(&l);

    while(op != 0)
    {
        printf("\n\t\t--Menu de Opcoes--\n");
        printf("\n\t\t[1]Inserir\n\t\t[2]Remover\n\t\t[3]Consultar\n\t\t[4]Atualizar\n\t\t[5]Listar\n\t\t[0]Sair\n:");
        scanf("%d", &op);

        switch (op)
        {
            case 1: insere(&l);
            break;

            case 2: remover(&l);
            break;

            case 3: consultar(l);
            break;

            case 4: atualizar(&l);
            break;

            case 5: listar(l);
            break;

            default:
                system("clear");
                printf("\n\t\t[Programa Finalizado]\n");
            break;
        }
    }

    return 0;
}