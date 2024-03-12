#include <stdio.h>

#define TAMANHO 10

int pegarValor();
void printarValores(int valores[TAMANHO]);
void bubbleSortReverso(int *valores);

int main(){
    int valores[TAMANHO];
    int index = 0;
    for (int i = 0; i < TAMANHO; i++){
        valores[i] = pegarValor();
    }

    bubbleSortReverso(valores);
    printarValores(valores);
    
    return 0;
}

int pegarValor(){
    printf("Digite um valor inteiro: ");
    int valor;
    scanf("%d", &valor);
    return valor;
}

void bubbleSortReverso(int *valores){
    int aux;
    int finalizado;
    for (int i = 0; i < TAMANHO; i++){
        finalizado = 1;
        for (int j = 0; j <  TAMANHO - 1 - i; j++){
            if (valores[j] < valores[j+1]){
                aux = valores[j];
                valores[j] = valores[j + 1];
                valores[j+1] = aux;
                finalizado = 0;
            }
        }
        if (finalizado == 1){
            return;
        }
    }
} 

void printarValores(int valores[TAMANHO]){
    for (int i = 0; i < TAMANHO; i++){
        printf("%d ", valores[i]);
    }
}