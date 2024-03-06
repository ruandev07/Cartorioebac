#include <stdio.h> //Biblioteca de comunica��o com usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings


int registro()
{
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		
		printf("Digite o CPF a ser cadastrado: ");
		scanf("%s", cpf);
		
		strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
		
		FILE *file; // cria o arquivo
		file = fopen(arquivo, "w"); // cria o arquivo
		fprintf(file,cpf); // salvo o valor da vareavel
		fclose(file); // fechar o arquivo
		
		file = fopen(arquivo, "a"); // "a" pra atualizar
		fprintf(file,", ");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s",nome);
		
		file = fopen(arquivo, "a");
		fprintf(file, nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,", ");
		fclose(file);
		
		printf("digite o sobrenome a ser cadastrado: ");
		scanf("%s",sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file,", ");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s",cargo);
			
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		system("pause");
	
		
}

int consultar()
{
		setlocale(LC_ALL,"Portuguese");//Definindo a linguagem
		
		char cpf[40];
		char conteudo[200];
		
		printf("Digite o CPF a ser consultado: ");
		scanf("%s",cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
		}
			
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas s�o as informac�es do usuario: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
			
		system("pause");
	
	
}

int deletar()
{
	printf("voc� escolheu deletar nomes!\n");
	system("pause");
}

int main()
   {
	int opcao=0; //Definindo variaveis
	int laco=0;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); // op��o para limpar a tela.
		
		setlocale(LC_ALL,"Portuguese");//Definindo a linguagem
		
		printf("### Cartorio da EBAC ###\n\n"); // inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registra nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o:"); // fim do menu
		
		scanf("%d", &opcao); // armazenar as escolhas do usuario.
		
		system("cls"); // op��o para limpar a tela.
		
		
		switch(opcao) // inicio de selec�o
		{
			case 1:
			registro();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o esta disponive!\n");
			system("pause");
			break;
			//fim da sele��o
		}
				
    } 
				 
 }