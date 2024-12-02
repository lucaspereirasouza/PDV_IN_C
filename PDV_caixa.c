// Bibliotecas
// Bibliotéca para entrada e saida incluind fgets, printf, scanf
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// formatação da linguagem utilizada pt-br
#include <locale.h>

#define MAX_PRODUTOS 255
#define LIMIT_VENDAS 1000
#define LIMIT_LISTA 255

typedef struct
{
    int id;
    char produto[50];
    char categoria[50];
    char validade[11];
    float preco;
    int estoque;
    // tipo de pesagem
    float valorPesagem;
    char granel[15];

} Produto;



// Declaração de variáveis globais
Produto produtos[MAX_PRODUTOS];
int proxId = 1;
int numProdutos = 0;

typedef struct
{
    int id_venda;
    char lista[LIMIT_LISTA];
    float calculo;
    float peso;


} Venda;

void calculoDaCompra(){

    // void calcularCompra(Produto produtos[], int totalProdutos) {
    int idProduto, quantidade;
    char continuar;
    float valorTotal = 0.0;

    printf("Bem-vindo ao calculo de compras!\n");

    do {
        // Solicitar ID do produto
        printf("\nDigite o ID do produto que deseja comprar: ");
        scanf("%d", &idProduto);

        // Procurar o produto na lista
        Produto *produtoEscolhido = NULL;
        for (int i = 0; i < MAX_PRODUTOS; i++) {
            if (produtos[i].id == idProduto) {
                produtoEscolhido = &produtos[i];
                break;
            }
        }

        // Validar se o produto existe
        if (produtoEscolhido == NULL) {
            printf("Produto com ID %d não encontrado. Tente novamente.\n", idProduto);
            continue;
        }

        // Exibir informações do produto
        printf("Produto encontrado: %s (R$ %.2f)\n", produtoEscolhido->produto, produtoEscolhido->preco);
        printf("Disponível em estoque: %d unidades\n", produtoEscolhido->estoque);

        // Solicitar quantidade
        printf("Digite a quantidade desejada: ");
        scanf("%d", &quantidade);

        // Validar se há estoque suficiente
        if (quantidade <= 0) {
            printf("Quantidade inválida. Tente novamente.\n");
        } else if (quantidade > produtoEscolhido->estoque) {
            printf("Estoque insuficiente. Apenas %d unidades disponíveis.\n", produtoEscolhido->estoque);
        } else {
            // Calcular o valor total
            float valorCompra = produtoEscolhido->preco * quantidade;
            valorTotal += valorCompra;
            produtoEscolhido->estoque -= quantidade; // Atualizar estoque

            printf("Produto adicionado ao carrinho: %s - Quantidade: %d - Subtotal: R$ %.2f\n", 
                   produtoEscolhido->produto, quantidade, valorCompra);
        }

        // Perguntar se deseja continuar
        printf("Deseja adicionar mais produtos? (S/N): ");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    printf("\n Calculo de compra finalizada. Valor total: R$ %.2f\n", valorTotal);
    return;
 
}

// Declaração de variáveis globais
Produto produtos[MAX_PRODUTOS];
Venda vendas[LIMIT_VENDAS];
// int numProdutos = 0;

// Transação

// Atualização do estoque


void fileCheck(){
    FILE *pFile;
    pFile = fopen("produtos.txt", "a");

    if (pFile == NULL)
    {
        printf("Erro ao abrir produto, criado um novo arquivo");
        FILE *pFile;
        pFile = fopen("produtos.txt", "w");
        return;
    }
}


int lerProdutosDeArquivo()
{
    FILE *arquivo = fopen("produtos.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s\n", "produtos.txt");
        return -1;
    }

    int i = 0;
    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        if (strncmp(linha, "--------------------------", 26) == 0)
        {
            continue;
        }
        if (strncmp(linha, "ID: ", 4) == 0)
        {
            sscanf(linha, "ID: %d", &produtos[i].id);

            fgets(linha, sizeof(linha), arquivo);
            sscanf(linha, "Produto: %49s", produtos[i].produto);

            fgets(linha, sizeof(linha), arquivo);
            sscanf(linha, "Categoria: %49s", produtos[i].categoria);

            fgets(linha, sizeof(linha), arquivo);
            sscanf(linha, "Validade: %10s", produtos[i].validade);

            fgets(linha, sizeof(linha), arquivo);
            sscanf(linha, "Preço: %f", &produtos[i].preco);

            fgets(linha, sizeof(linha), arquivo);
            sscanf(linha, "Quantidade no estoque: %d", &produtos[i].estoque);

            fgets(linha, sizeof(linha), arquivo);
            sscanf(linha, "valor da pesagem: %f", &produtos[i].valorPesagem);

            fgets(linha, sizeof(linha), arquivo);
            sscanf(linha, "tipo de pesagem: %14s", produtos[i].granel);

            // Avança para o próximo produto
            i++;
            if (i >= MAX_PRODUTOS)
            {
                printf("Limite máximo de produtos atingido.\n");
                break;
            }
        }
        if (i == 0)
        {
            printf("Nenhum produto foi lido do arquivo. Verifique o formato dos dados.\n");
        }
    }

    fclose(arquivo);
    return i;
}


// int lerProdutosDeArquivo()
// {
//     FILE *arquivo = fopen("produtos.txt", "r");
//     if (arquivo == NULL)
//     {
//         printf("Erro ao abrir o arquivo %s\n", "produtos.txt");
//         return -1;
//     }

//     int i = 0;
//     char linha[100];

