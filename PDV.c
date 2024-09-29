struct produto{
	
	FILE *arq;
    FILE *arq_temp;
	FILE *arquivo_new;
    
    int id;
	char nomeDoProduto[100];
	char Categoria[100];
    // inserir e validar a quantidade
	int valor_produto;
    int quant_atual;
    int estoque;

    // buscar
    char buscar_categoria[100];
    char buscar_Produto[100];
    //Continue
    char continuar[1];
	// search
    char buscar[100];
    // opcao
    int opcao;
	//alts
	char alt_produto[100];
	char alt_categoria[100];
	//editions variables
	char edit_produto;
	char edit_categoria[100];

}cadastro;
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
	scanf("%d",&cadastro.opcao);
	
	
	                          // ESTRUTURA SWITCH P/AS OPÇÕES DE CADASTRO
	switch(cadastro.opcao){    
		case 1:
			printf(" Processando...");
			Sleep(2000);
			system("clear");
			adicionar();
	    	break;
	    case 2:
	        printf(" Processando...");
			Sleep(2000);
			system("clear");
			listar();
	    	break;
	    case 3:
	        printf(" Processando...");
			Sleep(2000);
			system("clear");
			buscar();
	        break;
	    case 4:
	        printf(" Processando...");
			Sleep(2000);
			system("clear");
			editar();
	        break;
	    case 5:
	    	printf(" Processando...");
			Sleep(2000);
			system("clear");
			deletar();
	    case 0:
	        
	        break;
	                		
	    default:
	        printf("\n\n [!]ERRO [!]");                      //MENSAGEM DE ERRO PADRÃO
	    	printf("\n Desculpe,opção inválida.");
	}}while(cadastro.opcao!=0);{
   printf(" Processando...");
   Sleep(1000);
   printf("\n-------------VOLTE SEMPRE!!---------------"); //MENSAGEM DE SAÍDA DO PROGRAMA
}

