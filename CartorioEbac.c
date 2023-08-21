#include <stdio.h> //biblioteca de  comunicaçao com o usuario
#include <stdlib.h>//biblioteca de alocaçao de espaço em memoria
#include <locale.h>//bibliotecq de alocações de texto por regiao
#include <string.h>

int registro()    //função responsavel por cadastrar os uduarios no sistema

{   	
   	setlocale(LC_ALL, "Portuguese_Brasil");//Definindo o edioma
    //inicio criacao de variaveis/strings e quantidade de caracteres
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];     //fim cricao de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado:"); //Coletando informacoes dos usuarios
	scanf("%s", &cpf);      // Le a entrada do usuario e armazena na variavel "cpf"
	
	strcpy(arquivo, cpf);    //Responsavel por copiar os valores das string para arquivo
	
	FILE *file;    //Cria o arquivo 
	file = fopen(arquivo, "w");    // Cria o arquivo e "w" significa escrever
	fprintf(file,"\nCPF:");
	fprintf(file, cpf);    //salva o valor da variavel
	fclose(file);    // fecha arquivo
	
	file = fopen(arquivo,"a"); // "a" usado para atualizar
	fprintf(file,"\nNOME:");    // Escreve uma virgula no arquivo, para separar os dados
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");     //Coletando informacoes dos usuarios
	scanf("%s", &nome);    // Le a entrada do usuario e armazena na variavel "nome"
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
    file = fopen(arquivo,"a"); 
	fprintf(file,"\nSOBENOME:");    
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", &sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
    file = fopen(arquivo,"a"); 
	fprintf(file,"\nCARGO:");    
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", &cargo);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, cargo);
	fprintf(file,"\n\n"); 
	fclose(file);
	
	system("pause");	// Pausa o programa para o usuario ler a mensagem
	
}
int consulta()     //inicio da funcao consulta atraves do cpf
{
	setlocale(LC_ALL, "Portuguese_Brasil");//Definindo o edioma
	
    char cpf[40];
    char conteudo[200];
    
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    
    {
    	printf("Aquivo não localizao!.\n");
	} else
	printf("\nEssas são as informações do usuário:\n");
	
	while(fgets(conteudo, 200, file) != NULL)
	
	{
		printf("%s", conteudo);
	}
	
	fclose(file);
	system("pause");
	
}
int deletar()
{
	
	char cpf[40];
	
	printf("Digite o CPF a ser cadastrado: \n");
	scanf("%s,",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)   
	{
		printf("Excluido com sucesso!\n");
	    system("pause");
	}

}

int main()
{
   setlocale(LC_ALL, "Portuguese_Brasil");//Definindo o edioma
   
    int opcao = 0;    //Definindo variavel
    int laco=1;    // definindo variavel para repeticao loop

    for (laco=1;laco=1;)    // repeticao "para volta ao inicio do menu"
    {

      system("cls");    // responsavel por limpar a tela

      printf("### Cartorio da EBAC ###\n\n");//inicio do menu
      printf("Escolha a opção desejada do menu\n\n");
      printf("\t1 - Registrar nomes\n");
      printf("\t2 - Consulta nomes\n");
      printf("\t3 - Deletar nomes\n");
      printf("Opção:");//fim do menu

      scanf("%d",&opcao);//armazenando escolha do usuario

      system("cls");//Limpa a tela

      switch (opcao) //inicio da selecao
      {
           case 1:    // Caso o valor de "opcao" seja 1
           registro();    // Chama a funcao "registro"
           break;    // Encerra o caso
     
     
           case 2:
           consulta();
           break;
     
           case 3:
           deletar();
           break;
     
           default:
           printf("Essa opção não esta disponivel!\n");
           system("pause");
           break;
           
        }//fim da seleção
   

    }//fim da repeticao
}
