// Autor: Henrique Ribeiro Favaro
// RA: 115.408

#define maxnome 40 

#define regnaoexiste 2
#define regjaexiste 1
#define regremovido 3
#define reginserido 4
#define regatualizado 5

typedef char tiponome[maxnome];

typedef struct tiporeg
{
    tiponome nome;
    int idade;
    char genero;
    char cpf[15];
    char tel[15];
} tiporeg;

typedef struct tipoelem
{
    tiporeg reg;
    struct tipoelem *prox;
} tipoelem;

typedef tipoelem *tipolista;


//--------------------------------------------------------------------------------------------------------------------------------


/*A função CRIALISTA inicia o ponteiro L, recebido por parametro, apontando para NULL pois ainda não existem elementos cadastrados
na lista, isso é feitoapenas para iniciar uma ponta da lista e poder se fazer um encadeamento a cada elemento cadastrado posteriormente */
void crialista(tipolista *l)
{
    (*l) = NULL;
}


/*A função LISTA CHEIA apenas retorna FALSO sempre, pois uma lista dinamica nunca se enche. Ela recebe o ponteiro L da lista
e serve apenas para uso da aplicação principal caso necessário */
int listacheia(tipolista l)
{
    return 0;
}


/*A função LISTA VAZIA recebe o ponteiro L e checa dentro do mesmo se está apontando para NULL, caso esteja significa que não
existem elementos inseridos na lista, assim sendo retorna à aplicação o valor utilizado para as checagens, possibilitanto
o desenvolvimento do sistema sem gerar problemas de execução futuros. */
int listavazia(tipolista l)
{
    return (l==NULL);
}


/*A funcao BUSCAPOSLISTA recebe o ponteiro L da Lista, um nome e um ponteiro para posição anterior pela qual retornará a posição
anterior do elemento procurado. Faz uma busca dentre os registros na Lista, caso não exista o elemento ela informa que o elemento não
existe, porem caso ele exista, será retornado pelo ponteiro POSANT o registro que aponta para o registro procurado. Nao retorna a posicao
do registro procurado em si, mas sim a posição de seu anterior. A aplicação precisa checar se a lista nao esta vazia antes de utilizar*/
int buscaposlista(tipolista l, tiponome nome, tipolista *posant)
{
    tipolista auxpos;

    *posant = NULL;
    auxpos = l;

    if(auxpos != NULL)
    {
        while((strcmp(auxpos->reg.nome,nome)<0)&&(auxpos->prox != NULL))
        {
            *posant = auxpos;
            auxpos = auxpos->prox;
        }

        if(strcmp(auxpos->reg.nome,nome)<0)
        {
            *posant = auxpos;
            return (regnaoexiste);
        }

        else if(strcmp(auxpos->reg.nome,nome)>0)
        {
            return (regnaoexiste);
        }

        else return (regjaexiste);
    }

    else return (regnaoexiste);
}


/*A funcao REMOVELISTA recebe o ponteiro da Lista (*l) como parâmetro e um registro (*reg) tambem como parametro, pelo qual
sera retornado ao usuario o registro completo removido da Lista. A aplicacao precisa checar se a lista está vazia ou nao, para evitar
problemas de execucao no codigo. Caso a lista nao esteja vazia, será feita uma busca pelos registros, se o registro procurado para
remover, existir, será removido e retornado pela variavel REG, caso contrario sera retornado que o registro procurado nao existe */
int removelista(tipolista *l, tiporeg *reg)
{
    tipolista antpos, prox;
    int res;

    res = buscaposlista(*l, reg->nome, &antpos);

    if(res==regnaoexiste)
    {
        return (regnaoexiste);
    }

    else if(antpos != NULL)
    {
        prox = antpos->prox;
        *reg = antpos->prox->reg;
        antpos->prox = prox->prox;
        free(prox);

        return (regremovido);
    }

    else
    {
        prox = *l;
        (*l) = prox->prox;
        (*reg) = prox->reg;
        free(prox);

        return (regremovido);
    }
}


