#include <iostream>        
#include <stdlib.h>



using namespace std ;

void imprime(int *V  , int tam){
    int i;
    for(i = 0; i < tam; i++){
      cout <<  V[i] << " "; 
  
    }
    cout << "\n";
  
 }  

int particiona(int *V, int inicio, int final ){
    int esq, dir, pivo, aux;
    esq = inicio; // define esquerda como inicio
    dir = final; // define direita no final
    pivo = V[inicio]; // define pivo no inicio 
    
    while(esq < dir){
        while(V[esq] <= pivo) // percorre ate encontrar elementos menores que o pivo
            esq++;
        while(V[dir] > pivo) // percorre direita  ate encontrar elementos menores que o pivo
           //   esq++;
            dir--;
        if(esq < dir){ // se direita for maior que esquerda troca os valores 
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    V[inicio] = V[dir]; // ultimo valor da direita se torna inicio
    V[dir] = pivo; // valorda direita se torna pivo 
    return dir;  // retorna direita ponto onde todos a esqueda sao menor e a direita sao maior
}

void QuickSort(int *V, int inicio, int fim) {
    int pivo;
    if(fim > inicio){
        pivo = particiona(V, inicio, fim); // separar os dados em duas particoes
        QuickSort(V, inicio, pivo-1); // quickSort para elementos antes do pivo
        QuickSort(V, pivo+1, fim); // quickSort para elementos depois do pivo
    }
}



int main(){
    int Vetor[] = {3,47,6,-10,90,12,31,20,12};
int tamanho= sizeof(Vetor)/sizeof(Vetor[0]);

    cout <<" Vetor Desordenado:\n" ;
    imprime(Vetor,tamanho);
    cout << " \n" ;


    QuickSort(Vetor,0,tamanho-1);
    cout << "Vetor Ordenado:\n";
    imprime(Vetor,tamanho);
    cout << " \n" ;
   
    return 0;
}

