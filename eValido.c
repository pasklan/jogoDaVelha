//Garante que nada diferente de 'x', 'X', 'o', 'O' seja informado durante as 
//jogadas
int eValido(char letra){
	if(letra == 'x' || letra == 'o' || letra == 'X' || letra == 'O')
		return 1;
	else
		return 0;	
}
