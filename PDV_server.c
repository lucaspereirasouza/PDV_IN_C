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

// Função adicionar produto
void adicionarProduto()
{

    if (numProdutos >= MAX_PRODUTOS)
    {
        printf("Limite de produtos atingido.\n");
        return;
    }

    Produto novoProduto;

    FILE *pFile;
    pFile = fopen("produtos.txt", "a");

    if (pFile == NULL)
    {
        printf("Erro ao abrir produto");
        return;
    }

    novoProduto.id = ++proxId;
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

    fprintf(pFile, "--------------------------");
    fprintf(pFile, "\nID: %d\nProduto: %s\nCategoria: %s\nValidade: %s", novoProduto.id, novoProduto.produto, novoProduto.categoria,
            novoProduto.validade);
    fprintf(pFile, "\nPreço: %.2f \nQuantidade no estoque: %d \nvalor da pesagem: %2.f \ntipo de pesagem: %s \n", novoProduto.preco,
            novoProduto.estoque, novoProduto.valorPesagem, novoProduto.granel);

    produtos[numProdutos++] = novoProduto;
    printf("\n\nProduto adicionado com sucesso!\n");
    fclose(pFile);
    return;
}

// Função para listar produtos
void listarProdutos()
{
    FILE *pFile;
    pFile = fopen("produtos.txt", "r");
    if (pFile == NULL)
    {
        printf("Erro ao carregar o arquivo");
        return;
    }
    lerProdutosDeArquivo();

    for (int i = 0; i < proxId; i++)
    {
        printf("ID: %d\nProduto: %s\nCategoria: %s\nValidade: %s",
               produtos[i].id, produtos[i].produto, produtos[i].categoria, produtos[i].validade);
        printf("\nPreço: %.2f \nQuantidade no estoque: %d \nvalor da pesagem: %2.f \ntipo de pesagem %s \n\n", produtos[i].preco, produtos[i].estoque, produtos[i].valorPesagem, produtos[i].granel);
        
    }
    // fclose
    fclose(pFile);
    return;
}

void returnProdutoById()
{
    int id;
    printf("insira o id do produto: 12");
    scanf("%i", &id);
    
    if (id<=0){
        printf("id invalido");
        return;
    }
    
    id--;

    // arq
    FILE *pFile;
    pFile = fopen("produtos.txt", "r");
    // val
    if (pFile == NULL)
    {
        printf("Erro ao carregar o arquivo");
        return;
    }

    printf("ID: %d\nProduto: %s\nCategoria: %s\nValidade: %s",
           produtos[id].id, produtos[id].produto, produtos[id].categoria, produtos[id].validade);
    printf("\nPreço: %.2f \nQuantidade no estoque: %d \nvalor da pesagem: %2.f \ntipo de pesagem %s \n", produtos[id].preco, produtos[id].estoque, produtos[id].valorPesagem, produtos[id].granel);

    fclose(pFile);
}

int fmin(int a, int b) {
    return (a < b) ? a : b;
}

void returnProdutoByName()
{
    int id;
    char name[50];
    printf("\n insira o nome: ");
    scanf("%s", &name);

    for (size_t i = 0; i < proxId; i++)
    {
        if (strcmp(name, produtos[i].produto) == 0)
        {
            produtos[i].id = id;
            break;
        }
    }


    if (id==0){
        printf("nome não encontrado");
        return;
    }

    printf("ID: %d\nProduto: %s\nCategoria: %s\nValidade: %s",
           produtos[id].id, produtos[id].produto, produtos[id].categoria, produtos[id].validade);
    printf("\nPreço: %.2f \nQuantidade no estoque: %d \nvalor da pesagem: %2.f \ntipo de pesagem %s \n", produtos[id].preco, produtos[id].estoque, produtos[id].valorPesagem, produtos[id].granel);
}

void buscarProduto()
{

    int opcao;
    printf("Gostaria de buscar o produto pelo nome ou pelo id?\n(1) id\n(2) nome\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        returnProdutoById();
        break;
    case 2:
        returnProdutoByName();
        break;
    default:
        break;
    }
}


void saveDataFromProdutos()
{
    int id=0;
    FILE *pFile;
    pFile = fopen("produtos.txt", "w");

    int max = sizeof(produtos) / sizeof(produtos[0]);

    printf("%d", max);
    for (int id = 0; id < proxId; id++)
    {
        // printf("%d", &id);
        fprintf(pFile, "--------------------------");
        fprintf(pFile, "\nID: %d\nProduto: %s\nCategoria: %s\nValidade: %s", id+1, produtos[id].produto, produtos[id].categoria,
                produtos[id].validade);
        fprintf(pFile, "\nPreço: %.2f \nQuantidade no estoque: %d \nvalor da pesagem: %2.f \ntipo de pesagem: %s \n", produtos[id].preco,
                produtos[id].estoque, produtos[id].valorPesagem, produtos[id].granel);
    }
    printf("Produto adicionado com sucesso!\n");
    fclose(pFile);
    return;
}

// Função para atualizar produto
void atualizarProduto()
{
    int id;
    printf("Digite o ID do produto a ser atualizado: ");
    scanf("%d", &id);
    for (int i = 0; i < numProdutos; i++)
    {
        if (produtos[i].id == id)
        {
            printf("Digite o novo nome do produto: ");
            scanf("%s", &produtos[i].produto);

            printf("Digite a nova categoria do produto: ");
            scanf("%s", &produtos[i].categoria);

            printf("Digite a nova data de validade (DD-MM-AAAA): ");
            scanf("%s", &produtos[i].validade);

            printf("Digite um novo preço");
            scanf("%f", &produtos[i].preco);

            printf("Digite um novo valor de estotque");
            scanf("%d", &produtos[i].estoque);

            printf("DIgite um novo valor de pesagem");
            scanf("%f", &produtos[i].valorPesagem);

            printf("Digite o tipo de Pesagem");
            scanf("%s", &produtos[i].granel);

            printf("Produto atualizado com sucesso!\n");
            
        }
    }
    saveDataFromProdutos();
    return;
    
}

// Função para deletar produto
void deletarProduto()
{
    int id;
    printf("Digite o ID do produto a ser deletado: ");
    scanf("%d", &id);

    for (int i = 0; i < numProdutos; i++)
    {
        if (produtos[i].id == id)
        {
            for (int j = i; j < numProdutos - 1; j++)
            {
                produtos[j] = produtos[j + 1];
            }
            
            printf("Produto deletado com sucesso!\n");
            saveDataFromProdutos();
            break;
        }
    }

    
    printf("Produto não encontrado.\n");
    return;
}

int main()
{
    int opcao;
    fileCheck();
    proxId = lerProdutosDeArquivo();
    numProdutos = proxId;
    setlocale(LC_ALL, "Portuguese");
    do
    {
        printf("\n   -----------------------------------------------------------");
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
        printf("\n   ----------------=HortiMax PDV Server v0.3=---------------");
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
            buscarProduto();
            break;
        case 4:
            atualizarProduto();
            break;
        case 5:
            deletarProduto();
            break;
        case 0:
            printf("Saindo...\n");
            // teste para sair da aplicação
            return 0;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    } while (opcao != 6);

    return 0;
}
