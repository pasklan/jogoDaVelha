//Verifica se foram informadas coordenadas válidas
//linha entre 0 e 2 e coluna entre 0 e 2
int coordenadaEhValida(int l, int c){
	if(l >= 0 && l < 3){
		if(c >= 0 && c < 3){
			return 1;
		}
	}
	return 0;
}
