// Bibliotecas
// Bibliotéca para entrada e saida incluind fgets, printf, scanf
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// formatação da linguagem utilizada pt-br
#include <locale.h>

// Definindo a struct Produto
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

#define MAX_PRODUTOS 255

// Declaração de variáveis globais
Produto produtos[MAX_PRODUTOS];
int proxId = 1;
int numProdutos = 0;

// Função adicionar produto
void adicionarProduto()
{
    // Validação para evitar sobrecargar de buffer
    if (numProdutos >= MAX_PRODUTOS)
    {
        printf("Limite de produtos atingido.\n");
        return;
    }
    // Inicialização e auto incrementação do id
    Produto novoProduto;
    novoProduto.id = proxId++;

    // Inseração dos dados com printf e scanf
    printf("Digite o nome do produto: ");
    scanf("%s", &novoProduto.produto);

    printf("Digite a categoria do produto: ");
    scanf("%s", &novoProduto.categoria);

    printf("Digite a data de validade (DD-MM-AAAA): ");
    scanf("%s", &novoProduto.validade);

    // peso estoque e tipo
    printf("Digite o preço do produto: ");
    scanf("%f", &novoProduto.preco);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &novoProduto.estoque);

    printf("Digite o tipo de peso: ");
    scanf("%s", &novoProduto.granel);

    printf("Digite o valor do peso: ");
    scanf("%f", &novoProduto.valorPesagem);

    // inserção em array da lista
    produtos[numProdutos++] = novoProduto;
    printf("Produto adicionado com sucesso!\n");
}

// Função para listar produtos
void listarProdutos()
{
    for (int i = 0; i < numProdutos; i++)
    {
        printf("ID: %d\nProduto: %s\nCategoria: %s\nValidade: %s\n\n",
               produtos[i].id, produtos[i].produto, produtos[i].categoria, produtos[i].validade);
        printf("\n Preço: %f \n Quantidade no estoque: %d \n valor da pesagem: %f \n tipo de pesagem %s"
        ,produtos[i].preco, produtos[i].estoque, produtos[i].valorPesagem, produtos[i].granel);

    }
}

// Função para atualizar produto
void atualizarProduto(int id)
{
    for (int i = 0; i < numProdutos; i++)
    {
        if (produtos[i].id == id)
        {
            printf("Digite o novo nome do produto: ");
            scanf("%s", produtos[i].produto);

            printf("Digite a nova categoria do produto: ");
            scanf("%s", produtos[i].categoria);

            printf("Digite a nova data de validade (DD-MM-AAAA): ");
            scanf("%s", produtos[i].validade);

            printf("Digite um novo preço");
            scanf("%f", produtos[i].preco);

            printf("Digite um novo valor de estotque");
            scanf("%d", produtos[i].estoque);

            printf("DIgite um novo valor de pesagem");
            scanf("%f", produtos[i].valorPesagem);

            printf("Digite o tipo de Pesagem");
            scanf("%s", produtos[i].granel);

            printf("Produto atualizado com sucesso!\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

// Função para deletar produto
void deletarProduto(int id)
{
    for (int i = 0; i < numProdutos; i++)
    {
        if (produtos[i].id == id)
        {
            for (int j = i; j < numProdutos - 1; j++)
            {
                produtos[j] = produtos[j + 1];
            }
            numProdutos--;
            printf("Produto deletado com sucesso!\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

// Função principal
int main()
{
    int opcao, id;

    setlocale(LC_ALL, "Portuguese");
    do
    {
        printf("\n   ---------------------PDV Hortifruti v0.1------------------");
        printf("\n   |                                                         |");
        printf("\n   |                                                         |");
        printf("\n   |         MENU PRINCIPAL                                  |");
        printf("\n   |                                                         |");
        printf("\n   |                                                         |");
        printf("\n   |                                                         |");
        printf("\n   |         1-Adicionar produto                             |");
        printf("\n   |         2-Exibir lista de produtos                      |");
        printf("\n   |         3-Buscar produto                                |");
        printf("\n   |         4-Editar produto                                |");
        printf("\n   |         5-Apagar produto                                |");
        printf("\n   |         0-Encerrar aplicacao                            |");
        printf("\n   |                                                         |");
        printf("\n   |                                                         |");
        printf("\n   |                                                         |");
        printf("\n   |                                                         |");
        printf("\n   |                                                         |");
        printf("\n   |                                                         |");
        printf("\n   |                                                         |");
        printf("\n   |                                                         |");
        printf("\n   ---------------------PDV Hortifruti v0.1-------------------");
        printf("\n\n\n Por favor, digite uma opção:");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adicionarProduto();
            break;
        case 2:
            listarProdutos();
            break;
        case 3:
            printf("Digite o ID do produto a ser atualizado: ");
            scanf("%d", &id);
            atualizarProduto(id);
            break;
        case 4:
            printf("Digite o ID do produto a ser deletado: ");
            scanf("%d", &id);
            deletarProduto(id);
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida.\n");
        }
    } while (opcao != 5);

    return 0;
}
