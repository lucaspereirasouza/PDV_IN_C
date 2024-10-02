//Bibliotecas
// Bibliotéca para entrada e saida incluind fgets, printf, scanf
#include <stdio.h>
// formatação da linguagem utilizada pt-br
#include <locale.h>
// biblioteca para classe de strings
// Ferramentas de comparação de *chars[]
#include <string.h>
// biblioteca fundamental
#include <stdlib.h>
// biblioteca para utilização de intervalos
#include <time.h>

// define
#define NULO '\0'
#define TIME 500
#define LIMIT 100
// Entidade do produto
// Refatorar os updates

//Inicialização explicita de funções para evitar instancia implicita do compilador
void adicionar();
void buscar();
void listar();
void editar();
void apagar();

struct produto
{
	// Variaveis FILE para leitura e escritura de arquivos
	FILE *arq;
	FILE *arq_temp;
	FILE *arquivo_new;
	// id Auto incrementativo
	int id;
	// caracteristicas
	char nomeDoProduto[LIMIT];
	char Categoria[LIMIT];
	// valores -- colocar depois
	int valor_produto;
	int quant_atual;
	int estoque;

	// buscar
	char buscar_categoria[LIMIT];
	char buscar_Produto[LIMIT];
	// variavel para confirmar a criação
	char continuar[1];
	// viriavel para buscagem em lista
	char buscar[LIMIT];
	// variavel para seleção do menu
	int opcao;
	// variaveis de alteração para inserção do produto
	char alt_produto[LIMIT];
	char alt_categoria[LIMIT];
	// edição complementar para alterar
	char edit_produto;
	char edit_categoria[LIMIT];

} cadastro;
// inicializador de contador para contagem incrementativa
// valor estatico
int _id_STORAGE = NULO;
int main(void)
{
	// Inicialização com o cadastro
	// !! fazer depois abrir arquivo para leitura
	_id_STORAGE = cadastro.id;
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
		cadastro.opcao = 1;
		scanf("%d", &cadastro.opcao);

		// seleção de opções do menu
		switch (cadastro.opcao)
		{
		case 1:
			printf(" Processando...");
			nanosleep(TIME);
			system("clear");
			adicionar();
			break;
		case 2:
			printf(" Processando...");
			nanosleep(TIME);
			system("clear");
			listar();
			break;
		case 3:
			printf(" Processando...");
			nanosleep(TIME);
			system("clear");
			buscar();
			break;
		case 4:
			printf(" Processando...");
			nanosleep(TIME);
			system("clear");
			editar();
			break;
		case 5:
			printf(" Processando...");
			nanosleep(TIME);
			system("clear");
			// deletar();
		case 0:
			return 0;
		default:
			printf("\n\n [!]ERRO [!]"); // MENSAGEM DE ERRO PADRÃO
			printf("\n Desculpe,opção inválida.");
		}
	} while (cadastro.opcao != 0);
	{
		printf(" Processando...");
		nanosleep(TIME);
		printf("\n-------------VOLTE SEMPRE!!---------------"); // MENSAGEM DE SAÍDA DO PROGRAMA
	}
}
// CRUD

void adicionar()
{
	// Declaração e abertura do arquivo produtos
	cadastro.arq = fopen("produtos.txt", "a"); 

	do
	{
		//função limpar buffer input/output
		fflush(stdin); 

		printf("\nDigite o nome do produto:");
		if(scanf("%s", &cadastro.nomeDoProduto)==1 && cadastro.nomeDoProduto >=1){
		_id_STORAGE++;
		cadastro.id = _id_STORAGE;
		

		printf("Digite a categoria do produto:");
		scanf("%s", &cadastro.Categoria);
		

		
		printf("\n Confirmar? [S/N]:");
		scanf("%s", &cadastro.continuar);

		if (strcmp(cadastro.continuar, "S") == 0)
		{

			fprintf(cadastro.arq, "id do produto - %d:", cadastro.id);
			fprintf(cadastro.arq, "\n  Nome - %s\n", cadastro.nomeDoProduto); 
			fprintf(cadastro.arq, "produto - %s\n", cadastro.Categoria);
			fprintf(cadastro.arq, "\n-------------------------------\n");

			printf("Ok vamos continuar...");
			nanosleep(TIME);
			//
			cadastro.arq = fclose("produtos.txt");
			system("clear");
		}
		}else{
			
			return 1;
		}

	} while (strcmp(cadastro.continuar, "s") == 0);
	fclose(cadastro.arq);
	system("clear");
}

void listar()
{
	// Declaração e abertura do arquivo produtos para leitura "r"
	cadastro.arq = fopen("produtos.txt", "r");
	char listas[200];

	// Função para mostra na tela a lista
	while (fgets(listas, 200, cadastro.arq) != NULL)
	{
		printf("%s", listas); // printf p imprimir a lista na tela
	}
	fclose(cadastro.arq);
	
}

