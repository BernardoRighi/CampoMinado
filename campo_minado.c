
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define tmat 10

/*
COR DO FUNDO:
 	preta \033[40m
  	vermelha \033[41m
  	verde \033[42m
  	laranja \033[43m
  	azul \033[44m
  	magenta \033[45m
  	ciano \033[46m
  	branca \033[47m
COR DO PRIMEIRO PLANO:
	preta \033[30m
	vermelha \033[31m
	verde \033[32m
	laranja \033[33m
	azul \033[34m
	magenta \033[35m
	ciano \033[36m
	branca \033[37m
*/

#define cordaborda printf("\033[36m")
#define cordacoordenada printf("\033[37m")
#define cordabomba printf("\033[31m")
#define cordatela printf("\033[35m")
#define cordozero printf("\033[30m")
#define cordofundo printf("\033[37m")
#define cordamensagem printf("\033[37m")

#define bordacima1 printf("\u250F")
#define bordacima2 printf("\u2533")
#define bordacima3 printf("\u2513\n")
#define bordabaixo1 printf("\u2517")
#define bordabaixo2 printf("\u253B")
#define bordabaixo3 printf("\u251B\n")
#define divisoria1 printf("\u2523")
#define divisoria2 printf("\u254B")
#define divisoria3 printf("\u252B\n")
#define lateral printf("\u2503")

// Criando a enumeração:
enum boolean {
    true = 1, false = 0
};

// Permitindo a sua declaração como um tipo qualquer:
typedef  enum boolean  bool;


// Declaração dos registros da matriz
typedef struct
{
	int coordenada;
	bool status;
	int tela;
}

tmatriz;


// Inicia a matriz
void inicia_matriz(tmatriz matriz[tmat][tmat])
{
	int i,j,ini=0;
	for (i=0;i<tmat;i++)
	{
		for (j=0;j<tmat;j++)
		{
			matriz[i][j].coordenada=ini;  //numero do campo da matriz. Para o jogador escolher qual campo abrir
			matriz[i][j].status=false;  //true=aberto false=fechado
			matriz[i][j].tela=0;  //conteúdo do campo da matriz
			ini+=1;
		}
	}
}

// Desenha o tabuleiro, mostrando coordenadas e o valor dos campos
void desenhar(tmatriz matriz[tmat][tmat])
{
	int i,j,k;

	//Desenha a borda superior
	cordaborda;
	bordacima1;
	for (k=1;k<tmat;k++) 
	{
		bordacima2;
	}
	bordacima3;

	//Loop para desenhar o meio e colocar os valores
	for (i=0;i<tmat;i++)
	{
		for (j=0;j<tmat;j++)
		{
			cordaborda;
			lateral;

			// Teste para desenhar os valores
			if (matriz[i][j].status==true)
			{
				if (matriz[i][j].tela==9)
				{
					cordozero;
					printf(" %02d ",matriz[i][j].tela);
				}
				if (matriz[i][j].tela==10)
				{
					cordabomba;
					printf(" BB ");
				}
				if (matriz[i][j].tela<9)
				{
					cordatela;
					printf(" %02d ",matriz[i][j].tela);
				}
			}
			if (matriz[i][j].status==false)
			{
			cordacoordenada;
			printf(" %02d ",matriz[i][j].coordenada);
			}
			// fim do teste
		}
		cordaborda;
		lateral;
		printf("\n");
		if (i<tmat-1)
		{
			divisoria1;
			for (k=1;k<tmat;k++) 
			{
				divisoria2;
			}
			divisoria3;
		}
	}
	//Desenha a borda inferior
	bordabaixo1;
	for (k=1;k<tmat;k++) 
	{
		bordabaixo2;
	}

	bordabaixo3;
}

void cabecario()
{
	cordamensagem;
	printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
   
}

int main()
{

	tmatriz matriz[tmat][tmat];
	int qtdbomb,escolha,acerto,k,l;
	bool parada,opcao=true;
	srand(time(NULL));

	printf("\033[40m");
	printf("\033[2J");
	cabecario();

	//loop principal
	while (opcao==true)
	{
		inicia_matriz(matriz);
		desenhar(matriz);

		opcao = false;

		return 0;
	}
}

