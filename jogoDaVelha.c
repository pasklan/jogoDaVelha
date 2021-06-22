#include <stdio.h>
#include <locale.h>
#include "limparTela.c"
#include "eValido.c"
#include "coordenadaEhValida.c"
#include "eVazia.c"
//Constantes de tamanho dos vetores
#define tamNome 50
#define tamTab 3

//Variáveis globais, podem ser acessadas
//de qualquer função
char jogador1[tamNome], jogador2[tamNome];
char tabuleiro[tamTab][tamTab];

//atribui a letra 'V' a todas as posições/coordenadas na minha matrix/tabuleiro
void inicializaTabuleiro(){
	int i, k;
	for(i=0; i<=2; i++){
		for(k=0; k<=2; k++){
			tabuleiro[i][k] = 'V';
		}
	}
}

//Verifica se o jogador ganhou por linhas
int ganhouLinhas(){
	int i, j, ganhou = 1;
	for(i=0; i<3; i++){
		for(j=0; j<2; j++){
			if( eValido(tabuleiro[i][j]) && tabuleiro[i][j] == tabuleiro[i][j+1] ){
				ganhou++;
			}
		}
		if(ganhou == 3){
			return 1;
		}
		ganhou = 1;
	}
	return 0;	
}

//Verifica se o jogador ganhou por colunas
int ganhouColunas(){
	int i, j, ganhou = 1;
	for(i=0; i<3; i++){
		for(j=0; j<2; j++){
			if( eValido(tabuleiro[j][i]) && tabuleiro[j][i] == tabuleiro[j+1][i] ){
				ganhou++;
			}
		}
		if(ganhou == 3){
			return 1;
		}
		ganhou = 1;
	}
	return 0;	
}
/*Verifica se alguém ganhou completando a diagonal
principal*/
int ganhouDiagPrincipal(){
	int i, ganhou = 1;
	for(i = 0; i < 2; i++){
		if(eValido(tabuleiro[i][i]) && tabuleiro[i][i] == tabuleiro[i+1][i+1])
			ganhou++;
	}
	printf("\n%d\n", ganhou);
	if(ganhou == 3)
		return 1;
	else
		return 0;
}
/*Verifica se alguem ganhou pela completando a 
diagonal secundária*/
int ganhouDiagSecundaria(){
	int i, ganhou = 1;
	for(i = 0; i < 2; i++){
		if(eValido(tabuleiro[i][3-1-i]) &&  tabuleiro[i][3-i-1] == tabuleiro[i+1][3-i-2] )
			ganhou++;
	}
	if(ganhou == 3)
		return 1;
	else
		return 0;
}

/*Imprime na tela o tabuleiro do jogo*/
imprimeTabuleiro(){
	int i, j;
	printf("\n   0   1    2\n");
	for(i=0; i<3; i++){
		printf("%d", i);
		for(j=0; j<3; j++){
			if(eValido(tabuleiro[i][j])){
				if(j < 2){
					printf("  %c |", tabuleiro[i][j]);
				}else{
					printf("  %c ", tabuleiro[i][j]);
				}
			}else{
				if(j < 2){
					printf("    |");
				}else{
					printf("    ");
				}
			}
		}
		if(i < 2){
			printf("\n  -------------\n");
		}	
	}
}
//Ao ser chamada pede coordenadas ao jogador 
//se forem dadas coordenadas inválidas, continuará 
//solicitando coordenadas enquanto coordenadas inválidas
//não forem informadas
void jogar(){
	int x, y, valida, ordem = 1, vencer = 0, jogadas = 0;
	
	do{
		do{
			imprimeTabuleiro();
			printf("\n\nPor favor faça sua jogada, qual coordenada deseja usar? \n");
			scanf("%d%d", &x, &y);
			limparTela();
			valida = coordenadaEhValida(x, y);
			if(valida == 1)
				valida += eVazia(x, y);
		}while(valida != 2);
		if(ordem == 1){
			tabuleiro[x][y] = 'X';
		}else{
			tabuleiro[x][y] = 'O';
		}
		jogadas++;
		ordem++;
		if(ordem == 3){
			ordem = 1;
		}	
		vencer += ganhouLinhas();
		vencer += ganhouColunas();
		vencer += ganhouDiagPrincipal();
		vencer += ganhouDiagSecundaria();
	}while(vencer == 0 && jogadas < 9);
	limparTela();
	imprimeTabuleiro();
	if(vencer != 0 ){
		if(ordem - 1 == 1){
			printf("\n\nParabéns %s, você venceu!\n", jogador1);
		}else{
			printf("\n\nParabéns %s, você venceu!\n", jogador2);
		}
	}else{
		printf("\n\nNinguém venceu... empate...\n");
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	puts("\n\tInforme nome do Jogador 1:");
	scanf("%s", jogador1);
	puts("\tInforme nome do Jogador 2:");
	scanf("%s", jogador2);
	limparTela();
	/*INICIO DO JOGO*/
	//Executa o jogo enquanto se desejar jogar
	do{
		inicializaTabuleiro();
		jogar();
		printf("\nDeseja jogar  novamente\n(1-SIM / 2-NÃO)\n");
		scanf("%d", &opcao);
	}while(opcao == 1);
	
	return 0;
}