void buscar()
{
	// Contadores
	int counter_produto = 0;
	int counter_categoria = 0;

	// booleanos para validação
	int bol_produto;
	int bol_categoria;

	// char listas[200];
	cadastro.arq = fopen("produtos.txt", "r");
	printf("-----------------------------------------------------------------------\n");
	printf("|                       BUSCAR PRODUTO                                |\n");
	printf("-----------------------------------------------------------------------\n\n\n ");
	fflush(stdin);
	printf("Por favor,informe o nome do produto que deseja buscar:\n");

	fgets(cadastro.buscar_Produto, LIMIT, stdin);
	cadastro.buscar_Produto[strlen(cadastro.buscar) - 1] = 0;

	do
	{
		fgets(cadastro.nomeDoProduto, LIMIT, cadastro.arq);
		counter_produto++;
		if (strstr(cadastro.buscar_Produto, cadastro.nomeDoProduto) != NULL)
		{
			// printf("Linha %d: %s", j, cadastro.buscar);
			bol_produto = 1;
			break;
			// strcpy(pegar_nome,cadastro.nome);
			// achou1 = 1;
		}

	} while (!feof(cadastro.arq));
	rewind(cadastro.arq);
	printf("Por favor,informe a categoria do produto que deseja buscar:\n");
	fgets(cadastro.Categoria, LIMIT, stdin);
	cadastro.Categoria[strlen(cadastro.Categoria) - 1] = 0;
	do
	{
		fgets(cadastro.Categoria, LIMIT, cadastro.arq);
		counter_categoria++;
		if (strstr(cadastro.Categoria, cadastro.buscar_categoria) != NULL)
		{
			// printf("Linha %d: %s", j1, cadastro.buscar_profissao);
			// nao1 = j1;
			bol_categoria = 1;
			break;
			// strcpy(pegar_nome,cadastro.nome);
			// achou1 = 1;
		}
	} while (!feof(cadastro.arq));
	// rewind(cadastro.arq);
	if (bol_produto == 1 && bol_categoria == 1)
	{
		printf("\nFoi encontrado o funcionário !");
		printf("\nNome - %s", cadastro.buscar);
		printf("\nCategoria - %s", cadastro.buscar_categoria);
	}

	// counter_produto counter_categoria
	if (counter_produto != 1 && counter_categoria != 1)
	{
		printf("\nNão foi encontrado o produto!\n");
	}
	fclose(cadastro.arq);
	system("pause");
	system("clear");
}

void editar()
{
	// abertura de arquivos para leitura "r"
	cadastro.arq = fopen("produtos.txt", "r");
	// abertura para edição "w"
	cadastro.arq_temp = fopen("func_temp.txt", "w");

	//variaveis
	int alcan = 0;
	int pegar;
	int li;
	int linha = 1;
	int valida = 0;
	char nometrocar[LIMIT];

	printf("*-----------------------------------------------------------------------*\n");
	printf("|                         EDITAR PRODUTO                                |\n");
	printf("*-----------------------------------------------------------------------*\n\n\n ");

	rewind(cadastro.arq);
	fflush(stdin);
	printf("Digite a categoria que deseja alterar:");
	fgets(cadastro.alt_categoria, LIMIT, stdin);
	cadastro.alt_categoria[strlen(cadastro.alt_produto) - 1] = 0;
	do
	{
		fgets(cadastro.Categoria, 1000, cadastro.arq);
		alcan++;
		if (strstr(cadastro.Categoria, cadastro.alt_categoria) != NULL)
		{
			// printf("Linha %d: %s", bli, login.nome_trocar);
			pegar = alcan;
		}
	} while (!feof(cadastro.arq));
	rewind(cadastro.arq);

	printf("\nQual categoria gostaria de colocar no lugar?");
	fgets(cadastro.edit_categoria, LIMIT, stdin);
	// fflush(stdin);
	for (li = 0; !feof(cadastro.arq); li++)
	{
		memset(nometrocar, NULO, LIMIT);
		fgets(nometrocar, 101, cadastro.arq);
		if (linha == pegar)
		{
			fprintf(cadastro.arq_temp, "Categoria - %s", cadastro.edit_categoria);
			// fputs("", cadastro.arquivo_new);
			linha = linha + 1;
			valida = 1;
			continue;
		}
		linha = linha + 1;
		fputs(nometrocar, cadastro.arq_temp);
	}
	if (valida == 1)
	{
		printf("\nproduto alterada!\n");
	}
	if (valida == 0)
	{
		printf("\nproduto não alterada!\n");
	}
	if (valida == 1)
	{
		valida = 0;
	}
	fclose(cadastro.arq);
	fclose(cadastro.arq_temp);
	remove("produtos.txt");
	rename("func_temp.txt", "produtos.txt");
	system("pause");
	system("clear");
}
void apagar()
{
	int alcan = 0;
	int pegar;
	int li;
	int linha = 1;
	int valida = 0;
	char nometrocar[LIMIT];
	cadastro.arq = fopen("produtos.txt", "r");
	cadastro.arq_temp = fopen("func_temp.txt", "w");

	printf("-----------------------------------------------------------------------\n");
	printf("|                        APAGAR CADASTRO                                |\n");
	printf("-----------------------------------------------------------------------\n\n ");
	printf("\n\n Digite o nome do produto que deseja apagar o cadastro: \n");
	fgets(cadastro.alt_produto, LIMIT, stdin);

	if (linha == pegar)
	{
		fputs("", cadastro.arquivo_new);
		linha = linha + 1;
		valida = 1;
	}
	linha = linha + 1;
	fputs(cadastro.alt_produto, cadastro.arq_temp);

	if (valida == 1)
	{
		printf("\n Cadastro apagado!!\n");
	}
	if (valida == 0)
	{
		printf("\nCadastro não apagado\n");
	}
	if (valida == 1)
	{
		valida = 0;
	}

	fclose(cadastro.arq);
	fclose(cadastro.arq_temp);
	remove("produtos.txt");
	rename("func_temp.txt", "produtos.txt");
	system("pause");
	system("clear");
}