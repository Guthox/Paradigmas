#include <stdio.h>

int main(){

	float num1;
	float num2;

	scanf("%f", &num1);
	scanf("%f", &num2);

	printf("Soma: %f\n", num1+num2);
	printf("Divisao: %f\n", num1/num2);
	printf("Multiplicacao: %f\n", num1*num2);
	printf("Media aritimetica real: %f\n", (num1+num2)/2);
	printf("Media aritimetica inteira: %.0f\n", (num1+num2)/2);
	return 0;
}
