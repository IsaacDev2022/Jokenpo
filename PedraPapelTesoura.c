#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

/* 
	Projeto realizado entre os dias 05/02/2020 e 09/02/2020:
	Autor: Isaac Silva Martins
	Curso: Tecnologia em análise e desenvolvimento de sistemas Uniprojeção - Tagautinga DF
	
	Jogo: Pedra, papel e tesoura, mais conhecido como Jokenpo, é uma brincadeira em que
	duas pessoas decidem a vitória esticando a mão e formando um determinado símbolo simultaneamente,
	de acordo com a regra do jogo, a vitória é garantida da seguinte regra:
		- Pedra ganha da tesoura (quebrando);
		- tesoura ganha do papel (cortando);
		- papel ganha da pedra (enrolando);
*/


#define B 219
#define PEDRA 1
#define PAPEL 2
#define TESOURA 3


// Funções:
	// Funções relacionadas a estilizção do jogo:
	void gotoxy(int x, int y);
	void borderLine(int x, int y);
	void borderVline (int x, int y);
	void insideBorderLine (int x, int y);
	void insideBorderVline (int x, int y);	
	void line (int n);
	void Vline (int n, int x, int y);
	void border ();
	void menuStart ();
	void carregando();
	void barra ();
	void loading ();
	void sign ();
	void options ();
	void tutorial ();
	
	
	// Funções relacionadas ao funcionamento do jogo:
	void game ();
	void backendGame ();
	int checkerGame (int escJogador, int escComputer);
	void roundWinner (int vitory);
	void gameWinner (int pontJogador, int pontComputer);	



// Variáveis globais:
	int i, j, n, esc, escJogador, escComputer, pontJogador = 0, pontComputer = 0, vitory;
	char escReturn;
	

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int main(){
	srand (time(NULL));
	// Função que muda as cores do terminal
	system ("color 1A");
	game ();
	
	return 0;	
}


// Função que reuni todas as outras e dá vida ao jogo
void game (){
	loading ();
	sign ();
	border ();
	getchar ();
	menuStart ();

	switch (n){
		case 01:{
			do {
			
			backendGame ();
			getchar ();
			border ();
			getchar ();
			gotoxy (8, 13);
			printf ("Sua escolha: ");
				scanf ("%d", &escJogador);
				
				escComputer = rand () % 3 + 1;
				
				roundWinner (vitory);
				
				border ();
		
				if (pontJogador == 5)
						{
							gotoxy (45, 15);
							line (10);
							printf ("Voce e o vencedor");
							line (10);
							gotoxy (45, 17);
							printf ("  1 - Jogar novamente");
							gotoxy (45, 19);
							printf ("  2 - Sair");
							Vline (8, 45, 15);
							Vline (8, 81, 15);
							gotoxy (45, 22);
							line (37);
							gotoxy (45, 24);
							printf ("Sua escolha: ");
								scanf ("%d", &i);
								
							switch (i){
								case 01:{
									pontJogador = 0;
									system ("cls");
									game ();
									
									
									break;
								}
								
								case 02:{
									exit (2);
									break;
								}
							}
						}
						
					if (pontComputer == 5)
						{
							gotoxy (45, 15);
							line (10);
							printf ("Voce perdeu");
							line (10);
							gotoxy (45, 17);
							printf ("  1 - Jogar novamente");
							gotoxy (45, 19);
							printf ("  2 - Sair");
							Vline (8, 45, 15);
							Vline (8, 75, 15);
							gotoxy (45, 22);
							line (31);
							gotoxy (45, 24);
							printf ("Sua escolha: ");
								scanf ("%d", &i);
								
							switch (i){
								case 01:{
									pontComputer = 0;
									system ("cls");
									game ();
									
									
									break;
								}
								
								case 02:{
									exit (2);
									break;
								}
							}
						} 
						
				
				
			} while (i != 2);
			
			break;
			
			case 02:{
				tutorial ();
				break;
			}
			
			case 03:{
				exit (3);
				break;
				}
			
			}
		}		
}


// Funções para tela de carregamento:
void loading (){
	int i;	
	for (i = 0; i < 1; i++){
		printf ("\n");
		printf ("\t\t\t\t\t\t");
		carregando ();
		printf ("\n");
		barra ();
		
		system ("cls");
	}	
}


