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



void merge(int *Vetor,int inicio, int meio, int fim){
  
  int p1,p2, tamanho, i ,j, k;
  int *aux;
  int fim1 = 0; 
  int fim2 = 0;

  tamanho = fim -inicio+1;
  aux = (int*)malloc(tamanho*sizeof(int)); // aloca tamanho do vetor auxiliar

  p1= inicio;
  p2 = meio+1;


if (aux != NULL){   // percorre vetor auxiliar
    for(i = 0; i < tamanho; i++){

    // verifica em cada posição do p1 e p2 quem é o menor elemento
      if(!fim1 && !fim2){ 
      
        if(Vetor[p1] < Vetor[p2]){
                aux[i] = Vetor[p1];
                p1++;
                }
              else{ 
            aux[i] = Vetor[p2];
            p2++;
            }

        if(p1 > meio) fim1 = 1; // seta o fim do vetor 1  
        if(p2 > fim) fim2 = 1; // seta o fim do vetor 2
        }

      else{
        if(!fim1){
          aux[i] = Vetor[p1]; // se vetor 1 não acabou copia o que sobrou para o vetor auxiliar 
          p1++;
        }

        else{
          aux[i] = Vetor[p2]; // se vetor 2 não acabou copia o que sobrou dele para o vetor auxiliar
          p2++;
        }
        }

       
       } 

       // copia os valores do vetor auxiliar para o vetor inicial
    for(j = 0, k = inicio; j<tamanho; j++, k++){
      Vetor[k] = aux[j];  
    
      }

  
    }

    free(aux);

}   


void mergeSort(int *Vetor, int inicio, int fim){
  int meio;

  if(inicio < fim){
    meio = (inicio + fim)/2;  // calcula meio do vetor
    
    // mergeSort dados serão divididos
    mergeSort(Vetor,inicio,meio);   // mergeSort primeira metade
    mergeSort(Vetor, meio+1, fim);  // mergeSort segunda metade
    
    // combinar as duas partes de forma ordenada
    merge(Vetor,inicio,meio,fim);


  }
}


 int main()  
 {  
         int Vetor[] = {3,47,6,-10,90,12,31,20,12,23,67,78};
         int tamanho= sizeof(Vetor)/sizeof(Vetor[0]);
    
      cout <<" Vetor Desordenado:\n" ; 
      imprime(Vetor,tamanho);
      cout << " \n\n" ;

      mergeSort(Vetor,0,tamanho-1);
      cout << "Ordenado:\n";
      imprime(Vetor,tamanho); 
      cout << " \n\n" ;
 


      return 0 ; 
 }  