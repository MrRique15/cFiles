/*Autor: Henrique Ribeiro Favaro
RA: 115.408*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "moduloarvore1.c"
#include "moduloarvore2.c"

/* Funcao que solicita ao usuario os dados que serao inseridos na arvore, e faz a chamada da funcao de insercao 
da arvore que o usuario escolheu */
void insere(tipoarvore *arv, int op)
{
    int res; 
    tiporeg reg;
    int cresceu = 0;

    system("clear");
    printf("\t\tModulo de Inserção\n");

    printf("\nInsira o nome: ");
    getchar();
    fgets(reg.nome, 50, stdin);
    reg.nome[strlen(reg.nome)-1] = '\0';

    printf("\nInsira a idade: ");
    scanf("%d", &reg.idade);
    getchar();

    printf("\nInsira o genero (m/f): ");
    scanf("%c", &reg.genero);

    printf("\nInsira o CPF (somente numeros): ");
    scanf("%ld", &reg.cpf);

    printf("\nInsira o telefone (99999-9999): ");
    getchar();
    fgets(reg.tel,15,stdin);
    reg.tel[strlen(reg.tel)-1] = '\0';

    if(op == 1){
        res = inserearvore(arv,reg,&cresceu);
    }
    else if (op == 2)
    {
        res = inserearvore2(arv,reg,&cresceu);
    }

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

/* Funcao que solicita ao usuario um nome, e apos isso passa esse nome para a funcao de remocao dentro da arvore em
questao para que seja realizada a remocao e apos isso a impressao dos dados removidos */
void remover(tipoarvore *arv, int op, int op2)
{
    int res;
    tiporeg reg;
    int diminuiu = 0;

    system("clear");
    printf("\t\tModulo de Remoção\n");

    if(!arvorevazia(*arv))
    {
        printf("\nInsira o nome a ser removido: ");
        setbuf(stdin,NULL);
        fgets(reg.nome, 50, stdin);
        reg.nome[strlen(reg.nome)-1] = '\0';

        if(op == 1){ //selecao da arvore operada
            if(op2 == 1){ //selecao do menor dos maiores ou maior dos menores
                res = removearvore(arv,&reg,&diminuiu); //maior menores
            }
            else{
                res = removearvore_2(arv,&reg,&diminuiu); //menor maiores
            }
        }
        else if (op == 2)
        {
            if(op2 == 1){
                res = removearvore2(arv,&reg,&diminuiu); //maior menores
            }
            else
            {
                res = removearvore2_2(arv,&reg,&diminuiu); //menor maiores
            }
        }

        if(res==regnaoremovido)
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
            printf("\nCPF: %ld", reg.cpf);
            printf("\nTelefone: %s", reg.tel);
        }
    }

    else
    {
        system("clear");
        printf("\nA Árvore está vazia\n");
    }
}

/* Funcao de listagem dos elementos em ordem, ou pre ordem, ou pos ordem, dependendo de como o usuario deseja */
void listar(tipoarvore arv, int op)
{
    int aux;
    system("clear");
    printf("\nEscolha o método de impressão:\n[1]Em ordem\n[2]Pre ordem\n[3]Pos ordem\n");
    scanf("%d", &aux);
    if(aux == 1)
    {

        if (op == 1)
        {
            system("clear");
            inorder(arv);
        }
        else if (op == 2)
        {
            system("clear");
            inorder2(arv);
        }
        
    }
    else if(aux == 2)
    {

        if (op == 1)
        {
            system("clear");
            preorder(arv);   
        }
        else if (op == 2)
        {
            system("clear");
            preorder2(arv);
        }

    }
    else if(aux == 3)
    {
        if (op == 1)
        {
            system("clear");
            posorder(arv);
        }
        else if (op == 2)
        {
            system("clear");
            posorder2(arv);
        }
        
    }
    else
    {
        system("clear");
        printf("\nMétodo inválido\n");
    }
}

