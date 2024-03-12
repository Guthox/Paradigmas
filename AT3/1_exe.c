#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;
void moda(int v[], int n);
int v1[13] = { 1,6,8,9,9,5,9,7,9,9,5,6,4 };
int v2[11] = { 5,5,8,6,5,8,5,7,8,4,8 };
int v3[10] = { 1,8,4,5,9,7,6,3,2,0 };
void media(int v[], int n);
void mediana(int v[], int n);
void ordenar(int v[], int n);

int main()
{
	char op;
	cout << "Deseja digitar os valores manualmente? S ou N" << endl;
	cin >> op;
	op = toupper(op);
	if (op == 'S'){
		// Digita o vetor manualmente
		cout << "ok\n";
	}
	
    cout << "\nModa do vetor 1" << endl;
    moda(v1, 13);
	media(v1, 13);
	mediana(v1, 13);

    cout << "\nModa do vetor 2" << endl;
    moda(v2, 11);
	media(v2, 11);
	mediana(v2, 11);	

    cout << "\nModa do vetor 3" << endl;
    moda(v3, 10);
	media(v3, 10);
	mediana(v3, 10);

    system("Pause"); //se preferir coloque este comando em comentario
    return 0;
}

void mediana(int v[], int n){
	// Cria uma copia para nao mexer no vetor original.
	int* vCopia = new int[n];
	for (int i = 0; i < n; i++){
		vCopia[i] = v[i];
	}
	double median;
	ordenar(vCopia, n);
	if (n % 2 == 0){
		median = (vCopia[n/2 - 1] + v[n/2]) / 2.0;
	}
	else{
		median = v[n/2];
	}
	cout << "Mediana: " << median << "." << endl;
}

void ordenar(int v[], int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (v[i] > v[i+1]){
				int aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
			}
		}
	}
}

void media(int v[], int n){
	double media = 0;
	for (int i = 0; i < n; i++){
		media = media + v[i];
	}
	media = media / n;
	cout << "Media: " << fixed << setprecision(2) << media << "." << endl;
}

// função para o cálculo da moda
void moda(int v[], int n)
{
    // ordenando o vetor
    float aux;
    for (int i = 1; i <= n - 1; i++)
        for (int j = n - 1; j >= 0; j--)
            if (v[j - 1] > v[j])
            {
                aux = v[j - 1];
                v[j - 1] = v[j];
                v[j] = aux;
            }
    //contar quantas classes de elementos
    int cont = 0;
    for (int i = 0; i <= n - 2; i++)
        if (v[i] != v[i + 1]) cont++;
    cont++; //somando 1 ao numero de classes
    //criando o vetor com o numero de elementos
    int vc[cont], hist[cont];
    //preenchendo o vetor contagem com os elementos se n for diferente de cont
    if (n == cont)
        cout << "Vetor amodal" << endl;
    else
    {
        int j = 0;
        for (int i = 0; i <= n - 2; i++)
            if (v[i] != v[i + 1])
            {
                vc[j] = v[i];
                j++;
            }
        vc[j] = v[n - 1];
        //contar os elementos das classes
        for (int j = 0; j <= cont - 1; j++)
        {
            int k = 0;
            for (int i = 0; i <= n - 1; i++)
                if (vc[j] == v[i]) k++;
            hist[j] = k;
        }
        // buscando a posição do maior elemento em hist
        int pm, max;
        max = hist[0];
        for (int j = 0; j <= cont - 1; j++)
            if (max < hist[j]) max = hist[j];
        //retornando a moda, os elementos de vc cujo respectivo hist é igual ao max
        cout << "Moda: \n";
        for (int j = 0; j <= cont - 1; j++)
            if (hist[j] == max) cout << vc[j] << endl;
    }
}

