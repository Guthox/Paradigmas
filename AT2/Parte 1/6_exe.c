#include <stdio.h>

int main(){
	int celsius;
	scanf("%d", &celsius);
	printf("Temperatura em Farenheit: %f", celsius * 9.0 / 5.0 + 32);
	return 0;
}
