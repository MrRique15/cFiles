/*Autor: Henrique Ribeiro Favaro
RA: 115.408*/

void criaarvore3(tipoarvore *raiz)
{
    (*raiz) = NULL;
}

int arvorevazia3(tipoarvore raiz)
{
    return (raiz == NULL);
}

void balanceiaesq(tipoarvore *raiz, int *cresceu)
{
    tipoarvore p1, p2;

    switch ((*raiz)->bal)
    {
    case 0:
        (*raiz)->bal = -1;
        break;
    
    case 1:
        (*raiz)->bal = 0;
        (*cresceu) = 0;
        break;

    case -1:
        p1 = (*raiz)->esq;
        if(p1->bal == -1) /* Rotacao LL */
        {
            (*raiz)->esq = p1->dir;
            p1->dir = (*raiz);
            (*raiz)->bal = 0;
            (*raiz) = p1;
            (*raiz)->bal = 0;
            (*cresceu) = 0;
        }
        else             /* Rotacao LR */   
        {
            p2 = p1->dir;
            p1->dir = p2->esq;
            (*raiz)->esq = p2->dir;
            p2->esq = p1;
            p2->dir = (*raiz);
            if(p2->bal == 1)
            {
                (*raiz)->bal = 0;
                p1->bal = -1;
                p2->bal = 0;
            }
            else
            {
                (*raiz)->bal = 1;
                p1->bal = 0;
                p2->bal = 0;
            }
            (*raiz) = p2;
            (*cresceu) = 0;
        }
        break;
    }
}

//daqui
void balanceiaesq2(tipoarvore *raiz, int *diminuiu) 
{
    tipoarvore p1, p2;
    switch ((*raiz)->bal)
    {
    case 0:
        (*raiz)->bal = -1;
        diminuiu = 0;
        break;
    
    case -1:
        p1 = (*raiz)->esq;
        if((p1->bal) == -1)      
        {
            (*raiz)->esq = p1->dir;
            p1->dir = (*raiz);
            (*raiz)->bal = 0;
            p1->bal = 0;
            (*raiz) = p1;
        }
        else if((p1->bal) == 1) 
        {
            p2 = p1->dir;
            (*raiz)->esq = p2->dir;
            p1->dir = p2->esq;
            p2->dir = (*raiz);
            p2->esq = p1;
            if((p2->bal) == 0)
            {
                p2->bal = 0;
                (*raiz)->bal = 0;
                p1->bal = 0;
            }
            else if((p2->bal) == 1)
            {
                p2->bal = 0;
                (*raiz)->bal = 0;
                p1->bal = -1; 
            }
            else
            {
                p2->bal = 0;
                (*raiz)->bal = 1;
                p1->bal = 0;
            }
            (*raiz) = p2;
        }
        else if((p1->bal) == 0)
        {
            (*raiz)->esq = p1->dir;
            p1->dir = (*raiz);
            p1->bal = 1;
            (*raiz) = p1;
            diminuiu = 0;
        }
        break;
    
    case 1:
        (*raiz)->bal = 0;
        break;

    }
} //aqui

void balanceiadir(tipoarvore *raiz, int *cresceu)
{
    tipoarvore p1, p2;


    switch ((*raiz)->bal)
    {
        case 0:
            (*raiz)->bal = 1;
        break;
    
        case -1:
            (*raiz)->bal = 0;
            (*cresceu) = 0;
        break;

        case 1:
            p1 = (*raiz)->dir;
            if(p1->bal == 1) /* Rotacao RR */
            {
                (*raiz)->dir = p1->esq;
                p1->esq = (*raiz);
                (*raiz)->bal = 0;
                (*raiz) = p1;
                (*raiz)->bal = 0;
                (*cresceu) = 0;
            }
            else             /* Rotacao RL */
            {
                p2 = p1->esq;
                p1->esq = p2->dir;
                (*raiz)->dir = p2->esq;
                p2->dir = p1;
                p2->esq = (*raiz);
                if(p2->bal == -1)
                {
                    (*raiz)->bal = 0;
                    p1->bal = 1;
                    p2->bal = 0;
                }
                else
                {
                    (*raiz)->bal = -1;
                    p1->bal = 0;
                    p2->bal = 0;
                }
                (*raiz) = p2;
                (*cresceu) = 0;
            }
        break;
    }
}


