y// Autor: Henrique Ribeiro Favaro
// RA: 115.408

#define maxlista 30

#define maxnome 50

#define terra -1

#define regjaexiste 1
#define regnaoexiste 2
#define regfoiinserido 2
#define regremovido 1

typedef char tiponome[maxnome];

typedef struct tiporeg
{
    char nome[maxnome];
    int idade;
    char genero;
    char cpf[15];
    char tel[15];
    int prox;
}tiporeg;

typedef struct
{
    tiporeg lista[maxlista];
    int total, livre, ocupado;
}tipolista;

//-------------------------------------------------------------------------------------------------------------------

/* A função CRIA LISTA aponta o inicio da lista para terra, pois está sem nenhum elemento,
define seu total como 0 ,(zero), devido à estar vazia e diz que a primeira posicao livre é logo a primeira da lista.
Após isso, faz o encadeamento de cada elemento da lista estática até chegar em seu tamanho máximo, ligando a posição
PROXIMO de um para o outro. Recebe por parâmetro apenas a LISTA a ser operada.
 */
void crialista(tipolista *L)
{
    int i;

    L->total = 0;
    L->ocupado = terra;
    L->livre = 0;

    for(i=0;i<(maxlista-1);i++)
    {
        L->lista[i].prox = i+1;   //faz o encadeamento de elementos na lista
    }

    L->lista[maxlista-1].prox = terra;
}


/* Confere pelo total de elementos na lista se a mesma está vazia ou não
e retorna "TRUE or FALSE". Recebe no cabeçalho apenas a LISTA em operação.
*/
int listavazia(tipolista L)
{
    return (L.total == 0);
}


/* Confere se a lista está cheia, comparando o total de elementos com o tamanho máximo da lista
Recebe no cabeçalho apenas a LISTA em operação.
*/
int listacheia(tipolista L)
{
    return (L.total == maxlista);
}


/* Faz uma busca pelos elementos da lista um à um e salva a posição anterior do elemento procurado no parâmetro POS recebido. 
Caso a lista esteja vazia, não será executada a busca e retornará que nao existem registros.
Se existirem elementos será feita a busca em ordem alfabética até chegar no elemento procurado, caso ele
exista, será retornado a posição do seu antecessor pelo parâmetro POS, se não existir após toda a busca,
seré informado que o registro não existe. Recebe além do parâmetro POS, a LISTA e o NOME do registro buscado, no cabeçalho da função.
 */
int busca(tipolista L, tiponome name, int *pos)
{
    int posaux;
    
    *pos = terra;

    if(listavazia(L))
    {
        return (regnaoexiste);
    }

    else
    {
        posaux = L.ocupado;

        while((strcmp(L.lista[posaux].nome,name)<0)&&(L.lista[posaux].prox!=terra))
        {
            *pos = posaux;
            posaux = L.lista[posaux].prox; //avanca as posicoes ate sair do while
        }

        if(strcmp(L.lista[posaux].nome,name)==0)
        {
            return (regjaexiste);
        }

        else
        {
            if(strcmp(L.lista[posaux].nome,name)<0)
            {
               *pos = posaux;
            }

            return (regnaoexiste);
        }
    }
}


/* A função de inserção, faz uma busca pela lista para checar a posição alfabética do elemento à ser inserido e também
checa se o mesmo já existe. Caso exista, retorna que o elemento já existe, se não existir, fará a inserção no meio ou em alguma
das pontas da lista, respitando a ordem alfabética. Se for inserir no meio da lista, fará o anterior do novo inserido,
apontar para ele, e o novo apontará para o que estava antes em seu lugar na lista utilizando a variável PROX dentro de sua estrutura,
deixando assim a sequência correta alfabéticamente. Caso a inserção seja na ponta inicial, o primeiro elemento da Lista será o novo
inserido, e ele apontaŕa para o que era o primeiro antes. Se for no ultimo da lista, a função só fará o penúltimo apontar para 
o novo elemento. A lista não pode estar cheia, a aplicação do usuário deve checar essa condição antes. Recebe por parâmetro a LISTA
operada e também no cabeçalho da função utiliza-se de um registro REG para buscar e inserir o mesmo na lista.
 */
int inserelista(tipolista *L, tiporeg reg)
{
    int posant, res, aux;

    res = busca(*L, reg.nome, &posant);

    if(res==regjaexiste)
    {
        return (regjaexiste);
    }

    else
    {
        aux = L->livre;
        L->livre = L->lista[aux].prox;
        L->lista[aux] = reg;

        if(posant==terra)
        {
            L->lista[aux].prox = L->ocupado;
            L->ocupado = aux;
        }

        else
        {
            L->lista[aux].prox = L->lista[posant].prox;
            L->lista[posant].prox = aux;
        }

        L->total++;
        return (regfoiinserido);
    }
}


