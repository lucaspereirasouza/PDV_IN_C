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
