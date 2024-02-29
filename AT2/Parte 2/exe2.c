#include <stdio.h>

#define TAMANHO 9 // 3 * 3

void gerarMatriz(int *matriz);
void printarMatriz(int *matriz);
void somarMatriz(int *matrizA, int *matrizB, int *matrizC);
void subtrairMatriz(int *matrizA, int *matrizB, int *matrizC);
int menu();

int main(){
    int matrizA[TAMANHO];
    int matrizB[TAMANHO];
    int matrizC[TAMANHO];
    printf("Gerando a matriz A.\n");
    gerarMatriz(matrizA);
    printf("Gerando a matriz B.\n");
    gerarMatriz(matrizB);

    int op;
    do{
        op = menu();

        switch (op){
            case 1:
                break; // TODO MULTIPLICAr
            case 2:
                subtrairMatriz(matrizA, matrizB, matrizC);
                printf("A-B = \n");
                printarMatriz(matrizC);
                break;
            case 3:
                somarMatriz(matrizA, matrizB, matrizC);
                printf("A+B = \n");
                printarMatriz(matrizC);
                break;
            case 4:
                break; // TODO TRANSPOSTA
            case 5:
                break;
            default:
                printf("Operacao invalida.");
        }

    }while(op !=5);

    return 0;
}

int menu(){
    printf("1) A*B\n");
    printf("2) A-B\n");
    printf("3) A+B\n");
    printf("4) Transposta da matriz C, sendo que C=A*B\n");
    printf("5) Sair do Programa\n");
    int op;
    scanf("%d", &op);
    return op;
}

void gerarMatriz(int *matriz){
    for (int i = 0; i < TAMANHO; i++){
        printf("Digite um numero: ");
        scanf("%d", &matriz[i]);
    }
}

void somarMatriz(int *matrizA, int *matrizB, int *matrizC){
    for (int i = 0; i < TAMANHO; i++){
        matrizC[i] = matrizA[i] + matrizB[i];
    }
}

void subtrairMatriz(int *matrizA, int *matrizB, int *matrizC){
    for (int i = 0; i < TAMANHO; i++){
        matrizC[i] = matrizA[i] - matrizB[i];
    }
}

void printarMatriz(int *matriz){
    for (int i = 0; i < TAMANHO; i++){
        printf("%d ", matriz[i]);
        if ( (i+1) % 3 == 0){
            printf("\n");
        }
    }
}