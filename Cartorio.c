#include <stdio.h> //Biblioteca de comunicação com usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocação de texto por região
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
			printf("Não foi possivel abrir o arquivo, não localizado!.\n");
		}
			
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas são as informacões do usuario: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
			
		system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
		
		
	
	FILE *file;	
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		FILE *file;	
		file = fopen(cpf,"r");
		if(file == NULL)
		{
			printf("Usuário deletado com sucesso!.\n");
			system("pause");
		}
	}
	fclose(file);
	
}

int main()
   {
	int opcao=0; //Definindo variaveis
	int laco=0;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartorio da EBAC ###\n\n");
	printf("login de administrador!\n\nDigite a sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
	    system ("cls");
		for(laco=1;laco=1;)
		{
			
			system("cls"); // opção para limpar a tela.
			
			setlocale(LC_ALL,"Portuguese");//Definindo a linguagem
		
			printf("### Cartorio da EBAC ###\n\n"); // inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registra nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - sair do sistema\n\n"); 
			printf("Opção:"); // fim do menu
				
			scanf("%d", &opcao); // armazenar as escolhas do usuario.
		
			system("cls"); // opção para limpar a tela.
		
		
				switch(opcao) // inicio de selecão
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
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
			
				default:
				printf("Essa opção não esta disponive!\n");
				system("pause");
				break;
				//fim da seleção
			}
    	}					 
	}
	
	else
		printf("Senha incorreta");
    
 }
