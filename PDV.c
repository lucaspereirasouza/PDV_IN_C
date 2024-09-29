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

}cadastro;

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