void carregando (){
	char nome [10] = "CARREGANDO";
	int i, j;
	
	for (j = 0; j < 10; j++){
		printf("%c", nome[j]);
        Sleep(200);
    }
}


void barra (){
	int i, j;
	for (i = 0; i <= 32; i++){ 
		gotoxy (3, 3);               
      	printf (" \r", i);
      	fflush (stdout);                      
         
      	for (j = 0; j < i; j++){ 
	  		if (!j) 
	  		
	  		gotoxy (3, 3);
        	printf ("  ");   
        	printf ("%c", B);
        	
        	Sleep(1);
    	}                      
   	}
}


// Função que exibe um letreiro tema:
void sign (){
	printf ("\n\n\n\n");
	printf ("\n\t\t\t      |   |||||||   |   |    |||||   ||      |   ||||||   |||||||");
	printf ("\n\t\t\t      |   |     |   |  |     |       | |     |   |    |   |     |");
	printf ("\n\t\t\t      |   |     |   | |      |       |  |    |   |    |   |     |");
	printf ("\n\t\t\t      |   |     |   ||       |||||   |   |   |   ||||||   |     |");
	printf ("\n\t\t\t      |   |     |   | |      |       |    |  |   |        |     |");
	printf ("\n\t\t\t |    |   |     |   |  |     |       |     | |   |        |     |");
	printf ("\n\t\t\t |    |   |     |   |   |    |       |      ||   |        |     |");
	printf ("\n\t\t\t ||||||   |||||||   |    |   |||||   |       |   |        |||||||");
	
}


// Funções para composição das bordas: 
// Bordas para as tabelas de jogador, de menu, etc.
void line(int n){
	for(i = 0; i < n; i++){
		printf("%c", B);
	} 
}

	
void Vline(int n, int x, int y){	
	for(i = 0; i < n; i++){
		gotoxy(x, y + i);
		printf("%c", B);	
	} 
}


// Bordas externas:
void borderLine (int x, int y){
	for(i = 0; i < 118; i++){
		gotoxy (x + i, y);
		printf("%c", B);
	} 
}


void borderVline (int x, int y){
	for(i = 0; i < 31; i++){
		gotoxy (x, y + i);
		printf("%c", B);
	}
}


// Bordas internas:
void insideBorderLine (int x, int y){
	for(i = 0; i < 115; i++){
		gotoxy (x + i, y);
		printf("%c", B);
	} 
}


void insideBorderVline (int x, int y){
	for(i = 0; i < 26; i++){
		gotoxy (x, y + i);
		printf("%c", B);
	}
}	


// Agrupa as funções de bordas em uma só 
void border (){
// Borda externa:
	borderLine (0, 0);
	gotoxy (3, 3);
	borderVline (0, 0);
	borderLine (0, 30);
	borderVline (118, 0);
	
// Borda interna:
	insideBorderLine (2, 2);
	gotoxy (5, 5);
	insideBorderVline (2, 2);
	insideBorderLine (2, 28);
	insideBorderVline (116, 2);
	
}


void menuStart (){
// Menu de início:
	gotoxy (45, 15);
	line (10);
	printf (" Bem vindo ");
	line (10);
	gotoxy (47, 17);
	printf (" 1 - Jogar");
	gotoxy (47, 19);
	printf (" 2 - Ver tutorial");
	gotoxy (47, 21);
	printf (" 3 - Sair");
	Vline (8, 45, 15);
	Vline (8, 75, 15);
	gotoxy (45, 23);
	line (31);
	gotoxy (45, 25);
	printf ("Sua escolha: ");
		scanf ("%d", &n);
		
	system ("cls");
	
}


void backendGame (){
// Jogador 01:
	gotoxy (8, 5);
	line (7);
	printf (" jogador 01 ");
	line (7);
	gotoxy (8, 7);
	printf ("  Sua escolha: %d", escJogador);
	gotoxy (8, 9);
	printf ("  Pontos: %d", pontJogador);
	Vline (6, 8, 5);
	Vline (6, 33, 5);
	gotoxy (8, 11);
	line (26);
	

// Jogador 02: Máquina 
	gotoxy (84, 5);
	line (7);
	printf (" jogador 02 ");
	line (7);
	gotoxy (84, 7);
	printf ("  Escolha dele: %d", escComputer);
	gotoxy (84, 9);
	printf ("  Pontos: %d", pontComputer);
	Vline (6, 84, 5);
	Vline (6, 109, 5);
	gotoxy (84, 11);
	line (26);
	
	options ();

}


