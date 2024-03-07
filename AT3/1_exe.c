#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 3

void criarMatriz(int ***matriz);
void preencherMatriz(int ***matriz);
void printarMatriz(int ***matriz);

int main(){

    // declaração de variável ponteiro para ponteiro
    int **mat;
    int **matrizA;
    int **matrizC;
    criarMatriz(&mat);
    criarMatriz(&matrizA);
    criarMatriz(&matrizC);

    // preenchendo a matriz
    preencherMatriz(&mat);
    preencherMatriz(&matrizA);

    // mostrando os elementos da matriz
    printarMatriz(&mat);
    printf("#################\n");
    printarMatriz(&matrizA);

    for (int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){
            matrizC[i][j] = mat[i][j] + matrizA[i][j];
        }
    }
    printf("#################\n");
    printarMatriz(&matrizC);

    free(mat);
    free(matrizA);
    free(matrizC);

    return 0;
}

void criarMatriz(int ***matriz){
    *matriz = (int **)malloc(LINHAS * sizeof(int *));
    for (int i = 0; i < LINHAS; i++)
        (*matriz)[i] = (int *)malloc(COLUNAS * sizeof(int));
}

void preencherMatriz(int ***matriz){
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
            (*matriz)[i][j] = i + j;
    }
}

void printarMatriz(int ***matriz){
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
            printf("%d\t", (*matriz)[i][j]);
        printf("\n");
    }
}