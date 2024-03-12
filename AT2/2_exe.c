#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 20

int main(){

    float *valor;
    valor = (float *)malloc(sizeof(float));

    printf("Digite um valor: ");
    scanf("%f", valor);

    char *texto;
    texto = (char *)malloc(TAMANHO * sizeof(char));

    sprintf(texto, "%f", *valor);
    
    printf("%s", texto);

    free(texto);
    free(valor);

    return 0;
}