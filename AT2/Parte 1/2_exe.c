#include <stdio.h>

int main(){
	int porcentagem = 50;
	char data[] = "31/12/2000";
	char capital[] = "50.000.000,00";
	
	printf("\"Vendemos %d%% a mais que no ano passado.\"\n", porcentagem);
	printf("Em %s nosso capital era de R$ %s.\n", data, capital);
	printf("A barra utilizada para pastas seria '/' ou '\\'?");
	return 0;
}
