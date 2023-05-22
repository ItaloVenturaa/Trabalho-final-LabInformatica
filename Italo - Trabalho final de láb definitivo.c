/**************************
Nome e RA: Ettore Amadeu dos Anjos Gobato - 2525267
Nome e RA: Italo Pereira Ventura - 2467259
Turma: AS31A - Láb. de Informatica
Enunciado: TRABALHO FINAL - PROJETO (Gerenciador de treino do GP Formula X)
TRABALHO FEITO NO IDE FALCON !!!
***************************/

#include <stdio.h>	// biblioteca principal de C
#include <locale.h> // biblioteca para ficar certo letras com acento
#include <string.h> // biblioteca para manipular strings
#include <stdlib.h> // biblioteca para o ENTER (pausa para o usuario processar a tela
#include <time.h> 	// biblioteca para converte em xx:xx:xxx
#include <conio.h> 	// biblioteca para apresentar melhor na tela
#include <limits.h> // biblioteca para ter o menor numero possivel



void letraA(int volta[12][8],int w,int o, char listanome[12][50])
{
	int l,i,j;
	int m,M,S,sobra; // converter o tempo e minuto,segundo e milisegundo
	
	//rodamos a matriz e mostramos arrumada volta por volta piloto por piloto
	l=0;
	for (i=0;i<=w;i++)
	{
		printf("%s  ",listanome[l]); // mostra o nome do piloto e na sua frente seus tempos
		l++;
		for(j=0;j<=o;j++)
		{
			// faz o calculo para colocar em xx:xx:xxx o tempo
			M = volta[i][j]/100000;
			sobra = volta[i][j]% 100000;
			S = sobra/1000;
			m = sobra % 1000;
			
			printf("%d:%.2d:%.3d  ", M,S,m);
		}
		printf("\n");
	}
}

void letraB(int volta[12][8],int w,int o,char listanome[12][50])
{
	int i,j,aux,soma; //auxiliares
	int somaLinhas[12];// vetor auxiliar para somar as linhas
	int m,M,S,sobra; // converter o tempo e minuto,segundo e milisegundo
	
	for(i = 0; i <=w; i++)
	{
        soma = 0;
        aux = 8;
        for(j = 0; j <=o; j++)
		{
            soma += volta[i][j];
            if(volta[i][j] == 0)
			{
				aux--;
			}
        }
        somaLinhas[i] = soma/aux;
    }
	
	// imprime a media de todas as linhas da matriz
    for(i=0; i <=w; i++)
	{
		// faz o calculo para colocar em xx:xx:xxx o tempo
		M = somaLinhas[i]/100000;
		sobra = somaLinhas[i] % 100000;
		S = sobra/1000;
		m = sobra % 1000;
		printf("A media do piloto %s é: %d:%.2d:%.3d",listanome[i],M,S,m );
		printf("\n");
    }
}

void letraC(int volta[12][8],int w,int o)
{
	int i,j,aux,soma; // auxiliares para os vetores e contas de divisão
	int somaColunas[8]; //vetor auxiliar para achar a media da volta
	int somaLinhas[12]; // vetor auxiliar para achar a media de cada piloto
	int m,M,S,sobra; // converter o tempo e minuto,segundo e milisegundo
		
	for(i = 0; i <=w; i++)
	{
		// aqui soma linha por linha e acha a media do piloto
        soma = 0;
        aux = 8;
        for(j = 0; j <=o; j++)
		{
            soma += volta[i][j];
            if(volta[i][j] == 0)
			{
				// esse if é para se ele abandonou mudar o digito da divisão para achar a media
				aux--;
			}
        }
        somaLinhas[i] = soma/aux;
    }
    
    for(j=0;j<=o;j++)
	{
		// aqui soma coluna por coluna e acha a media de cada volta
        soma = 0;
        aux = 12;
        for(i=0;i<=w;i++)
		{
            soma += volta[i][j];
            if(volta[i][j] == 0)
			{
				// esse if é para se ele abandonou mudar o digito da divisão para achar a media
				aux--;
			}
        }
        somaColunas[j] = soma/aux;
    }
	
	// imprime a media de todas as linhas da matriz
    for(j=0; j <=o; j++)
	{
		// faz o calculo para colocar em xx:xx:xxx o tempo
		M = somaColunas[j]/100000;
		sobra = somaColunas[j] % 100000;
		S = sobra/1000;
		m = sobra % 1000;
			
		printf("A media da volta %d é: %d:%.2d:%.3d",j+1,M,S,m );
		printf("\n");
    }
}

