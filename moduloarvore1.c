/*Autor: Henrique Ribeiro Favaro
RA: 115.408*/

#define maxnome 30

#define falso 0
#define verdadeiro 1
#define regnaoinserido 2
#define reginserido 3
#define direita 8
#define esquerda 7
#define regjaexiste 2
#define regnaoexiste 4
#define regnaoremovido 4
#define regremovido 5
#define regencontrado 2
#define regnaoencontrado 4
#define regnaoatualizado 4
#define regatualizado 2

typedef char tiponome[maxnome];

/* É criada a estrutura do registro que será utilizado para salvar os dados de cada cadastro */
typedef struct tiporeg
{
    tiponome nome;
    int idade;
    char genero;
    long int cpf;
    char tel[15];
}tiporeg;

/* É criado o elemento da arvore que conterá os registros futuramente */
typedef struct tipoelem
{
    tiporeg reg;
    struct tipoelem *esq, *dir;
    int bal;
    
}tipoelem;

typedef tipoelem *tipoarvore;

typedef struct TipoElem{
    tipoarvore raiz;         
    struct TipoElem *prox; 
} TipoElem;

typedef TipoElem *TipoPilha;

void CriaPilha(TipoPilha *p){
    *p = NULL; 
}

/* Temos a criação da pilha que sera utilizada para salvar os dados na arvore iterativa em ordem e posteriormente
realizar a impressao dos mesmos */
int PilhaVazia(TipoPilha p){
    return (p == NULL); 
}

/* Funcao de inserção de elementos na pilha, onde sempre é imserido um elemento no topo da pilha */
void InserePilha(TipoPilha *p, tipoarvore raiz){
    int tamanho;
    TipoElem *aux;
    tamanho = sizeof(TipoElem);  
    aux = malloc(tamanho);  
    aux->raiz = raiz;         
    aux->prox = (*p);      
    (*p) = aux;            
}

/* Funcao que remove o primeiro elemento do topo da pilha para retornar na aplicacao quando necessario */
void RemovePilha(TipoPilha *p, tipoarvore *raiz){
    TipoElem *aux;
    aux = (*p); 
    (*p) = aux->prox; 
    (*raiz) = aux->raiz;  
    free(aux);   
}

/* Retorna para a aplicacao o elemento que esta no topo da pilha */
tipoarvore TopoPilha(TipoPilha p){
    return (p->raiz); 
}

//---------------------------------- Arvore ---------------------------------- 
/* Nesta funcao temos a criação da arvore iterativa, onde sua raiz recebe valor Nulo */
void criaarvore(tipoarvore *raiz)
{
    (*raiz) = NULL;
}

/*Funcao para checar se a arvore possui algum elemento e retornar para a aplicacao quando solicitado */
int arvorevazia(tipoarvore raiz)
{
    return (raiz == NULL);
}

/* Funcao que localiza o maior elemento dentre os menores inseridos na árvore, para ser colocado como a nova raiz */
tipoarvore maiordosmenores(tipoarvore raiz)
{
    tipoarvore ant, post, aux;
    ant = NULL;
    post = raiz->esq;

    while (post->dir != NULL)
    {
        ant = post;
        post = post->dir;
    }

    aux = post;

    if (ant == NULL)
    {
        raiz->esq = post->esq;
    }

    else
    {
        ant->dir = post->esq;
    }
    return(aux);   
}

/* Funcao que localiza o menor elemento dentre os maiores inseridos na arvore, para ser colocado como a nova raiz */
tipoarvore menordosmaiores(tipoarvore raiz)
{
    tipoarvore ant, post, aux;
    ant = NULL;
    post = raiz->dir;

    while (post->esq != NULL)
    {
        ant = post;
        post = post->esq;
    }

    aux = post;

    if (ant == NULL)
    {
        raiz->dir = post->dir;
    }

    else
    {
        ant->esq = post->dir;
    }
    return(aux);   
}