void options (){
	gotoxy (47, 5);
	line (7);
	printf (" Escolhas: ");
	line (7);
	gotoxy (47, 7);
	printf ("   1 - Pedra ");
	gotoxy (47, 9);
	printf ("   2 - Papel ");
	gotoxy (47, 11);
	printf ("   3 - Tesoura ");
	Vline (8, 47, 5);
	Vline (8, 72, 5);
	gotoxy (47, 13);
	line (26);
	
}


// Funções relacionadas ao funcionamento do jogo:
int checkGame (int vitory, int escJogador, int escComputer){
// Verifica as condições para um dos jogadores vencer ou gerar empate e retorna o resultado pela variável vitory
    if(escJogador == escComputer)
    {
    	// Retorna 0 caso haja um empate, mas não dá pontuação para os dois jogadores
        vitory = 0;
    }

    if(escJogador==PEDRA && escComputer==TESOURA) vitory = 1; 
    if(escJogador==PEDRA && escComputer==PAPEL) vitory = 2; 

    if(escJogador==PAPEL && escComputer==PEDRA) vitory = 1; 
    if(escJogador==PAPEL && escComputer==TESOURA) vitory = 2; 

    if(escJogador==TESOURA && escComputer==PAPEL) vitory = 1; 
    if(escJogador==TESOURA && escComputer==PEDRA) vitory = 2; 
    
    return vitory;
}


// Conta os pontos a cada rodada dos dois jogadores (no caso o usuário e a máquina), quando a pontuação atinge 5 pontos, um deles é declarado campeão
void roundWinner (int vitory){
		vitory = checkGame (vitory, escJogador, escComputer);
	
		if (vitory == 1)
		{
			gotoxy (8, 15);
			line (7);
			printf ("Voce venceu");
			line (7);
			Vline (3, 8, 15);
			Vline (3, 33, 15);
			gotoxy (8, 18);
			line (26);
			getch ();
			system ("cls");
			pontJogador++;
		} 
	
		else if (vitory == 2)
		{
			gotoxy (82, 15);
			line (7);
			printf ("O computador venceu");
			line (7);
			Vline (3, 82, 15);
			Vline (3, 114, 15);
			gotoxy (82, 18);
			line (33);
			getch ();
			system ("cls");
			pontComputer++;
		} 
		
		else
		{
			gotoxy (50, 15);
			line (7);
			printf ("Empate");
			line (7);
			Vline (3, 50, 15);
			Vline (3, 70, 15);
			gotoxy (50, 18);
			line (21);
			getch ();
			system ("cls");
		} 
}


// Exibe um tutorial de ensinamento para o jogo
void tutorial (){
	border ();
	gotoxy (30, 5);
	line (27);
	printf (" Como Jogar: ");
	line (27);
	gotoxy (30, 7);
	printf ("   1 - Como funciona o jogo em si:");
	gotoxy (30, 9);
	printf ("       Pedra vence tesoura");
	gotoxy (30, 11);
	printf ("       Tesoura vence papel ");
	gotoxy (30, 13);
	printf ("       Papel vence pedra ");
	gotoxy (30, 15);
	printf ("   2 - Digite o numero correspondende a um dos tres");
	gotoxy (30, 17);
	printf ("   3 - Use a tecla Enter para passar pelas etapas");
	gotoxy (30, 19);
	printf ("   4 - O primeiro a atingir 5 pontos ganha o jogo");
	gotoxy (30, 21);
	printf ("   5 - Empate nao garante pontos para nenhum dos jogadores");
	Vline (18, 30, 5);
	Vline (18, 96, 5);
	gotoxy (30, 23);
	line (67);
	gotoxy (30, 26);
	printf ("Digite 1 para retornar ao menu principal ou 2 para sair: ");
		scanf ("%d", &i);
		
		if (i == 1)
		{
			system ("cls");
			game ();
		}
		
		else if (i == 2) exit (2);
	
	getchar ();

}