void letraD(int volta[12][8],int w,int o,char listanome[12][50])
{
	int i,j,u=0,p=0;
	int menor=INT_MAX;
	int m,M,S,sobra; // converter o tempo e minuto,segundo e milisegundo
	
	// aqui roda coluna por coluna procurando o menor valor consequentemente o menor é o mais rapido e a coluna é a volta do treino
	for(j=0;j<=o;j++)
	{
		for(i = 0;i <=w; i++)
		{	
	        if (volta[i][j]<menor)
			{
				if(volta[i][j]!=0)
				{
	            	menor = volta[i][j];
	            	// faz o calculo para colocar em xx:xx:xxx o tempo
	            	p = i+1;
	            	M = menor/100000;
					sobra = menor% 100000;
					S = sobra/1000;
					m = sobra % 1000;
				}
			}
		}
		u++;
		// apresenta o que o progama achou na coluna 
		printf("Na volta %d a liderança ficou com piloto %s com o tempo de %d:%.2d:%.3d\n",u,listanome[p-1],M,S,m );
		menor=INT_MAX;
    }
}

void letraE (int volta[12][8],int w,int o,char listanome[12][50])
{
	int i,j,p,q;
	
	// roda a matriz procurando valores igual a 0 e apresenta a coluna que esta que seria a volta do treino
	for(j=0;j<=o;j++)
	{
		for(i = 0;i <=w; i++)
		{	
	        if (volta[i][j] == 0)
			{
	            p = i;
	            q = j;
	            printf("o piloto %s abandonou o treino antes do fim na volta %d\n",listanome[p],q+1);
			}
		}
    }
}

void ordena(int classificacao[], int w,int o,char nome[][50])
{
	int i,j,temp;
	char auxNome[50];
	
    for ( j = 0; j <=w; j++)
    {
        for ( i = j; i <=w; i++) // roda linha por linha
        {
        	// ordena o vetor cresente
            if (classificacao[i] < classificacao[j])
            {
                temp = classificacao[i];
                classificacao[i] = classificacao[j];
                classificacao[j] = temp;
                
                strcpy(auxNome, nome[i]);
                strcpy(nome[i], nome[j]);
                strcpy(nome[j], auxNome);                
            }
        }
    }
}

