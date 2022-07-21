/*Autor: Henrique Ribeiro Favaro
RA: 115.408*/

/* Nesta funcao temos a criação da arvore iterativa, onde sua raiz recebe valor Nulo */
void criaarvore2(tipoarvore *raiz)
{
    (*raiz) = NULL;
}

/*Funcao para checar se a arvore possui algum elemento e retornar para a aplicacao quando solicitado */
int arvorevazia2(tipoarvore raiz)
{
    return (raiz == NULL);
}

/* Funcao que localiza o maior elemento dentre os menores inseridos na árvore, para ser colocado como a nova raiz,
porem de forma recursiva, diferente da funcao na arvore iterativa */
tipoarvore maiordosmenores2(tipoarvore *raiz)
{
    tipoarvore aux;
    if((*raiz)->dir != NULL)
    {
        return (maiordosmenores2(&((*raiz)->dir)));
    }
    else
    {
        aux = (*raiz);
        (*raiz) = aux->esq;
        return(aux);
    }
}

/* Funcao que localiza o menor elemento dentre os maiores inseridos na arvore, para ser colocado como a nova raiz,
porem de forma recursiva, diferente da funcao na arvore iterativa */
tipoarvore menordosmaiores2(tipoarvore *raiz)
{
    tipoarvore aux;
    if((*raiz)->esq != NULL)
    {
        return (menordosmaiores2(&((*raiz)->esq)));
    }
    else
    {
        aux = (*raiz);
        (*raiz) = aux->dir;
        return(aux);
    } 
}

/* Funcao que recebe um registro por meio do parametro REG e faz uma busca alfabetica para que apos isso realize a insercao
desse registro na arvore na raiz correta, de forma recursiva */
int inserearvore2(tipoarvore *raiz, tiporeg reg, int *cresceu)
{
    if(arvorevazia2(*raiz))
    {
        (*raiz) = malloc(sizeof(tipoelem));
        (*raiz)->reg = reg;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        return(reginserido);
    }
    else if(strcmp((*raiz)->reg.nome,reg.nome) < 0)
    {
        return(inserearvore2(&((*raiz)->dir) , reg, cresceu));
    }
    else if(strcmp((*raiz)->reg.nome,reg.nome) > 0)
    {
        return(inserearvore2(&((*raiz)->esq) , reg, cresceu));
    }
    else 
    {
        return(regjaexiste);
    }
}

/* Funcao recursiva que recebe um nome em seu parametro REG, faz a busca alfabetica descendo na arvore para a direita 
ou esquerda e apos encontrado, faz a remocao do registro em questao. Localiza o maior dos menores para que este seja
colocado no local da remocao realizada */
int removearvore2(tipoarvore *raiz, tiporeg *reg, int *diminuiu)
{
    tipoarvore aux;
    if((*raiz) == NULL)
    {
        return(regnaoencontrado);
    }
    else if(strcmp((*raiz)->reg.nome,reg->nome) < 0)
    {
        return (removearvore2(&((*raiz)->dir) , reg, diminuiu));
    }
    else if(strcmp((*raiz)->reg.nome,reg->nome) > 0)
    {
        return (removearvore2(&((*raiz)->esq) , reg, diminuiu));
    }
    else
    {
        if((*raiz)->esq == NULL)
        {
            aux = (*raiz);
            (*raiz) = aux->dir;
            (*reg) = aux->reg;
            free(aux);
            return (regremovido);
        }
        else if((*raiz)->dir == NULL)
        {
            aux = (*raiz);
            (*raiz) = aux->esq;
            (*reg) = aux->reg;
            free(aux);
            return(regremovido);
        }
        else
        {
            aux = maiordosmenores2(&((*raiz)->esq));
            (*reg) = (*raiz)->reg;
            (*raiz)->reg = aux->reg;
            free(aux);
            return(regremovido);
        }
    }
}

