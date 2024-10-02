                             //BIBLIOTECAS DECLARADAS
#include<stdio.h>
#include<locale.h>
#include<string.h> 
#include<stdlib.h>
#include<unistd.h>

#define NULO '\0'
#define TIME 500
#define LIMIT 100
// Entidade do produto
// Refatorar os updates

void adicionar();
void listaProdutos();
void buscar();
void listar();
void editar();
void apagar();


struct produto{
	
	FILE *arq;
    FILE *arq_temp;
	FILE *arquivo_new;
    
    int id;
	char nomeDoProduto[LIMIT];
	char Categoria[LIMIT];
    // inserir e validar a quantidade
	int valor_produto;
    int quant_atual;
    int estoque;

    // buscar
    char buscar_categoria[LIMIT];
    char buscar_Produto[LIMIT];
    //Continue
    char continuar[1];
	// search
    char buscar[LIMIT];
    // opcao
    int opcao;
	//alts
	char alt_produto[LIMIT];
	char alt_categoria[LIMIT];
	//editions variables
	char edit_produto;
	char edit_categoria[LIMIT];
	


}cadastro;
int _id_STORAGE = 0;
int main(void){
	
	setlocale(LC_ALL,"Portuguese");
	
	do{
	
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
	scanf("%d",&cadastro.opcao);
	
	                          // ESTRUTURA SWITCH P/AS OPÇÕES DE CADASTRO
	switch(cadastro.opcao){    
		case 1:
			printf(" Processando...");
			sleep(TIME);
			system("clear");
			adicionar();
	    	break;
	    case 2:
	        printf(" Processando...");
			sleep(TIME);
			system("clear");
			listar();
	    	break;
	    case 3:
	        printf(" Processando...");
			sleep(TIME);
			system("clear");
			buscar();
	        break;
	    case 4:
	        printf(" Processando...");
			sleep(TIME);
			system("clear");
			editar();
	        break;
	    case 5:
	    	printf(" Processando...");
			sleep(TIME);
			system("clear");
			// deletar();
	    case 0:
	        return 0;   		
	    default:
	        printf("\n\n [!]ERRO [!]");                      //MENSAGEM DE ERRO PADRÃO
	    	printf("\n Desculpe,opção inválida.");
	}}while(cadastro.opcao!=0);{
   printf(" Processando...");
   sleep(1000);
   printf("\n-------------VOLTE SEMPRE!!---------------"); //MENSAGEM DE SAÍDA DO PROGRAMA
}
}
// crud

void adicionar(){

	cadastro.arq = fopen("produtos.txt", "a"); //DECLARAÇÃO DO ARQUIVO PARA ARMAZENAR OS DADOS DO CADASTRO
	
	do{
		// fflush(stdin); //função p limpar o buffer de saída/entrada
		
        printf("\nDigite o nome do produto:");
		scanf("%s", &cadastro.nomeDoProduto);

		if(!cadastro.nomeDoProduto=="")
		




		_id_STORAGE++;
		cadastro.id = _id_STORAGE;
		fprintf(cadastro.arq, "id do produto - %d:", cadastro.id);
		fprintf(cadastro.arq, "\n  Nome - %s\n", cadastro.nomeDoProduto);//COMANDO P ARMAZENAMENTO NO ARQUIVO
		
        
		
        printf("Digite a categoria do produto:");
		scanf("%s", &cadastro.Categoria);
		fprintf(cadastro.arq, "produto - %s\n", cadastro.Categoria);

		fprintf(cadastro.arq,"\n-------------------------------\n"); //organizar o arquivo
		printf("\nQuer continuar? [S/N]:");
		gets(cadastro.continuar);
	
		if(strcmp(cadastro.continuar,"s") == 0){
           	

            // increment


			printf("Ok vamos continuar...");
			system ("clear");
		}
		
	}while(strcmp(cadastro.continuar,"s") == 0);
	fclose(cadastro.arq);
	system ("clear");
}

void listarProdutos(){
	
cadastro.arq = fopen("func.txt", "r");
char listas[200];


while(fgets(listas,200,cadastro.arq)!=NULL){ 
	printf("%s",listas); //printf p imprimir a lista na tela
}
fclose(cadastro.arq);
system("pause"); 
system ("clear");
}

