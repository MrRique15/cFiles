// Autor: Henrique Ribeiro Favaro
// RA: 115.408

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "modlistaest.c"


//---------------------------------------------------------------------------------------------------------------------------


/*A função INSERE trata a inserção de registros na Lista, ela coleta da entrada do usuário os dados a serem cadastrados e
os aplica na Lista em cada campo respectivo. A função recebe, (estrutura da lista por parâmetro se for estatica) e 
(endereço do vetor Lista caso seja Dinamica) (*l). Antes de inserir a função confere se a lista não está cheia (para nao gerar
problemas na estática), e tambem se o registro nao existe para que nao seja cadastrado duplicado. Caso nao exista e a lista nao
esteje cheia, sera inserido normalmente */
void insere(tipolista *l)
{
    int res; 
    tiporeg reg;
    system("clear");
    printf("\t\tModulo de Inserção\n");
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


/*A funcao REMOVER trata a remoção, recebendo a lista: referencia de uma estrutura para Lista estatica e endereço do vetor Lista para
Dinamica (*l). A função faz uma verificação se a lista não esta vazia, e após isso, se existirem registros na lista, a aplicação fará
uma busca pela lista para encontrar o registro à ser removido. Quando encontrado e removido, o registro é printado na tela por completo*/
void remover(tipolista *l)
{
    int res;
    tiporeg reg;
    system("clear");
    printf("\t\tModulo de remoção\n");
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


/*A função CONSULTAR recebe a estrutura da lista caso seja Lista Estatica e recebe o Ponteiro Lista caso seja dinamica, 
em seu cabeçalho (l). Primeiramente é realizada uma checagem para conferir se existem elementos cadastrados na lista.Após isso, 
o usuário informa um nome à aplicação que fará a busca do registro com mesmo nome dentro da estrutura. Quando for encontrado será
impresso na tela todos os dados do registro */
void consultar(tipolista l)
{
    int res;
    tiporeg reg;
    int posant;
    system("clear");
    printf("\t\tModulo de Consulta\n");
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


/*A função ATUALIZAR realiza a atualização da Idade e do Telefone de algum cadastro inserido. Ela recebe a Lista por parâmetro em 
seu cabeçalho (*l). Após realizar a checagem se a lista não está vazia, a função coletará uma entrada de Nome do usuário e fará
a busca dentro da Lista por esse nome, se encontrado solicitará os dados atualizados e realizará a atualização do Registro */
void atualizar(tipolista *l)
{
    tiporeg reg;
    int res, res2;
    if(!listavazia(*l))
    {
        system("clear");
        printf("\t\tModulo de atualização\n");

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

            printf("\nInsira o Telefone atualizado: ");
            setbuf(stdin,NULL);
            fgets(reg.tel, 15, stdin);
            reg.tel[strlen(reg.tel)-1] = '\0';

            res2 = atualizalista(l,reg);

            if(res2==regnaoexiste)
            {
                system("clear");
                printf("\nRegistro não existe\n");
            }

            else
            {
                system("clear");
                printf("\nRegistro atualizado\n");
                printf("\nNome: %s", reg.nome);
                printf("\nIdade: %d", reg.idade);
                printf("\nGenero: %c", reg.genero);
                printf("\nCPF: %s", reg.cpf);
                printf("\nTelefone: %s", reg.tel);
            }
        }
    }

    else
    {
        system("clear");
        printf("\nA lista está vazia\n");
    }
}


/*A função LISTAR recebe a estrutura da Lista (l) em seu cabeçalho. Primeiramente realiza a checagem para conferir se existem elementos
cadastrados na lista. Após isso, se existirem elementos ela buscará o numero total desses elementos. Realizados esses procedimentos,
tendo conhecimento do total de elementos à serem impressos, a função imprime na ordem da Lista todos os elementos cadastrados para
mostrar à seu usuário. Na impressao ela faz uma busca registro por registro utilizando sua posição, pela função CONSULTAREGNAPOSICAO
a qual busca na posição informada e retorna o registro por completo */
void listar(tipolista l)
{
    int i=1, pos=1;
    tiporeg reg;
    int total;  

    total = totallista(l);

    system("clear");
    printf("\t\tLista Completa\n");
    if(!listavazia(l))
    {
        while(i<=total)
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


/*Dentro da Função MAIN temos apenas um menu guiado pela escolha de opções informada pelo usuário com numeros para
cada operação desejada. A estrutura LISTA fica criada e salva dentro da MAIN, sendo encaminhada devidamente para as funções
sempre que for utilizada*/
void main()
{
    int i, op=1;

    char resp;

    tipolista l;

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
                printf("\n\t\t[Programa Finalizado]\n\n");
            break;
        }
    }
}