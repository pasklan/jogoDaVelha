//Verifica se a posicao informada está vazia no tabuleiro
int eVazia(int l, int c){
	if(tabuleiro[l][c] != 'x' && tabuleiro[l][c] != 'X' 
	&& tabuleiro[l][c] != 'o' && tabuleiro[l][c] != 'O') {
		return 1;
	}else{
		return 0;
	}
}
