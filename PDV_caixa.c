// Bibliotecas
// Bibliotéca para entrada e saida incluind fgets, printf, scanf
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// formatação da linguagem utilizada pt-br
#include <locale.h>

#define MAX_PRODUTOS 100
#define LIMIT_VENDAS 1000
#define LIMIT_LISTA 255

typedef struct {
    int id;
    char produto[50];
    char categoria[50];
    char validade[11];
    float preco;
    int estoque;
    // tipo de pesagem
    char granel[];

} Produto;

typedef struct
{
    int id_venda;
    char lista[LIMIT_LISTA];
    float calculo;
    float peso;


} Venda;

// Declaração de variáveis globais
Produto produtos[MAX_PRODUTOS];
Venda vendas[LIMIT_VENDAS];
int numProdutos = 0;

// Transação

// Atualização do estoque


int loadidByFile(char fileName[]){
    int maxId=0,id=0;;
    FILE *idFile;
    idFile = fopen(fileName,"r");
    if (idFile == NULL) {
            printf("Erro ao abrir o arquivo!\nCriando um arquivo");
            FILE *createFile;
            createFile = fopen("produtos.txt","w");
            fclose(createFile);
            return -1;
    }
    while (fscanf(idFile, "ID: %d", &id) == 1){
        if (id > maxId) {
            maxId = id;
        }
    }
    fclose(idFile);
    return maxId;
}

void transacaoPedido(){}
void menuCaixa(){
    int opcao;
    int id,idVendas;
    
    id = loadidByFile("produtos.txt");
    idVendas = loadidByFile("vendas.txt");
    
    //printf("%d | %d", &id,&idVendas);

     // Display menu

    printf("\n   -----------------PDV Hortifruti caixa v0.2-----------------");
	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
	printf("\n   |         Bem vindo! Por favor, para começar,             |");
	printf("\n   |         selecione 1                                     |");
	printf("\n   |         1. Calculo de valor e compra                    |");
	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
	printf("\n   |         0. encerrar aplicação                           |");
    printf("\n   |                                                         |");
	printf("\n   ----------------------------------------------------------");
    printf("\n\n\n Por favor, digite uma opção:\n");

    //switch
    scanf("%d",&opcao);
    //switch e opcoes
    switch (opcao)
    {
    case 1:
        registroVenda();
        break;
    case 0:
        return;
        
    default:
        printf("opção invalida.\n");
    } while (opcao != 0);

    return;
    //opcoes

    //Transação de pedidos > retiro de estoque e registro da venda
    
}


//looping EOF e carregamento dos protudos
loadId(Produto produtos[]){

    FILE *fileProdutos;
    fileProdutos = fopen("produtos.txt","r");

    int i=0;
    while (fscanf(fileProdutos,"ID: %d", &produtos[i].id)!=EOF)
    {
        i++;
    }
    fclose(fileProdutos);
    return i;
    
}


void calcPesagem(){}
void consultaPreco(){}


void menuEstacao(){
    int opcao;

    // Display menu

    printf("\n   ------------------PDV Hortifruti v0.1 estação--------------");
	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
	printf("\n   |         Bem vindo! Por favor, escolha uma das opçõoes   |");
	printf("\n   |         1. pesagem                                      |");
	printf("\n   |         2. cálculo do preço por peso                    |");
	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
	printf("\n   |         0. encerrar aplicação                           |");
    printf("\n   |                                                         |");
	printf("\n   ---------------------PDV Hortifruti v0.1-------------------");

    scanf("%d",&opcao);
    //switch e opcoes
    switch (opcao)
    {
    case 1:
        calcPesagem();
        break;
    case 2:
        consultaPreco();
        break;

    case 0:
        return 0;
        
    default:
        printf("opção invalida.\n");
    } while (opcao != 0);

    return 0;
   

    // Registro de vendas
    // Consulta de preço e listagem de produtos
    // calculo de preço e pesagem

}

// Função principal
int main() {
    int id, opt;
    setlocale(LC_ALL, "Portuguese");
   
    do {

        // escolher entre caixa e estação

    printf("\n   ---------------------PDV Hortifruti v0.1------------------");
	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
	printf("\n   |         Por favor, escolha o tipo da aplicação          |");
	printf("\n   |         1. Estação                                      |");
	printf("\n   |         2. Caixa                                        |");
	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
	printf("\n   ---------------------PDV Hortifruti v0.1-------------------");
	printf("\n\n\n Por favor, digite uma opção:\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                menuEstacao();
                break;
            case 2:
                menuCaixa();
                break;
            default:
                printf("Opção invalida.\n");
        }
    } while (opt != 0);

    return 0;
}