/* Funcao que solicita um nome ao usuario, passa esse nome para a arvore e apos realizada uma busca, imprime os dados
do registro referente à tal nome em questao */
void consulta(tipoarvore arv, int op)
{
    tiporeg reg;
    int res;

    system("clear");
    printf("\t\tModulo de Consulta\n");
    if(!arvorevazia(arv))
    {
        printf("\nInsira o nome: ");
        setbuf(stdin,NULL);
        fgets(reg.nome, 50, stdin);
        reg.nome[strlen(reg.nome)-1] = '\0';

        if (op == 1)
        {
            res = busca(arv,&reg);
        }
        else if (op == 2)
        {
            res = busca2(arv,&reg);
        }
        
        if(res == regnaoencontrado)
        {
            system("clear");
            printf("\nRegistro nao existe");
        }
        else
        {
            system("clear");
            printf("\nRegistro Localizado");
            printf("\nNome: %s",reg.nome);
            printf("\nIdade: %d",reg.idade);
            printf("\nGenero: %c", reg.genero);
            printf("\nCPF: %ld", reg.cpf);
            printf("\nTelefone: %s", reg.tel);
        }

    }

    else
    {
        system("clear");
        printf("\nA Árvore está vazia.");
    }

}

/* Funcao que atualiza os dados inseridos de um registro com base no nome inserido, o qual sera passado 
juntamente com os dados atualizados para a arvore e apos isso retorna o sucesso da operacao, atualizado ou nao */
void atualiza(tipoarvore *arv, int op)
{
    tiporeg reg;
    int res;

    system("clear");
    printf("\t\tModulo de Atualização\n");

    if (!arvorevazia(*arv))
    {
        printf("\nInsira o nome: ");
        setbuf(stdin,NULL);
        fgets(reg.nome, 50, stdin);
        reg.nome[strlen(reg.nome)-1] = '\0';

        printf("\nInsira a idade atualizada: ");
        scanf("%d", &reg.idade);
        setbuf(stdin,NULL);

        printf("\nInsira o telefone (99999-9999): ");
        setbuf(stdin,NULL);
        fgets(reg.tel,15,stdin);
        reg.tel[strlen(reg.tel)-1] = '\0';

        if (op == 1)
        {
            res = atualizacao(arv,reg);
        }
        else if (op == 2)
        {
            res = atualizacao2(arv,reg);
        }

        if(res == regnaoatualizado)
        {
            system("clear");
            printf("\nRegistro não encontrado");
        }
        else
        {
            system("clear");
            printf("\nRegistro atualizado");
        }
    }
    else
    {
        system("clear");
        printf("\nA Árvore está vazia.");
    }
    
}

/* Funcao main com a escolha da arvore que sera utilizada e com a escolha do metodo de remocao que sera utilizado,
apos selecionar a arvore que queira utilizar, já se é realizada a criacao da arvore com sua raiz em NULO */
int main(){

    tipoarvore arv;

    int op = 1, esc, esc2;

    printf("\n\t\tSelecione a árvore que deseja utilizar:\n\t\t[1]Iterativa\n\t\t[2]Recursiva\n[Escolha]:");
    scanf("%d", &esc);

    if ((esc!=1)&&(esc!=2))
    {
        system("clear");
        printf("\n\t\t[A árvore selecionada não existe]\n");
        return 0;
    }
    else{
        system("clear");
        printf("\n\t\tEscolha o método utilizado:\n\t\t[1]Menor dos maiores\n\t\t[2]Maior dos menores\n[Escolha]:");
        scanf("%d", &esc2);
        if ((esc2 != 1) && (esc2 != 2))
        {  
            system("clear");
            printf("\n\t\t[O método selecionado não existe]\n");
            return 0;
        }
    }

    if (esc == 1)
    {
        criaarvore(&arv);
    }
    else if (esc == 2)
    {
        criaarvore2(&arv);
    }
    else
    {
        system("clear");
        printf("\n\t\t[Árvore utilizada inválida]\n");
        return 0;
    }

    system("clear");

    while (op != 0)
    {
        printf("\n\t\t--Menu de Opcoes--\n");
        printf("\n\t\t[1]Inserir\n\t\t[2]Remover\n\t\t[3]Listar\n\t\t[4]Consulta\n\t\t[5]Atualiza\n\t\t[0]Sair\n[Escolha]: ");
        scanf("%d", &op);

        switch (op)
        {
            case 1: insere(&arv, esc);
            break;
            
            case 2: remover(&arv, esc, esc2);
            break;

            case 3: listar(arv, esc);
            break;

            case 4: consulta(arv, esc);
            break;

            case 5: atualiza(&arv, esc);
            break;

            default:
            system("clear");
            printf("\n\t\t[Programa Finalizado]\n\n");
            break;
        }
    }
    
}