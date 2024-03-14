#include <iostream>

#define NNOTAS 4 // Numero de notas diferentes

int tiposNotas[] = { 200, 50, 5, 1 }; // Valores das notas;
int* calcularSaque(int valor);
void printarNotas(int* notas);

int main() {

	int valor = 0;

	do {
		std::cout << "Digite o valor a ser sacado: ";
		std::cin >> valor;

		if (valor < 15 || valor > 500) {
			std::cout << "Valor de saque invalido.\
			O saque minimo neste caixa e de 15 reais\
			e o maximo 500 reais." << std::endl;
		}
	} while (valor < 15 || valor > 500);

	int* notas = calcularSaque(valor);
	printarNotas(notas);

	return 0;
}

void printarNotas(int *notas) {
	for (int i = 0; i < NNOTAS; i++) {
		std::cout << notas[i] << " notas de valor "\
			<< tiposNotas[i] << " reais." << std::endl;
	}
}

int* calcularSaque(int valor) {
	static int notas[NNOTAS];

	for (int i = 0; i < NNOTAS; i++) {
		notas[i] = valor / tiposNotas[i];
		valor = valor % tiposNotas[i];
	}

	return notas;
}