/* Funcao que realiza a inserção de elementos na árvore, realizando a busca em ordem alfabética para ordenar os elementos
dentro da árvore */
int inserearvore(tipoarvore *raiz, tiporeg reg, int *cresceu)
{
    tipoarvore ant, post, aux;
    int sentido;
    ant = NULL;     
    post = *raiz;
    aux = malloc(sizeof(tipoelem));
    aux->reg = reg;
    aux->esq = NULL;
    aux->dir = NULL;
    while (post!=NULL)
    {
        if(strcmp(post->reg.nome,reg.nome) < 0)
        {
            ant = post;
            post = ant->dir;
            sentido = direita;
        }
        else if(strcmp(post->reg.nome,reg.nome) > 0)
        {
            ant = post;
            post = ant->esq;
            sentido = esquerda;
        }
        else return(regjaexiste);
    }

    if(ant == NULL)
    {
        *raiz = aux;  
    }

    else
    {
        if (sentido == esquerda)
        {
            ant->esq = aux;
        }

        else
        {
            ant->dir = aux;
        }
    }

    return(reginserido);  
}

/* Funcao que realiza uma busca com o registro recebido, e assim o encontra dentro da árvore, faz sua remocao, busca 
quem sera colocado na raiz, que sera o maior dentre os menores elementos abaixo da raiz removida */
int removearvore(tipoarvore *raiz, tiporeg *reg, int *cresceu)
{
    tipoarvore ant, post, aux;
    int sentido, achou=0;
    ant = NULL;
    post = *raiz;
    while (post != NULL)
    {
        if (strcmp(post->reg.nome,reg->nome)<0)
        {
            ant = post;
            sentido = direita;
            post = post->dir;
        }

        else if (strcmp(post->reg.nome,reg->nome)>0)
        {
            ant = post;
            sentido = esquerda;
            post = post->esq;
        }
        else
        {
            achou = 1;
            aux = post;
            *reg = post->reg;

            if (post->esq == NULL)
            {
                if(ant == NULL)
                {
                    *raiz = post->dir;
                }

                else if (sentido == direita)
                {
                    ant->dir = post->dir;
                }

                else
                {
                    ant->esq = post->dir;
                }
                
                
            }

            else if (post->dir == NULL)
            {
                if (ant == NULL)
                {
                    *raiz = post->esq;
                }

                else if (sentido == direita)
                {
                    ant->dir = post->esq;
                }

                else
                {
                    ant->esq = post->esq;
                }
            }

            else
            {
                aux = maiordosmenores(post);
                post->reg = aux->reg;
            }
            post = NULL;
        }
    }

    if(achou)
    {
        free(aux);
        return(regremovido);
    }

    else
    {
        return(regnaoremovido);
    }   
}

/* Esta funcao realiza a mesma remocao da funca à cima, porem coloca na raiz o menor elemento dentre
os maiores abaixo da raiz que sera removida */
int removearvore_2(tipoarvore *raiz, tiporeg *reg, int *cresceu)
{
    tipoarvore ant, post, aux;
    int sentido, achou=0;
    ant = NULL;
    post = *raiz;
    while (post != NULL)
    {
        if (strcmp(post->reg.nome,reg->nome)<0)
        {
            ant = post;
            sentido = direita;
            post = post->dir;
        }

        else if (strcmp(post->reg.nome,reg->nome)>0)
        {
            ant = post;
            sentido = esquerda;
            post = post->esq;
        }
        else
        {
            achou = 1;
            aux = post;
            *reg = post->reg;

            if (post->esq == NULL)
            {
                if(ant == NULL)
                {
                    *raiz = post->dir;
                }

                else if (sentido == direita)
                {
                    ant->dir = post->dir;
                }

                else
                {
                    ant->esq = post->dir;
                }
                
                
            }

            else if (post->dir == NULL)
            {
                if (ant == NULL)
                {
                    *raiz = post->esq;
                }

                else if (sentido == direita)
                {
                    ant->dir = post->esq;
                }

                else
                {
                    ant->esq = post->esq;
                }
            }

            else
            {
                aux = menordosmaiores(post);
                post->reg = aux->reg;
            }
            post = NULL;
        }
    }

    if(achou)
    {
        free(aux);
        return(regremovido);
    }

    else
    {
        return(regnaoremovido);
    }   
}