//     while (fgets(linha, sizeof(linha), arquivo) != NULL)
//     {
//         if (strncmp(linha, "--------------------------", 26) == 0)
//         {
//             continue;
//         }
//         if (strncmp(linha, "ID: ", 4) == 0)
//         {
//             sscanf(linha, "ID: %d", &produtos[i].id);

//             fgets(linha, sizeof(linha), arquivo);
//             sscanf(linha, "Produto: %49s", produtos[i].produto);

//             fgets(linha, sizeof(linha), arquivo);
//             sscanf(linha, "Categoria: %49s", produtos[i].categoria);

//             fgets(linha, sizeof(linha), arquivo);
//             sscanf(linha, "Validade: %10s", produtos[i].validade);

//             fgets(linha, sizeof(linha), arquivo);
//             sscanf(linha, "Preço: %f", &produtos[i].preco);

//             fgets(linha, sizeof(linha), arquivo);
//             sscanf(linha, "Quantidade no estoque: %d", &produtos[i].estoque);

//             fgets(linha, sizeof(linha), arquivo);
//             sscanf(linha, "valor da pesagem: %f", &produtos[i].valorPesagem);

//             fgets(linha, sizeof(linha), arquivo);
//             sscanf(linha, "tipo de pesagem: %14s", produtos[i].granel);

//             // Avança para o próximo produto
//             i++;
//             if (i >= MAX_PRODUTOS)
//             {
//                 printf("Limite máximo de produtos atingido.\n");
//                 break;
//             }
//         }
//         if (i == 0)
//         {
//             printf("Nenhum produto foi lido do arquivo. Verifique o formato dos dados.\n");
//         }
//     }

//     fclose(arquivo);
//     return i;
// }


void transacaoPedido(){}
void menuCaixa(){
    int opcao;
    fileCheck();
    proxId = lerProdutosDeArquivo();
    numProdutos = proxId;
    setlocale(LC_ALL, "Portuguese");
    
    // idVendas = loadidByFile("vendas.txt");
    
    //printf("%d | %d", &id,&idVendas);

     // Display menu

    printf("\n   -----------------PDV Hortifruti caixa v0.2-----------------");
	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
	printf("\n   |         Bem vindo! Por favor, para começar,             |");
	printf("\n   |         selecione 1 para começar                        |");
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
        calculoDaCompra();
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
int loadId(Produto produtos[]){

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

void consultaPreco(){}

float calcularPrecoGranel(float precoPorKg, float peso) {
    return precoPorKg * peso;
}

void calcPesagem() {
    int idProduto;
    float peso;
    char continuar;

    
    int totalProdutos = MAX_PRODUTOS;
    
    printf("Bem-vindo à estação de pesagem!\n");

    do {
        // Solicitar ID do produto
        printf("\nDigite o ID do produto para pesagem: ");
        scanf("%d", &idProduto);

        // Procurar o produto na lista
        Produto *produtoEscolhido = NULL;
        for (int i = 0; i < totalProdutos; i++) {
            if (produtos[i].id == idProduto) {
                produtoEscolhido = &produtos[i];
                break;
            }
        }

        // Validar se o produto existe
        if (produtoEscolhido == NULL) {
            printf("Produto com ID %d não encontrado. Tente novamente.\n", idProduto);
            continue;
        }

        // Verificar se o produto é vendido a granel
        if (strcmp(produtoEscolhido->granel, "granel") != 0) {
            printf("O produto %s não é vendido a granel.\n", produtoEscolhido->produto);
            continue;
        }

        // Solicitar o peso
        printf("Digite o peso (em kg) para o produto %s: ", produtoEscolhido->produto);
        scanf("%f", &peso);

        // Validar se há peso suficiente em estoque
        if (peso <= 0) {
            printf("Peso inválido. Tente novamente.\n");
        } else if (peso > produtoEscolhido->valorPesagem) {
            printf("Estoque insuficiente. Apenas %.2f kg disponível.\n", produtoEscolhido->valorPesagem);
        } else {
            // Atualizar o estoque de peso
            produtoEscolhido->valorPesagem -= peso;
            printf("Produto %s pesado com sucesso! Peso registrado: %.2f kg\n", produtoEscolhido->produto, peso);

            // Calcular o preço
            float preco = calcularPrecoGranel(produtoEscolhido->preco, peso);
            printf("Preço total: R$ %.2f\n", preco);
        }

        // Perguntar se deseja continuar
        printf("Deseja pesar outro produto? (S/N): ");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');
}



void menuEstacao(){
    int opcao;

    fileCheck();
    proxId = lerProdutosDeArquivo();
    numProdutos = proxId;
    setlocale(LC_ALL, "Portuguese");

    // Display menu

    printf("\n   ------------------PDV Hortifruti v0.1 estação--------------");
	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
	printf("\n   |         Bem vindo! Por favor, selecione a opção 1       |");
    printf("\n   |         para começar                                    |");
	printf("\n   |         1. pesagem e cálculo do preço por peso          |");
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
        return ;
        
    default:
        printf("opção invalida.\n");
    } while (opcao != 0);

    return ;
   

    // Registro de vendas
    // Consulta de preço e listagem de produtos
    // calculo de preço e pesagem

}

// Função principal
int main() {
    int opt;
    setlocale(LC_ALL, "Portuguese");
   
    do {

        // escolher entre caixa e estação

    printf("\n   ---------------------PDV HortiMax v0.1------------------");
	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
	printf("\n   |         Por favor, escolha o tipo da aplicação          |");
	printf("\n   |         1. Estação                                      |");
	printf("\n   |         2. Caixa                                        |");
	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
	printf("\n   ---------------------PDV HortiMax v0.1-------------------");
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
