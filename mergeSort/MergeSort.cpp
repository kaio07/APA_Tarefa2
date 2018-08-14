#include <iostream>       
 using namespace std;  
 void imprime(int * X, int tam ){  
      for (int i = 0; i < tam; ++i)  
      {  
           cout << "["<< X[i] << "]";  
      }  
      cout << "\n";  
 }  
 void intercala(int X[], int inicio, int fim, int meio){  
      int posLivre,inicio_vetor1, inicio_vetor2, i;  
      int aux[10];  
      inicio_vetor1 = inicio;  
      inicio_vetor2 = meio+1;  
      posLivre = inicio;  
      while(inicio_vetor1 <= meio && inicio_vetor2 <= fim){  
           if (X[inicio_vetor1] <= X[inicio_vetor2])  
           {  
                aux[posLivre] = X[inicio_vetor1];  
                inicio_vetor1++;  
           }  
           else{  
                aux[posLivre] = X[inicio_vetor2];  
                inicio_vetor2++;  
           }  
           posLivre++;  
      }  
      //se ainda existem numeros no primeiro vetor  
      //que nao foram intercalados  
      for (int i = inicio_vetor1; i <= meio; ++i)  
      {  
           aux[posLivre] = X[i];  
           posLivre++;  
      }  
      //se ainda existem numeros no segundo vetor  
      //que nao foram intercalados  
      for (int i = inicio_vetor2; i <= fim; ++i)  
      {  
           aux[posLivre] = X[i];  
           posLivre++;  
      }  
      //retorne os valores do vetor aux para o vetor X  
      for (int i = inicio; i <=fim; ++i)  
      {  
           X[i] = aux[i];  
      }  
 }  
 void merge (int X[], int inicio, int fim){  
      int meio;  
      if (inicio < fim)  
      {  
           meio = (inicio+fim)/2;  
           merge (X,inicio, meio);  
           merge (X,meio+1, fim);  
           intercala(X,inicio, fim, meio);  
           //imprime(X,10);  
      }  
 }  
 int main()  
 {  
      int X [] = {3,0,5,8,2,4,9,7,1,6};  
      merge (X, 0 ,9); 
      imprime(X,10); 
      return 0;  
 }  