/* Funcao que realiza uma listagem em ordem utilizando a pilha para ordenar os elementos e depois disso
apresentá-los em ordem da impressao por meio da ordem alfabetica */
void inorder(tipoarvore raiz)  
{
    tipoarvore aux;
    TipoPilha pilha;
    int cont = 1;
    CriaPilha(&pilha);
    aux = raiz;
    do
    {
        while (aux != NULL)
        {
            InserePilha(&pilha, aux);
            aux = aux->esq;
        }

        if(!PilhaVazia(pilha))
        {
            RemovePilha(&pilha, &aux);
            printf("\n\t\t[%d]", cont);
            printf("\n\t\tNome: %s", aux->reg.nome);
            printf("\n\t\tIdade: %d", aux->reg.idade);
            printf("\n\t\tGenero: %c", aux->reg.genero);
            printf("\n\t\tCPF: %ld", aux->reg.cpf);
            printf("\n\t\tTel.: %s\n", aux->reg.tel);
            cont++;
            aux = aux->dir;
        }
        
    } while ((aux != NULL) || (!PilhaVazia(pilha))); 
}

/* Nesta funcao serao impressos, porem sera impresso primeiramente a raiz, depois o elemento da
esquerda depois o da direita da raiz impressa */
void preorder(tipoarvore raiz)
{
    if(!arvorevazia(raiz))
    {
        printf("\n\t\tNome: %s", raiz->reg.nome);
        printf("\n\t\tIdade: %d", raiz->reg.idade);
        printf("\n\t\tGenero: %c", raiz->reg.genero);
        printf("\n\t\tCPF: %ld", raiz->reg.cpf);
        printf("\n\t\tTel.: %s\n", raiz->reg.tel);
        preorder(raiz->esq);
        preorder(raiz->dir);
    }
}

/* Nesta funcao será realizada a mesma funcao que a funcao acima, porem teremos a impressao do galho à 
esquerda depois do galho à direita e por ultimo a raiz respectiva */
void posorder(tipoarvore raiz)
{
    if(!arvorevazia(raiz))
    {
        posorder(raiz->esq);
        posorder(raiz->dir);
        printf("\n\t\tNome: %s", raiz->reg.nome);
        printf("\n\t\tIdade: %d", raiz->reg.idade);
        printf("\n\t\tGenero: %c", raiz->reg.genero);
        printf("\n\t\tCPF: %ld", raiz->reg.cpf);
        printf("\n\t\tTel.: %s\n", raiz->reg.tel);
    }
}

/* NEsta funcao sera informado um nome por meio do REG e assim teremos uma busca dentro da arvore para localizar o 
elemento desejado, que sera retornado para a aplicacao dentro do mesmo parametro REG */
int busca(tipoarvore raiz, tiporeg *reg)
{
    tipoarvore ant, post, aux;
    int sentido, achou=0;
    ant = NULL;
    post = raiz;
    while (post != NULL)
    {
        if (strcmp(post->reg.nome,reg->nome)<0)
        {
            ant = post;
            sentido = direita;
            post = post->dir;
        }

        else if (strcmp(post->reg.nome,reg->nome)>0)
        {
            ant = post;
            sentido = esquerda;
            post = post->esq;
        }
        else
        {
            achou = 1;
            *reg = post->reg;
            post = NULL;
        }
    }

    if(achou)
    {
        return(regencontrado);
    }

    else
    {
        return(regnaoencontrado);
    }   
}

/* Nesta funcao sera recebido um nome por meio do REG juntamente dos seus dados atualizados, e, apos isso 
será feita a atualizacao dentro da raiz desse registro para que o mesmo seja salvo atualizado
dentro da arvore */
int atualizacao(tipoarvore *raiz, tiporeg reg)
{
    tipoarvore ant, post, aux;
    int sentido, achou=0;
    ant = NULL;
    post = *raiz;
    while (post != NULL)
    {
        if (strcmp(post->reg.nome,reg.nome)<0)
        {
            ant = post;
            sentido = direita;
            post = post->dir;
        }

        else if (strcmp(post->reg.nome,reg.nome)>0)
        {
            ant = post;
            sentido = esquerda;
            post = post->esq;
        }
        else
        {
            achou = 1;
            post->reg.idade = reg.idade;
            strcpy(post->reg.tel,reg.tel);
            post = NULL;
        }
    }

    if(achou)
    {
        return(regatualizado);
    }

    else
    {
        return(regnaoatualizado);
    }   
}