void adicionar(){
    int _id_STORAGE = 0;
	cadastro.arq = fopen("produtos.txt", "a"); //DECLARAÇÃO DO ARQUIVO PARA ARMAZENAR OS DADOS DO CADASTRO
	
	do{
		fflush(stdin); //função p limpar o buffer de saída/entrada
		
        printf("Digite o nome do produto:");
		gets(cadastro.nomeDoProduto);


		if(cadastro.nomeDoProduto)

		fprintf(cadastro.arq, "Nome - %s\n", cadastro.nomeDoProduto);//COMANDO P ARMAZENAMENTO NO ARQUIVO
		
        printf("Digite a categoria do produto:");
		gets(cadastro.Categoria);
		fprintf(cadastro.arq, "Profissão - %s\n", cadastro.Categoria);

		fprintf(cadastro.arq,"\n-------------------------------\n"); //organizar o arquivo
		printf("\nQuer continuar? [S/N]:");
		gets(cadastro.continuar);
	
		if(strcmp(cadastro.continuar,"s") == 0){
           	_id_STORAGE++;
            cadastro.id = _id_STORAGE;

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
	//
    int j2 = 0;

	// Bools
    int bol_produto;
	int bol_categoria;


    // teste
	int teste;
 
	//char listas[200];

	cadastro.arq = fopen("func.txt", "r");
	printf("-----------------------------------------------------------------------\n");
	printf("|                       BUSCAR PRODUTO                                |\n");
	printf("-----------------------------------------------------------------------\n\n\n ");
	fflush(stdin);
	printf("Por favor,informe o nome do produto que deseja buscar:\n");

	fgets(cadastro.buscar_Produto, 100, stdin);    

	cadastro.buscar[strlen(cadastro.buscar) -1] = 0;  

	do{
		fgets(cadastro.nomeDoProduto, 100, cadastro.arq);        
		counter_produto++;        
		if(strstr(cadastro.nomeDoProduto, cadastro.nomeDoProduto) != NULL){
			//printf("Linha %d: %s", j, cadastro.buscar);
			bol_produto = 1;
			break; 
			//strcpy(pegar_nome,cadastro.nome);           
			//achou1 = 1;        
		}	
        		    
	}while(!feof(cadastro.arq));
	rewind(cadastro.arq);
	printf("Por favor,informe a categoria do produto que deseja buscar:\n");
	fgets(cadastro.Categoria, 100, stdin);    
	cadastro.Categoria[strlen(cadastro.Categoria) -1] = 0;  
	do{
		fgets(cadastro.Categoria, 1000, cadastro.arq);        
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

void buscar(){
cadastro.arq = fopen("func.txt", "rb");


printf("*-----------------------------------------------------------------------*\n");
printf("|                       BUSCAR FUNCIONÁRIO                              |\n");
printf("*-----------------------------------------------------------------------*\n\n\n ");
printf("Por favor,informe o nome do funcionário que deseja buscar:\n");
fflush(stdin);
scanf("%s",cadastro.buscar);

// exibir categoria
	printf("\n   ----------------------------------------------------------");
	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
	printf("\n   |                     Oque deseja editar                  |");
	printf("\n   |                     do produto?                         |");
	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
	printf("\n   |         1-Cadastrar                                     |");
	printf("\n   |         2-Exibir lista de produtos                      |");
	printf("\n   |         3-Buscar funcionário                            |");
	printf("\n   |         4-Editar produto                                |");
	printf("\n   |         5-Apagar cadastro                               |");
	printf("\n   |         0-Encerrar sessão                               |");
	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
 	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
	printf("\n   |                                                         |");
	printf("\n   | Programadora: Brenda Beato                              |");
	printf("\n   -------------------T.I ENTERPRISES-----------------------");
	printf("\n\n\n Por favor, digite uma opção:");
	scanf("%d",&cadastro.opcao);



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
	char nometrocar[100];
	
   printf("*-----------------------------------------------------------------------*\n");
   printf("|                         EDITAR PRODUTO                                |\n");
   printf("*-----------------------------------------------------------------------*\n\n\n ");
	
	
	
	
	rewind(cadastro.arq);
	fflush(stdin);
	printf("Digite a profissão que deseja alterar:");
	fgets(cadastro.alt_produto, 100, stdin);    
	cadastro.alt_profi[strlen(cadastro.alt_profi) -1] = 0;    
	do{
		fgets(cadastro.profissao, 1000, cadastro.arq);        
		alcan++;        
		if(strstr(cadastro.profissao, cadastro.alt_profi) != NULL){
		//printf("Linha %d: %s", bli, login.nome_trocar);
		pegar = alcan;         
	}				    
	}while(!feof(cadastro.arq));
	rewind(cadastro.arq);
	
	printf("\nQual profissão gostaria de colocar no lugar?");
	fgets(cadastro.tra_profi, 100, stdin); 
	//fflush(stdin);
	for(li = 0; !feof(cadastro.arq);li++){
	memset(nometrocar, NULO, 100); 
	fgets(nometrocar, 101, cadastro.arq);
	if(linha == pegar){
		fprintf(cadastro.arq_temp, "Profissão - %s", cadastro.tra_profi); 
		//fputs("", cadastro.arquivo_new); 
		linha = linha + 1; 
		valida = 1;
		continue; 
	}
	linha = linha + 1; 
	fputs(nometrocar, cadastro.arq_temp);
	}
	if(valida == 1){
		printf("\nProfissão alterada!\n");
	}
	if(valida == 0){
		printf("\nProfissão não alterada!\n");
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
	char nometrocar[100];
	cadastro.arq = fopen("func.txt", "r");
    cadastro.arq_temp = fopen("func_temp.txt", "w");

printf("-----------------------------------------------------------------------\n");
printf("|                        APAGAR CADASTRO                                |\n");
printf("-----------------------------------------------------------------------\n\n ");
printf("\n\n Digite o nome do funcionário que deseja apagar o cadastro: \n");
fgets(cadastro.alt_profi, 100, stdin);

if(linha == pegar){
fputs("", cadastro.arquivo_new); 
linha = linha + 1; 
valida = 1;
}
linha = linha + 1; 
fputs(cadastro.alt_profi, cadastro.arq_temp);
	
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
