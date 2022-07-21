#include <stdio.h>
#define maxvet 30
int A[maxvet], i, n, j, B[maxvet];
int aux=0, aux2=0, x=1, y=1, fim, z=0;
void main(void){
    // leitura do tamanho do vetor
    do{
        printf("\nDigite o tamanho do vetor (0<n<%d): ",maxvet);
        scanf("%d",&n);
    } while ((n<1)||(n>maxvet));

    // leitura dos elementos do vetor A
    printf("\nLeitura do vetor A:\n");
    for (i=0;i<n;i++){
    printf("Digite A[%d] = ",i);
    scanf("%d",&A[i]);
    }

    // mostra os elementos do vetor
    printf("\nElementos lidos do vetor:");
    for (i=0;i<n;i++){
    printf("\nA[%d] = %d",i,A[i]);
    }

    // Busca de elemento no vetor
    printf("\n\nRemocao de subsequencia:");
    printf("\nDigite a posicao inicial a ser removida: ");
    scanf("%d",&aux);
    printf("\nDigite a posicao final a ser removida: ");
    scanf("%d",&fim);

    for(i=aux;i<=fim;i++){ //Troca os valores de tras pro lugar dos valores a serem removidos
        A[i]=A[fim+y];
        y++;
        z++;
    }
    for(i=fim+1;i<n;i++){//Pega o resto do vetor e coloca onde os outros arrastados estavam antes
        A[i]=A[i+z];
    }
    n-=z; //diminui o tamanho do vetor dependendo do tanto retirado

    // mostra os elementos do vetor apos remocao
    printf("\nO vetor ficou assim:");
    for (i=0;i<n;i++){
        printf("\nA[%d] = %d",i,A[i]);
    }printf("\n");
}