/* Funcao recursiva que recebe um nome em seu parametro REG, faz a busca alfabetica descendo na arvore para a direita 
ou esquerda e apos encontrado, faz a remocao do registro em questao. Localiza o menor dos maiores para que este seja
colocado no local da remocao realizada */
int removearvore2_2(tipoarvore *raiz, tiporeg *reg, int *diminuiu)
{
    tipoarvore aux;
    if((*raiz) == NULL)
    {
        return(regnaoencontrado);
    }
    else if(strcmp((*raiz)->reg.nome,reg->nome) < 0)
    {
        return (removearvore2(&((*raiz)->dir) , reg, diminuiu));
    }
    else if(strcmp((*raiz)->reg.nome,reg->nome) > 0)
    {
        return (removearvore2(&((*raiz)->esq) , reg, diminuiu));
    }
    else
    {
        if((*raiz)->esq == NULL)
        {
            aux = (*raiz);
            (*raiz) = aux->dir;
            (*reg) = aux->reg;
            free(aux);
            return (regremovido);
        }
        else if((*raiz)->dir == NULL)
        {
            aux = (*raiz);
            (*raiz) = aux->esq;
            (*reg) = aux->reg;
            free(aux);
            return(regremovido);
        }
        else
        {
            aux = menordosmaiores2(&((*raiz)->esq));
            (*reg) = (*raiz)->reg;
            (*raiz)->reg = aux->reg;
            free(aux);
            return(regremovido);
        }
    }
}

/* Funcao recursiva que imprime os registros em ordem alfabetica na aplicacao quando solicitado */
void inorder2(tipoarvore raiz)
{
    if(!arvorevazia2(raiz))
    {
        inorder2(raiz->esq);
        printf("\n\t\tNome: %s", raiz->reg.nome);
        printf("\n\t\tIdade: %d", raiz->reg.idade);
        printf("\n\t\tGenero: %c", raiz->reg.genero);
        printf("\n\t\tCPF: %ld", raiz->reg.cpf);
        printf("\n\t\tTel.: %s\n", raiz->reg.tel);
        inorder2(raiz->dir);
    }
}

/* Funcao recursiva que imprime primeiro a raiz, depois seu registro à esquerda e depois o seu à direita */
void preorder2(tipoarvore raiz)
{
    if(!arvorevazia2(raiz))
    {
        printf("\n\t\tNome: %s", raiz->reg.nome);
        printf("\n\t\tIdade: %d", raiz->reg.idade);
        printf("\n\t\tGenero: %c", raiz->reg.genero);
        printf("\n\t\tCPF: %ld", raiz->reg.cpf);
        printf("\n\t\tTel.: %s\n", raiz->reg.tel);
        preorder2(raiz->esq);
        preorder2(raiz->dir);
    }
}

/* Funcao recursiva que imprime o registro à esquerda, depois o registro à direita e apos isso imprime por 
ultimo a raiz respectiva aos registros impressos */
void posorder2(tipoarvore raiz)
{
    if(!arvorevazia2(raiz))
    {
        posorder2(raiz->esq);
        posorder2(raiz->dir);
        printf("\n\t\tNome: %s", raiz->reg.nome);
        printf("\n\t\tIdade: %d", raiz->reg.idade);
        printf("\n\t\tGenero: %c", raiz->reg.genero);
        printf("\n\t\tCPF: %ld", raiz->reg.cpf);
        printf("\n\t\tTel.: %s\n", raiz->reg.tel);
    }
}

/* Funcao recursiva que recebe um nome em seu parametro REG, faz a busca em ordem alfabetica e retorna para a aplicacao 
o registro completo referente ao nome indicado */
int busca2(tipoarvore raiz, tiporeg *reg)
{
    if(raiz == NULL)
    {
        return(regnaoencontrado);
    }
    else if(strcmp(raiz->reg.nome,reg->nome) < 0)
    {
        return (busca2((raiz->dir) , reg));
    }
    else if(strcmp(raiz->reg.nome,reg->nome) > 0)
    {
        return (busca2((raiz->esq) , reg));
    }
    else
    {
        (*reg) = raiz->reg;
    }
}

/* Funcao recursiva que recebe o nome e os dados atualizados referentes à esse nome, faz uma busca pela arvore até
localizar tal registro e faz a troca de seus dados, salvando a atualizacao dentro da arvore na raiz localizada */
int atualizacao2(tipoarvore *raiz, tiporeg reg)
{ 
    if((*raiz) == NULL)
    {
        return(regnaoencontrado);
    }
    else if(strcmp((*raiz)->reg.nome,reg.nome) < 0)
    {
        return (atualizacao2(&(*raiz)->dir , reg));
    }
    else if(strcmp((*raiz)->reg.nome,reg.nome) > 0)
    {
        return (atualizacao2(&(*raiz)->esq , reg));
    }
    else
    {
        (*raiz)->reg.idade = reg.idade;
        strcpy((*raiz)->reg.tel,reg.tel);
    }
}