void mostrarclassificacao(int classificacao[], int w,char nome[][50])
{
	int i;
	int m,M,S,sobra; 
    for ( i = 0; i <=w; i++) // roda linha por linha
    {
    	// faz o calculo para colocar em xx:xx:xxx o tempo
    	M = classificacao[i]/100000;
		sobra = classificacao[i] % 100000;
		S = sobra/1000;
		m = sobra % 1000;
        printf("\n %s com esse tempo %d:%.2d:%.3d ", nome[i],M,S,m);
    }
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int volta[12][8];			// matriz de tempos
	int classificacao[12];		// vetor da classificação temporaria
	int grid[12];				// vetor do grid de largada
	int menor=INT_MAX;			// menor numero possivel 
	int i,j;					// auxiliares para a matriz
	int aux2;					// auxiliar na divisão se tiver abandono ela não conta e a divisão faz o certo
	int m,M,S,sobra; 			// converter o tempo e minuto,segundo e milisegundo
    int p;              		// Índice / variável contador
    int flag; 					// Indicador
    float X,Y,Z,MV;				// usado para 
	char listanome[12][50];   	// Matriz de caracteres ou vetor de strings
	char listareserva[12][50];   	// Matriz de caracteres ou vetor de strings reserva
	char nome[50]; 				// Nome que será verificado na lista, 17 é o tamanho maximo de caracter no nome
	
	// tela inicial do progama
	printf("\tBem vindo ao GP de formula X!\n\n\n");
	printf("Primeiro vamos colocar os nomes dos pilotos!\n");
	printf("Pressione (ENTER) para proseguir\n\n");
	getch();
	
	// Garregando Lista de nomes
    for (p = 0; p <= 11; p++) {
        printf("Digite o nome do piloto %d: ", p + 1);
        scanf("%s", listanome[p]);
    }

	// aqui eu pego a lista de nomes e faço uma copia para poder mexer no grid e volta por voltas
	// ai eu vou poder ter uma com os pilotos fixos para usar quando o usuario pedir o scouting
     for (p = 0; p <= 11; p++) 
	{
		   strcpy(listareserva[p], listanome[p]);	
    }
    
	printf("\n");
	
	// avisando o usuario como usar o progama 
	printf("OBS: ao colocar os tempos dos pilotos, colocar igual o exemplo:");
	printf("\n\nSe o piloto fez 1:08:721 de tempo colocar desse jeito 108721\n\n");
	printf("Fique tranquilo o progama ira apresentar da forma correta!!!\n");
	printf("Pressione (ENTER) para proseguir\n\n");
	getch();
	
	
	printf("\n\n");
	printf("Pressione (ENTER) para colocar os tempos dos pilotos\n\n");
	getch();
	
	// Garregando a matriz com os tempos
	for(j=0;j<=7;j++)
	{
		for (i=0;i<=11;i++)
		{
			printf("Qual o tempo da volta %d do piloto %s? ",j+1,listanome[i]);
			scanf("%d",&volta[i][j]);
		}
		printf("\n");
	}
	
	// usado para o usuario processar a tela
	printf("\n");
	printf("Pressione (ENTER) para ver o quadro de tempo!\n\n");
	getch();

	// LEBRA A
	printf("\n\n- QUADRO DE TEMPO DE TODAS AS VOLTAS! -\n\n");
	letraA(volta,11,7,listanome); //mostra a função com a letra A
	
	// usado para o usuario processar a tela
	printf("\n");
	printf("Pressione (ENTER) para ver a media de cada piloto!\n\n");
	getch();
	
	// LETRA B
	printf("\n- A MEDIA DE CADA PILOTO! -\n\n");
	letraB(volta,11,7,listanome); //mostra a função com a letra B
	
	// usado para o usuario processar a tela
	printf("\n");
	printf("Pressione (ENTER) para ver a media de cada volta!\n\n");
	getch();
	
	// LETRA C
    printf("\n- A MEDIA DE CADA VOLTA! -\n\n");
    letraC(volta,11,7); //mostra a função com a letra C
    
    // usado para o usuario processar a tela
    printf("\n");
	printf("Pressione (ENTER) para ver quais pilotos lideraram o treino!\n\n");
	getch();
    
    // LETRA D
    printf("\n- QUANTIDADE DE VOLTAS QUE CADA PILOTO LIDEROU! -\n\n");
    letraD(volta,11,7,listanome); //mostra a função com a letra D
    
    // usado para o usuario processar a tela
    printf("\n");
	printf("Pressione (ENTER) para ver quais pilotos abandonaram o treino!\n\n");
	getch();
    
    // LETRA E
    printf("\n- ESSE FORAM OS PILOTOS QUE ABANDONARAM! -\n\n");
    letraE(volta,11,7,listanome); //mostra a função com a letra E
    
    // usado para o usuario processar a tela
    printf("\n");
	printf("Pressione (ENTER) para ver o grid de largada!\n\n");
	getch();
    
    // LETRA F
    for(i=0;i<=11;i++) 
	{
	    for(j=0;j<=7;j++) 
		{
			if(volta[i][j]< menor && volta[i][j]!=0) // pega o menor valor diferente de 0
			{
				menor = volta[i][j]; // os valores serão armazenados nesse vetor
    		}
			grid[i]=menor;
	    }
	    menor=INT_MAX;
	}
	
    printf("\n");
    ordena(grid,11,7,listareserva); // função para ordenar o vetor
    printf("grid de largada: ");
    mostrarclassificacao(grid,11,listareserva); // função para mostrar o vetor organizado
    printf("\n");
    
    // usado para o usuario processar a tela
    printf("\n");
	printf("Pressione (ENTER) para ver a classificação temporaria das voltas! \n\n");
	getch();
	
	// OBS: a F e a G não coloquei na função pois em c não pode por função dentro de uma outra função
    
    // LETRA G
    for(j=0;j<=7;j++)
	{	
		for(i=0;i<=11;i++)
		{
			if(volta[i][j]!=0)
			{
				classificacao[i] = volta[i][j]; // armazenando os valores nesse vetor
			}
		}
	    printf("\n");
	    ordena(classificacao,11,7,listareserva);	// função para ordenar o vetor
	    printf("classificação temporaria da volta %d é: ",j+1);
	    mostrarclassificacao(classificacao,11,listareserva); // função para mostrar o vetor organizado
	    printf("\n");
	}
	
	// usado para o usuario processar a tela
	printf("\n");
	printf("Pressione (ENTER) para pesquisar o scouting de um determinado piloto\n\n");
	getch();
	
	// LETRA H
	do{
		// Entrada do nome a ser verificado na lista
        printf("\nDigite o nome do  pilito para mostrar o seu scouting: ");
        scanf("%s", nome);
        // Pesquisa nome na lista
        flag = 0;   // Indica que não achou
        for (p = 0; p <= 11; p++) {
            if (strcmp(listanome[p], nome) == 0) // Se o elemento é igual ao nome
			{    
				printf("\nPiloto %s tem esse scouting\n\n", nome);
				aux2 = p;
	
		 	   for(j=0;j<=7;j++) // roda na matriz e pega todas as voltas do piloto
				{
					// faz o calculo para colocar em xx:xx:xxx o tempo
					M = volta[aux2][j]/100000;
					sobra = volta[aux2][j]% 100000;
					S = sobra/1000;
					m = sobra % 1000;
					printf("%d:%.2d:%.3d  ", M,S,m);
				}
                flag = 1;   // Indica que achou
            }
        }
    	if(flag == 0) // caso o nome não seja encontrado na lista
		{
            printf("\nO nome %s não consta na lista.\n", nome);
        }
        
	}while(flag!=1);
	
	printf("\n");
	printf("\n");
	printf("Pressione (ENTER) para \n\n");
	getch();

	// LETRA I a maior media de velocidade 
	printf ("\nO autódromo italiano é o mais rápido da história da Fórmula X, com uma média de velocidade de 264,3 km/h \nem uma unica volta registrado por Lewis Hamilton durante uma volta no treino classificatório de 2020\n\n");
	
	// convertendo o tempo para fazer as contas da velocidade media
	Y=grid[0];
	Z=Y-100000;
	MV = 4275/(Z+60000);
	X = (1000*(MV*3.6));
	
	// apresenta a velocidade media
	printf("%.2f km/h foi a velocidade media que o primeiro colocado pegou no circuito!\n",X);
	
	// Encerra o progama
	printf("\n");
	printf("O fim de semana de treino da Formula X chegou ao fim!");
	printf("\n");
	
	// OBS tem algumas letras que não fizemos função pois não da para por função dentro de função em C
	
	return 0;
}