void buscar(){
    // Counters
	int counter_produto = 0;
	int counter_categoria = 0;

	// Bools
    int bol_produto;
	int bol_categoria;
 
	//char listas[200];

	cadastro.arq = fopen("func.txt", "r");
	printf("-----------------------------------------------------------------------\n");
	printf("|                       BUSCAR PRODUTO                                |\n");
	printf("-----------------------------------------------------------------------\n\n\n ");
	fflush(stdin);
	printf("Por favor,informe o nome do produto que deseja buscar:\n");

	fgets(cadastro.buscar_Produto, LIMIT, stdin);    

	cadastro.buscar_Produto[strlen(cadastro.buscar) -1] = 0;  

	do{
		fgets(cadastro.nomeDoProduto, LIMIT, cadastro.arq);        
		counter_produto++;
		if(strstr(cadastro.buscar_Produto, cadastro.nomeDoProduto) != NULL){
			//printf("Linha %d: %s", j, cadastro.buscar);
			bol_produto = 1;
			break; 
			//strcpy(pegar_nome,cadastro.nome);           
			//achou1 = 1;        
		}	
        		    
	}while(!feof(cadastro.arq));
	rewind(cadastro.arq);
	printf("Por favor,informe a categoria do produto que deseja buscar:\n");
	fgets(cadastro.Categoria, LIMIT, stdin);    
	cadastro.Categoria[strlen(cadastro.Categoria) -1] = 0;  
	do{
		fgets(cadastro.Categoria, LIMIT, cadastro.arq);        
		counter_categoria++;        
		if(strstr(cadastro.Categoria, cadastro.buscar_categoria) != NULL){
			//printf("Linha %d: %s", j1, cadastro.buscar_profissao);
			//nao1 = j1;
            bol_categoria = 1; 
			break; 
			//strcpy(pegar_nome,cadastro.nome);           
			//achou1 = 1;        
		}				    
	}while(!feof(cadastro.arq));
	// rewind(cadastro.arq);
	if(bol_produto == 1 && bol_categoria == 1){
		printf("\nFoi encontrado o funcionário !");
		printf("\nNome - %s", cadastro.buscar);
		printf("\nCategoria - %s", cadastro.buscar_categoria);

	}
	
    // counter_produto counter_categoria
	if(counter_produto != 1 && counter_categoria != 1){
		printf("\nNão foi encontrado o produto!\n");	
	}
	fclose(cadastro.arq);
	system("pause"); 
	system ("clear");
}
void listar(){
	
cadastro.arq = fopen("func.txt", "r");
int i;
char listas[200];


while(fgets(listas,200,cadastro.arq)!=NULL){ 

	printf("%s",listas); //printf p imprimir a lista na tela

}
fclose(cadastro.arq);
system("pause"); 
system ("clear");
}



void editar(){

	cadastro.arq = fopen("func.txt", "r");
	cadastro.arq_temp = fopen("func_temp.txt", "w");
	
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
	cadastro.alt_categoria[strlen(cadastro.alt_produto) -1] = 0;    
	do{
		fgets(cadastro.Categoria, 1000, cadastro.arq);        
		alcan++;        
		if(strstr(cadastro.Categoria, cadastro.alt_categoria) != NULL){
		//printf("Linha %d: %s", bli, login.nome_trocar);
		pegar = alcan;         
	}				    
	}while(!feof(cadastro.arq));
	rewind(cadastro.arq);
	
	printf("\nQual categoria gostaria de colocar no lugar?");
	fgets(cadastro.edit_categoria, LIMIT, stdin); 
	//fflush(stdin);
	for(li = 0; !feof(cadastro.arq);li++){
	memset(nometrocar, NULO, LIMIT); 
	fgets(nometrocar, 101, cadastro.arq);
	if(linha == pegar){
		fprintf(cadastro.arq_temp, "Categoria - %s", cadastro.edit_categoria); 
		//fputs("", cadastro.arquivo_new); 
		linha = linha + 1; 
		valida = 1;
		continue; 
	}
	linha = linha + 1; 
	fputs(nometrocar, cadastro.arq_temp);
	}
	if(valida == 1){
		printf("\nproduto alterada!\n");
	}
	if(valida == 0){
		printf("\nproduto não alterada!\n");
	}	
	if(valida == 1){
		valida = 0;
	}
	fclose(cadastro.arq); 
	fclose(cadastro.arq_temp); 
	remove("func.txt");
	rename("func_temp.txt", "func.txt");
	system("pause"); 
	system ("clear");
	}
void apagar(){
	int alcan = 0;
	int pegar;
	int li;
	int linha = 1;
	int valida = 0;
	char nometrocar[LIMIT];
	cadastro.arq = fopen("func.txt", "r");
    cadastro.arq_temp = fopen("func_temp.txt", "w");

printf("-----------------------------------------------------------------------\n");
printf("|                        APAGAR CADASTRO                                |\n");
printf("-----------------------------------------------------------------------\n\n ");
printf("\n\n Digite o nome do produto que deseja apagar o cadastro: \n");
fgets(cadastro.alt_produto, LIMIT, stdin);

if(linha == pegar){
fputs("", cadastro.arquivo_new); 
linha = linha + 1; 
valida = 1;
}
linha = linha + 1; 
fputs(cadastro.alt_produto, cadastro.arq_temp);
	
if(valida == 1){
printf("\n Cadastro apagado!!\n");
}
if(valida == 0){
printf("\nCadastro não apagado\n");
}	
if(valida == 1){
valida = 0;
}

fclose(cadastro.arq); 
fclose(cadastro.arq_temp); 
remove("func.txt");
rename("func_temp.txt", "func.txt");
system("pause");
system("clear");
}