void balanceiadir2(tipoarvore *raiz, int *diminuiu) 
{
    tipoarvore p1, p2;
    switch ((*raiz)->bal)
    {
    case 0:
        (*raiz)->bal = 1;
        diminuiu = 0;
        break;
    
    case -1:
        (*raiz)->bal = 0;
        break;
    
    case 1:
        p1 = (*raiz)->dir;
        if((p1->bal) == 1)       
        {
            (*raiz)->dir = p1->esq;
            p1->esq = (*raiz);
            (*raiz)->bal = 0;
            p1->bal = 0;
            (*raiz) = p1;
        }
        else if((p1->bal) == -1) 
        {
            p2 = p1->esq;
            (*raiz)->dir = p2->esq;
            p1->esq = p2->dir;
            p2->esq = (*raiz);
            p2->dir = p1;
            if((p2->bal) == 0)
            {
                p2->bal = 0;
                (*raiz)->bal = 0;
                p1->bal = 0;
            }
            else if((p2->bal) == -1)
            {
                p2->bal = 0;
                (*raiz)->bal = 0;
                p1->bal = 1; 
            }
            else
            {
                p2->bal = 0;
                (*raiz)->bal = -1;
                p1->bal = 0;
            }
            (*raiz) = p2;
        }
        else if((p1->bal) == 0)
        {
            (*raiz)->dir = p1->esq;
            p1->esq = (*raiz);
            p1->bal = -1;
            (*raiz) = p1;
            diminuiu = 0;
        }
        break;
    }
}

tipoarvore maiordosmenores3(tipoarvore *raiz, int *diminuiu)
{
    tipoarvore aux;
    if((*raiz)->dir != NULL)
    {
        return(maiordosmenores3(&((*raiz)->dir),diminuiu));
    }
    else
    {
        aux = (*raiz);
        (*raiz) = aux->esq;
        (*diminuiu) = 1;
        return(aux);
    }
}

tipoarvore menordosmaiores3(tipoarvore *raiz, int *diminuiu)
{
    tipoarvore aux;
    if((*raiz)->esq != NULL)
    {
        return(menordosmaiores3(&((*raiz)->esq),diminuiu));
    }
    else
    {
        aux = (*raiz);
        (*raiz) = aux->dir;
        (*diminuiu) = 1;
        return(aux);
    }
}

int inserearvore3(tipoarvore *raiz, tiporeg reg, int *cresceu)
{
    int res;
    if(arvorevazia(*raiz))
    {
        (*raiz) = malloc(sizeof(tipoarvore));
        (*raiz)->reg = reg;
        (*raiz)->dir = NULL;
        (*raiz)->esq = NULL;
        (*raiz)->bal = 0;
        (*cresceu) = 1;
        return(reginserido);
    }
    else if(strcmp((*raiz)->reg.nome, reg.nome) < 0)
    {
        res = inserearvore3(&((*raiz)->dir), reg, cresceu);

        /*if(*cresceu)
        {
            balanceiadir(raiz, cresceu);
        }*/
        return res;
    }
    else if(strcmp((*raiz)->reg.nome, reg.nome) > 0)
    {
        res = inserearvore3(&((*raiz)->esq), reg, cresceu);
        
        /*if(*cresceu)
        {
            balanceiaesq(raiz, cresceu);
        }*/=
        return(res);
    }
    else
    {
        *cresceu = 0;
        return(regnaoinserido);
    }
}