/* A função de remoção faz a mesma busca pela lista em ordem alfabética para checar se existe ou não o elemento.
Caso encontrado, e for o primeiro da lista, fará com que seu sucessor seja apontado como primeiro da lista. Se for algum elemento
do meio da lista, fará seu anterior apontar para o seu próximo, e sua posição será setada como livre para uma próxima inserção.
A lista não pode estar vazia, caso a aplicação tente executar com uma lista vazia, ocorrerão erros no programa.
Recebe como parâmetros a LISTA em L e o registro em REG, assim consegue remover e também retornar para a aplicação
qual registro foi removido da lista.
 */
int removelista(tipolista *L, tiporeg *reg)
{
    int aux, res, posant;

    res = busca(*L, reg->nome, &posant);

    if(res==regnaoexiste)
    {
        return (regnaoexiste);
    }

    else
    {
        if(posant==terra)
        {
            aux = L->ocupado;
            L->ocupado = L->lista[aux].prox;
        }

        else
        {
            aux = L->lista[posant].prox;
            L->lista[posant].prox = L->lista[aux].prox;
        }

        *reg = L->lista[aux];  //retorna o registro
        L->lista[aux].prox = L->livre;  //deixa encadeado nos disponiveis
        L->livre = aux;  //passa para o primeiro livre
        L->total--;

        return (regremovido);
    }
}


/* A função CONSULTA REG NA POSICAO, basicamente faz uma busca pela lista até chegar na posicao informada pelo usuário recebida no 
cabeçalho como POS, se o elemento buscado exisir, será retornado o registro encontrado na posição informada. A aplicação deve checar
se a lista não está vazia, caso tente executar mesmo estando vazia, o programa apresentará problemas na execução. Recebe no cabeçalho
também a LISTA , como L, em operaçao.
 */
tiporeg consultaregnaposicao(tipolista l, int pos)
{
    int posaux, i;

    posaux = l.ocupado;  //aponta para o primeiro elemento da sequencia

    i = 1;

    while(i<pos)
    {
        posaux = l.lista[posaux].prox;
        i++;  //avanca i para chegar ate a pos solicitada
    }

    return (l.lista[posaux]);
}


/* A função TOTAL LISTA basicamente retorna o valor da variável total que é incrementada na inserção e decrementada na 
remoção de elementos na lista, e serve como um controle para informar se a lista está cheia ou vazia. Recebe em seu cabeçalho
apenas a LISTA em operação.
 */
int totallista(tipolista l)
{
    return (l.total);  //retorna o total de cadastros na lista
}


/* A função CONSULTA LISTA faz a mesma busca em ordem alfabética e retorna se o registro existe ou não. Porém
retorna através do parâmetro TIPOREG REG o registro encontrado dentro da lista nessa consulta. Caso a aplicação tente
acessar essa função com uma lista vazia, o programa apresentará problemas na execução. A aplicação em uso deve checar
anteriormente a condição da lista, entendendo se está ou não vazia. Recebe em seu cabeçalho , também, a LISTA como L.
 */
int consultalista(tipolista L, tiporeg *reg)
{
    int posaux;

    posaux = L.ocupado;

    while((strcmp(L.lista[posaux].nome,reg->nome)<0)&&(L.lista[posaux].prox!=terra))
    {
        posaux = L.lista[posaux].prox;
    }

    if((strcmp(L.lista[posaux].nome,reg->nome)==0))
    {
        *reg = L.lista[posaux];
        return (regjaexiste);
    }

    else
    {
        return (regnaoexiste);
    }

}


/* A função ATUALIZA LISTA, recebe um registro no parâmetro REG com informações à serem atualizadas de algum registro e com
o mesmo nome do registro à ser buscado e atualizado. Será realiada a busca à algumsimilar na lista através do nome. Caso encontrado,
copia os dados do registro recebido pelo parâmetro e coloca-os no registro dentro da lista, setando as atualizações no registro desejado.
A aplicação tambem deve checar se a lista não está vazia, previnindo assim de quaisquer tipos de erros no programa
 */
int atualizalista(tipolista *L, tiporeg reg)
{
    int posaux;

    posaux = L->ocupado;

    while((strcmp(L->lista[posaux].nome,reg.nome)<0)&&(L->lista[posaux].prox!=terra))
    {
        posaux = L->lista[posaux].prox;
    }

    if((strcmp(L->lista[posaux].nome,reg.nome)==0))
    {
        L->lista[posaux].idade = reg.idade;
        L->lista[posaux].genero = reg.genero;
        strcpy(L->lista[posaux].cpf,reg.cpf);
        strcpy(L->lista[posaux].tel,reg.tel);

        return (regjaexiste);
    }

    else
    {
        return (regnaoexiste);
    }
}