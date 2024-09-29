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