int removearvore3(tipoarvore *raiz, tiporeg *reg, int *diminuiu)
{
    int res;
    tipoarvore aux;
    if(arvorevazia3(*raiz))
    {
        (*diminuiu) = 0;
        return(regnaoencontrado);
    }
    else if(strcmp((*raiz)->reg.nome, reg->nome) < 0)
    {
        res = removearvore3(&((*raiz)->dir),reg,diminuiu);
        if(res == regnaoencontrado)
        {
            return(res);
        }
        else if(diminuiu)
        {
            balanceiaesq2(raiz,diminuiu);
            return(res);
        }
    }
    else if(strcmp((*raiz)->reg.nome, reg->nome) > 0)
    {
        res = removearvore3(&((*raiz)->esq),reg,diminuiu);
        if(res == regnaoencontrado)
        {
            return(res);
        }
        else if(diminuiu)
        {
            balanceiadir2(raiz,diminuiu);
            return(res);
        }
    }
    else
    {
        (*reg) = (*raiz)->reg;
        aux = (*raiz);
        if((*raiz)->esq == NULL)
        {
            (*raiz) = aux->dir;
            (*diminuiu) = 1;
            free(aux);
            return(regremovido);
        }
        else if((*raiz)->dir == NULL)
        {
            (*raiz) = aux->esq;
            (*diminuiu) = 1;
            free(aux);
            return(regremovido);
        }
        else
        {
            aux = maiordosmenores3(&(aux->esq),diminuiu);
            (*raiz)->reg = aux->reg;
            free(aux);
            if(diminuiu)
            {
                balanceiadir2(raiz,diminuiu);
            }
            return(regremovido);
        }
    }
}

void inorder3(tipoarvore raiz)
{
    if(!arvorevazia(raiz))
    {
        inorder3(raiz->esq);
        printf("\n\t\tNome: %s", raiz->reg.nome);
        printf("\n\t\tIdade: %d", raiz->reg.idade);
        printf("\n\t\tGenero: %c", raiz->reg.genero);
        printf("\n\t\tCPF: %ld", raiz->reg.cpf);
        printf("\n\t\tTel.: %s\n", raiz->reg.tel);
        inorder3(raiz->dir);
    }
}

void preorder3(tipoarvore raiz)
{
    if(!arvorevazia3(raiz))
    {
        printf("\n\t\tNome: %s", raiz->reg.nome);
        printf("\n\t\tIdade: %d", raiz->reg.idade);
        printf("\n\t\tGenero: %c", raiz->reg.genero);
        printf("\n\t\tCPF: %ld", raiz->reg.cpf);
        printf("\n\t\tTel.: %s\n", raiz->reg.tel);
        preorder3(raiz->esq);
        preorder3(raiz->dir);
    }
}

void posorder3(tipoarvore raiz)
{
    if(!arvorevazia3(raiz))
    {
        posorder3(raiz->esq);
        posorder3(raiz->dir);
        printf("\n\t\tNome: %s", raiz->reg.nome);
        printf("\n\t\tIdade: %d", raiz->reg.idade);
        printf("\n\t\tGenero: %c", raiz->reg.genero);
        printf("\n\t\tCPF: %ld", raiz->reg.cpf);
        printf("\n\t\tTel.: %s\n", raiz->reg.tel);
    }
}

int busca3(tipoarvore raiz, tiporeg *reg)
{
    if(raiz == NULL)
    {
        return(regnaoencontrado);
    }
    else if(strcmp(raiz->reg.nome,reg->nome) < 0)
    {
        return (busca3((raiz->dir), reg));
    }
    else if(strcmp(raiz->reg.nome,reg->nome) > 0)
    {
        return (busca3((raiz->esq), reg));
    }
    else
    {
        (*reg) = raiz->reg;
    }
}

int atualizacao3(tipoarvore *raiz, tiporeg reg)
{ 
    if((*raiz) == NULL)
    {
        return(regnaoencontrado);
    }
    else if(strcmp((*raiz)->reg.nome,reg.nome) < 0)
    {
        return (atualizacao3(&(*raiz)->dir , reg));
    }
    else if(strcmp((*raiz)->reg.nome,reg.nome) > 0)
    {
        return (atualizacao3(&(*raiz)->esq , reg));
    }
    else
    {
        (*raiz)->reg.idade = reg.idade;
        strcpy((*raiz)->reg.tel,reg.tel);
    }
}