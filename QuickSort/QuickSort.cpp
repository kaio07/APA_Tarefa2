#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void imprime(int *V  , int N){
    int i;
    for(i = 0; i < N; i++)
        printf("%2d ",V[i]);
    printf("\n");
}



int particiona(int *V, int inicio, int final ){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = V[inicio];
    while(esq < dir){
        while(V[esq] <= pivo)
            esq++;
        while(V[dir] > pivo)
            dir--;
        if(esq < dir){
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;
    return dir;
}

void QuickSort(int *V, int inicio, int fim) {
    int pivo;
    if(fim > inicio){
        pivo = particiona(V, inicio, fim);
        QuickSort(V, inicio, pivo-1);
        QuickSort(V, pivo+1, fim);
    }
}



int main(){
    int Vetor[7] = {23,4,67,-8,90,54,21};
int tamanho= sizeof(Vetor)/sizeof(Vetor[0]);

    printf("Vetor desordenado:\n");
    imprime(Vetor,tamanho);


    QuickSort(Vetor,0,tamanho-1);
    printf("Ordenado:\n");
    imprime(Vetor,tamanho);

    system("pause");
    return 0;
}