/*A funcao INSERELISTA recebe o ponteiro da Lista (*l) por parametro e um registro a ser inserido. A aplicacao necessita verificar
se a lista nao esta vazia primeiramente, para nao gerar erros na execução do programa. A funcao primeiramente irá checar se o registro
à ser inserido já existe e retornar se existe ou nao. Se nao existir, fará a inserção do mesmo na sua devida posição em ordem
alfabética dentro da Lista e após isso retornara que o Registro foi inserido, deixando valida a operação realizada. */
int inserelista(tipolista *l, tiporeg reg)
{
    tipolista antpos, aux;
    int res;

    res = buscaposlista(*l, reg.nome, &antpos);

    if(res == regjaexiste)
    {
        return (regjaexiste);
    }

    else
    {
        aux = malloc(sizeof(tipoelem));
        aux->reg = reg;

        if(antpos == NULL)
        {
            aux->prox = (*l);
            (*l) = aux;
        }

        else
        {
            aux->prox = antpos->prox;
            antpos->prox = aux;
        }

        return (reginserido);
    }
}


/*A funcao CONSULTALISTA recebe o ponteiro da lista (l), e o nome do registro à ser consultado dentro da estrutura de registro
(*reg), pela qual será retornado o registro encontrado. O usuario precisa checar se a lista nao está vazia antes de utilizar a funcao
para nao gerar problemas na execucao do programa. Apos isso, será feita uma busca entre os registros e retornado se existe ou nao 
o registro em questao. Caso exista, o registro será retornado por completo na estrutura (*reg) e podera ser utilizado dentro da 
aplicação para seus devidos fins */
int consultalista(tipolista l, tiporeg *reg)
{
    tipolista antpos, prox;
    int res;

    res = buscaposlista(l, reg->nome, &antpos);

    if(res == regnaoexiste)
    {
        return (regnaoexiste);
    }

    else
    {
        if(antpos == NULL)
        {
            *reg = l->reg;

            return (regjaexiste);
        }

        else
        {
            prox = antpos->prox;
            *reg = prox->reg;

            return (regjaexiste);
        }
    }
}


/*A funcao ATUALIZALISTA recebe o ponteiro da lista (*l) por parametro e um registro (reg), com o nome do registro à ser atualizado
juntamente com as informações atualizadas. A aplicação precisar checar se a lista nao está vazia antes de operar com a funcao.
Caso o elemento exista, será realizado a troca de seus dados pelos novos dados atualizados e retornado à aplicacao que o registro
foi atualizado. Caso contrario será retornado que o registro nao existe, e nao serao feitas modificacoes em nenhum registro */
int atualizalista(tipolista *l, tiporeg reg)
{
    int res;

    tipolista antpos, prox;

    res = buscaposlista(*l, reg.nome, &antpos);

    if(res == regnaoexiste)
    {
        return (regnaoexiste);
    }
    else
    {
        if(antpos==NULL)
        {
            (*l)->reg = reg;
        }

        else
        {
            prox = antpos->prox;
            prox->reg = reg;
        }

        return (regjaexiste);
    }
}


/*A funcao CONSULTAREGNAPOSICAO recebe o ponteiro da lista (l) e uma posicao (pos) informada pela aplicação principal. A aplicação deve
checar se a lista nao esta vazia antes de utilizar a consulta para evitar problemas na execução do codigo. Caso existam registros,
será percorrida a lista posicao por posicao até chegar na posicao desejada, neste momento a funcao retornará à aplicacao o registro
(tiporeg) encontrado naquela posicao */
tiporeg consultaregnaposicao(tipolista l, int pos)
{
    tipolista aux;
    int i;

    aux = l;
    i = 1;

    while((i<pos)&&(aux!=NULL))
    {
        i++;
        aux = aux->prox;
    }

    return (aux->reg);
}


/*A funcao TOTALLISTA tem a finalidade de percorrer a lista e acrescentar 1 unidade à variavel total a cada elemento encontrado na lsta.
Nao necessita checar se a lista esta vazia ou nao, pois se estiver vazia retornara 0 como total de elementos. Rececbe o ponteiro de
Lista (l) e busca quantos registros o mesmo engloba. A funcao pode ser utilizada pela aplicação para informar ao usuário quantos registros
ja estão inseridos na Lista*/
int totallista(tipolista l)
{
    tipolista aux;
    int i;
    int total = 0;

    aux = l;

    while(aux != NULL)
    {
        total++;
        aux = aux->prox;
    }

    return total;
}