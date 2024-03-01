#include <stdio.h>

#define TAMANHO 3 // 3 * 3

void gerarMatriz(int matriz[TAMANHO][TAMANHO]);
void printarMatriz(int matriz[TAMANHO][TAMANHO]);
void somarMatriz(int matrizA[TAMANHO][TAMANHO], int matrizB[TAMANHO][TAMANHO], int matrizC[TAMANHO][TAMANHO]);
void subtrairMatriz(int matrizA[TAMANHO][TAMANHO], int matrizB[TAMANHO][TAMANHO], int matrizC[TAMANHO][TAMANHO]);
void multiplicarMatriz(int matrizA[TAMANHO][TAMANHO], int matrizB[TAMANHO][TAMANHO], int matrizC[TAMANHO][TAMANHO]);
void transposta(int matriz[TAMANHO][TAMANHO]);
int menu();

int main(){
    int matrizA[TAMANHO][TAMANHO];
    int matrizB[TAMANHO][TAMANHO];
    int matrizC[TAMANHO][TAMANHO];
    printf("Gerando a matriz A.\n");
    gerarMatriz(matrizA);
    printf("Gerando a matriz B.\n");
    gerarMatriz(matrizB);

    printf("A=\n");
    printarMatriz(matrizA);
    printf("--------------\n");
    printf("B=\n");
    printarMatriz(matrizB);
    int op;
    do{
        op = menu();

        switch (op){
            case 1:
                multiplicarMatriz(matrizA, matrizB, matrizC);
                printf("A*B =\n");
                printarMatriz(matrizC);
                break;
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
                multiplicarMatriz(matrizA, matrizB, matrizC);
                transposta(matrizC);
                printf("Transposta de C sendo C = A*B\n");
                printarMatriz(matrizC);
                break;
            case 5:
                break;
            default:
                printf("Operacao invalida.\n");
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

void gerarMatriz(int matriz[TAMANHO][TAMANHO]){
    int valor;
    for (int i = 0; i < TAMANHO; i++){
        for (int j = 0; j < TAMANHO; j++){
            printf("Digite um numero: ");
            scanf("%d", &valor);
            matriz[i][j] = valor;
        }
    }
}

void somarMatriz(int matrizA[TAMANHO][TAMANHO], int matrizB[TAMANHO][TAMANHO], int matrizC[TAMANHO][TAMANHO]){
    for (int i = 0; i < TAMANHO; i++){
        for (int j = 0; j < TAMANHO; j++){
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}

void subtrairMatriz(int matrizA[TAMANHO][TAMANHO], int matrizB[TAMANHO][TAMANHO], int matrizC[TAMANHO][TAMANHO]){
    for (int i = 0; i < TAMANHO; i++){
        for (int j = 0; j < TAMANHO; j++){
            matrizC[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }
}

void multiplicarMatriz(int matrizA[TAMANHO][TAMANHO], int matrizB[TAMANHO][TAMANHO], int matrizC[TAMANHO][TAMANHO]){
    int aux = 0;
    for (int i = 0; i < TAMANHO; i++){
        for (int j = 0; j < TAMANHO; j++){
            matrizC[i][j] = 0;
            for (int k = 0; k < TAMANHO; k++){
                aux = aux + ( matrizA[i][k] * matrizB[k][j] );
            }
            matrizC[i][j] = aux;
            aux = 0;
        }
    }
}

void transposta(int matriz[TAMANHO][TAMANHO]){
    int transposta[TAMANHO][TAMANHO];
    for (int i = 0; i < TAMANHO; i++){
        for (int j = 0; j < TAMANHO; j++){
            transposta[i][j] = matriz[j][i];
        }
    }
    
    for (int i = 0; i < TAMANHO; i++){
        for (int j = 0; j < TAMANHO; j++){
            matriz[i][j] = transposta[i][j];
        }
    }

}

void printarMatriz(int matriz[TAMANHO][TAMANHO]){
    for (int i = 0; i < TAMANHO; i++){
        for (int j = 0; j < TAMANHO; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}