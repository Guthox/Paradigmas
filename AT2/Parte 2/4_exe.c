#include <stdio.h>
#include <string.h>

#define TAMANHO 100

struct Projeto
{
    char nome[20];
    char area[20];
    int valorTotal;
    char data[20];
    int duracao;
};


const char* escolherArea();
int menu();
struct Projeto adicionarProjeto();
void printarProjeto(struct Projeto projeto);


int main(){
    
    int op;
    struct Projeto projetos[TAMANHO];
    int index = 0;

    char nome[20];
    int achou = 0;

    do{
        op = menu();

        switch (op){
            case 1:
                projetos[index] = adicionarProjeto();
                index = index + 1;
                printf("Projeto adicionado com sucesso.\n");
                break;
            case 2:
                printf("Nome do projeto: ");
                scanf("%s", &nome);
                for (int i = 0; i <= index; i++){
                    if (strcmp(nome, projetos[i].nome) == 0){
                        printarProjeto(projetos[i]);
                        break;
                        achou = 1;
                    }
                }
                if (achou == 0){
                    printf("Projeto nao encontrado.\n");
                }
                achou = 0;
                break;
            case 3:
                break;
            default:
                printf("Operacao invalida.\n");
                break;
        }

    }while (op != 3);
}

int menu(){
    int op;
    printf("1) Adicionar projeto.\n");
    printf("2) Consultar projeto.\n");
    printf("3) Sair.\n");
    scanf("%d", &op);
    return op;
}

struct Projeto adicionarProjeto(){
    char nome[20];
    printf("Nome do projeto: \n");
    scanf("%s", &nome);

    char area[20];
    strcpy(area, escolherArea());

    int valorTotal;
    printf("Valor total do projeto: \n");
    scanf("%d", &valorTotal);

    char data[20];
    printf("Data prevista de inicio: \n");
    scanf("%s", &data);

    int duracao;
    printf("Duracao em meses: \n");
    scanf("%d", &duracao);

    struct Projeto projeto1;
    strcpy(projeto1.nome, nome);
    strcpy(projeto1.area, area);
    projeto1.valorTotal = valorTotal;
    strcpy(projeto1.data, data);
    projeto1.duracao = duracao;
    return projeto1;
}

const char* escolherArea(){
    int op;
    while (1) {
        printf("1) Marketing\n");
        printf("2) Operacional\n");
        printf("3) Inovacao\n");
        scanf("%d", &op);

        switch (op){
            case 1:
                return "Marketing";
                break;
            case 2:
                return "Operacional";
                break;
            case 3:
                return "Inovação";
                break;
            default:
                printf("Operacao invalida.\n");
                break;
        }
    }
}

void printarProjeto(struct Projeto projeto){
    printf("Nome: %s\n", projeto.nome);
    printf("Area: %s\n", projeto.area);
    printf("Valor total: %d\n", projeto.valorTotal);
    printf("Data inicial prevista: %s\n", projeto.data);
    printf("Duracao em meses: %d\n", projeto.duracao);
}