// Bibliotecas
// Bibliotéca para entrada e saida incluind fgets, printf, scanf
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// formatação da linguagem utilizada pt-br
#include <locale.h>

// Definindo a struct Produto

//receber produto

#define LIST_LIMIT 10
//


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
    char lista[LIST_LIMIT][50];
    float calculo;
    float peso;


} Venda;


#define MAX_PRODUTOS 100

// Declaração de variáveis globais
Produto produtos[MAX_PRODUTOS];
int proxId = 1;
int numProdutos = 0;



// Função adicionar produto
void adicionarProduto() {
    // Validação para evitar sobrecargar de buffer
    if (numProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido.\n");
        return 1;
    }
    // Inicialização e auto incrementação do id
    Produto novoProduto;
    novoProduto.id = proxId++;

    // Inseração dos dados com printf e scanf
    printf("Digite o nome do produto: ");
    scanf("%s", novoProduto.produto);
    
    printf("Digite a categoria do produto: ");
    scanf("%s", novoProduto.categoria);
    
    printf("Digite a data de validade (DD-MM-AAAA): ");
    scanf("%s", novoProduto.validade);

    // inserção em array da lista
    produtos[numProdutos++] = novoProduto;
    printf("Produto adicionado com sucesso!\n");
}

// Função para listar produtos
void listarProdutos() {
    for (int i = 0; i < numProdutos; i++) {
        printf("ID: %d\nProduto: %s\nCategoria: %s\nValidade: %s\n\n", 
                produtos[i].id, produtos[i].produto, produtos[i].categoria, produtos[i].validade);
    }
}

// Função para atualizar produto
void atualizarProduto(int id) {
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].id == id) {
            printf("Digite o novo nome do produto: ");
            scanf("%s", produtos[i].produto);
            
            printf("Digite a nova categoria do produto: ");
            scanf("%s", produtos[i].categoria);
            
            printf("Digite a nova data de validade (DD-MM-AAAA): ");
            scanf("%s", produtos[i].validade);

            printf("Produto atualizado com sucesso!\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

void transacaoPedido(}{}
void menuCaixa(){
    int opcao;
    printf("Menu do caixa");

    // Display menu

    //switch
    //opcoes

    //Transação de pedidos > retiro de estoque e registro da venda
    
}

void registroVenda(){}
void consultaPreco(){}
void listagemProduto(){}
void precoCalculo(){}

void menuEstacao(){
    int opcao;

    // Display menu

     printf("\n   ---------------------PDV Hortifruti v0.1------------------");
	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
	printf("\n   |         Bem vindo! Por favor, escolha uma das opçõ      |");
	printf("\n   |         1. Registro da venda                            |");
	printf("\n   |         2. Consulta de preço                            |");
	printf("\n   |         3. Listagem dos produtos                        |");
	printf("\n   |         4. Preço e calculo                              |");
	printf("\n   |         0. encerrar aplicação                           |");
    printf("\n   |                                                         |");
	printf("\n   ---------------------PDV Hortifruti v0.1-------------------");

    scanf("%d",&opcao);
    //switch e opcoes
    switch (opcao)
    {
    case 1:
        registroVenda();
        break;
    case 2:
         consultaPreco();
        break;
    case 3:
        listagemProduto();
        break;
    case 4:
        precoCalculo();
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
	printf("\n\n\n Por favor, digite uma opção:");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                menuCaixa();
                break;
            case 2:
                menuEstacao();
                break;
            default:
                printf("Opção invalida.\n");
        }
    } while (opt != 0);

    return 0;
}
