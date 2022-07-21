typedef int TipoDado;

typedef struct TipoElem{
    TipoDado dado;         //contem o conteudo desse elemento da pilha
    struct TipoElem *prox; //contem o endereço do elemento de baixo na pilha
} TipoElem;

typedef TipoElem *TipoPilha;

void CriaPilha(TipoPilha *p){
    *p = NULL;  //declara o endereço do Topo como NULL quando estiver vazia
}

int PilhaVazia(TipoPilha p){
    return (p == NULL);  //confere se é verdade e retorna Verdadeiro ou Falso
}

void InserePilha(TipoPilha *p, TipoDado x){
    int tamanho;
    TipoElem *aux;
    tamanho = sizeof(TipoElem);  //tamanho recebe o size da struct TipoElem
    aux = malloc(tamanho);  //aloca um espaço de memoria com o tamanho fornecido
    aux->dado = x;         //armazena o dado nesse elemento
    aux->prox = (*p);      //pega o endereço de p como sendo o seu anterior na pilha
    (*p) = aux;            //topo recebe o endereço do aux que acabou de ser adicionado
}

void RemovePilha(TipoPilha *p, TipoDado *x){
    TipoElem *aux;
    aux = (*p);  //aux recebe o endereço de p e seu conteudo de dado
    (*p) = aux->prox;  //p agora recebe o endereço do prox topo da pilha anterior ao que acabou de ser removido
    (*x) = aux->dado;  //x recebe o DADO que estava no topo da pilha e vai retornar isso ao usuario quando necessario
    free(aux);   //devolve o espaço de memoria alocado para o sistema
}

TipoDado TopoPilha(TipoPilha p){
    return (p->dado); //retorna o dado armazenado no topo da pilha
}