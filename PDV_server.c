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

    if (numProdutos >= MAX_PRODUTOS)
    {
        printf("Limite de produtos atingido.\n");
        return;
    }

    Produto novoProduto;
    novoProduto.id = proxId++;

    FILE *pFile;
    pFile = fopen("produtos.txt", "a");
    

    if (pFile == NULL) 
    {
        printf("Erro ao abrir produto");
        return;
    }


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

    
 
    fprintf(pFile,"--------------------------");
    fprintf(pFile,"\nID: %d\nProduto: %s\nCategoria: %s\nValidade: %s",novoProduto.id, novoProduto.produto, novoProduto.categoria, 
    novoProduto.validade);
    fprintf(pFile,"\nPreço: %.2f \nQuantidade no estoque: %d \nvalor da pesagem: %2.f \ntipo de pesagem: %s \n",novoProduto.preco, 
    novoProduto.estoque, novoProduto.valorPesagem, novoProduto.granel);


    produtos[numProdutos++] = novoProduto;
    printf("Produto adicionado com sucesso!\n");
    fclose(pFile);
}

// Função para listar produtos
void listarProdutos()
{
    
//arq
    FILE *pFile;
    pFile = fopen("produtos.txt", "r");
//val
    if (pFile == NULL){
        printf("Erro ao carregar o arquivo");
        return;
    }
//loadfile
    loadDataToProdutos();
    
    for (int i = 0; i < numProdutos; i++)
    {
        printf("ID: %d\nProduto: %s\nCategoria: %s\nValidade: %s",
               produtos[i].id, produtos[i].produto, produtos[i].categoria, produtos[i].validade);
        printf("\nPreço: %.2f \nQuantidade no estoque: %d \nvalor da pesagem: %2.f \ntipo de pesagem %s \n"
        ,produtos[i].preco, produtos[i].estoque, produtos[i].valorPesagem, produtos[i].granel);

    }
    //fclose
    return;
}

void returnProdutoById(){
        int id;
        printf("insira o id do produto");
        scanf("%i", &id);

        //arq
    FILE *pFile;
    pFile = fopen("produtos.txt", "r");
//val
    if (pFile == NULL){
        printf("Erro ao carregar o arquivo");
        return;
    }   

        printf("ID: %d\nProduto: %s\nCategoria: %s\nValidade: %s",
               produtos[id].id, produtos[id].produto, produtos[id].categoria, produtos[id].validade);
        printf("\nPreço: %.2f \nQuantidade no estoque: %d \nvalor da pesagem: %2.f \ntipo de pesagem %s \n"
        ,produtos[id].preco, produtos[id].estoque, produtos[id].valorPesagem, produtos[id].granel);

        

}

void returnProdutoByName(){
     char name[50];
        printf("\n insira o nome");
        scanf("%s",&name);
}

void buscarProduto(){

    int opcao;
    printf("Gostaria de buscar o produto pelo nome ou pelo id?\n(1)nome\n(2)id");
    scanf("%d",opcao);

    switch (opcao)
    {
    case 1:
        returnProdutoByName();
        break;
    case 2:
    
        returnProdutoById();
    default:
        break;
    }


   
}

void loadDataToProdutos(){

    int id;
    FILE *idFile;
    char content[1048];
    Produto rs;
    idFile = fopen("produtos.txt","r");
    if (idFile == NULL) {
            printf("Erro ao abrir o arquivo!");
            return;
    }
    fgets(content,1048,idFile);
    while (fscanf(idFile, "ID: %d", &id) == 1){
        id++;
        
        rs.id=id;
        // colunas

        produtos[id] = rs;
    }
    fclose(idFile);
}

void saveDataFromProdutos(Produto produtos[]){


    int id;
    FILE *pFile;
    pFile = fopen("produtos.txt", "w");

    int max = sizeof(produtos);

    while (id >= max){
        printf("%d",&id);
        id++;
        fprintf(pFile,"--------------------------");
        fprintf(pFile,"\nID: %d\nProduto: %s\nCategoria: %s\nValidade: %s",produtos[id].id, produtos[id].produto, produtos[id].categoria, 
        produtos[id].validade);
        fprintf(pFile,"\nPreço: %.2f \nQuantidade no estoque: %d \nvalor da pesagem: %2.f \ntipo de pesagem: %s \n",produtos[id].preco, 
        produtos[id].estoque, produtos[id].valorPesagem, produtos[id].granel);
     }
    printf("Produto adicionado com sucesso!\n");
    fclose(pFile);
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

            // modify
            FILE *fileProduto;
            fileProduto = fopen("produtos.txt","w");

            printf("Produto atualizado com sucesso!\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
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
            numProdutos--;
            printf("Produto deletado com sucesso!\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

int loadid(int id){
    int maxId=0;
    FILE *idFile;
    idFile = fopen("produtos.txt","a");
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

// Função principal
int main()
{
    int opcao, id=0;
    proxId = loadid(proxId);
    printf("%d",id);
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
        printf("\n   ----------------=Hortifruti PDV Server v0.2=---------------");
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
            break;
        default:
            printf("Opcao invalida.\n");
        }
    } while (opcao != 5);

    return 0;
}
