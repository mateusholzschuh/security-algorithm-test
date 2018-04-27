#include <stdio.h>
#define LIN 10	//N DE LINHAS	MATRIZ
#define COL 10	//N DE COLUNAS	MATRIZ
#define PAL 4	//N DE PALAVRAS

int main(){
	char matriz[LIN][COL], palavras[PAL][COL+1];
	int tam[PAL], occ[PAL];
	int i, j, p, x, y, le;
	
	//Preenchimento da Matriz
	for(i=0;i<LIN;i++){
		for(j=0;j<COL;j++){
			//fflush(stdin);	//Usar quando não usar redirecionamento de entrada
			scanf("%c", &matriz[i][j]);
		}
	}
	
	//Escolha das palavras
	for(i=0;i<PAL;i++){
		scanf("%s", palavras[i]);
	}
	
	//Inicialização dos vetores (Tamanho e Ocorrencias)
	for(i=0;i<PAL;i++){
		tam[i] = 0;
		occ[i] = 0;	
	}
	
	//Tamanho das palavras
	for(i=0;i<PAL;i++){
		j=0;
		while(palavras[i][j] != '\0'){
			tam[i]++;
			j++;
		}
	}
	
	//Pesquisa das palavras
	
	for(p=0;p<PAL;p++){ //Para cada palavra
		//PESQUISA HORIZONTAL	
		for(x=0;x<LIN;x++){ //LINHA DA MATRIZ
			for(y=0;y<COL;y++){ //COLUNA DA MATRIZ
				if(matriz[x][y] == palavras[p][0]){ //SE ENCONTRAR A PRIMEIRA LETRA NA MATRIZ
					if(COL-y >= tam[p]){ //VERIFICA O NUMERO RESTANTE DE LETRAS
						le = 0;
						j=0;
						for(i=y;i<COL;i++){ //COMPARA O RESTO DA PALAVRA NA MATRIZ
							if(palavras[p][j] == matriz[x][i]){	//SE A LETRA SEGUINTE FOR ENCONTRADA CONTABILIZA
								le++; //Letras encontradas
								j++; //Contador da posição das letras
							}
						}
						if(le == tam[p]){ //SE NUMERO DE LETRAS ENCONTRADAS FOR IGUAL AO TAMANHO DA PALAVRA, SOMA OCORRENCIA
							occ[p]++;
						}
					}
					
				} 
			}			
		}
		
		//PESQUISA VERTICAL
		for(x=0;x<LIN;x++){	//LINHA DA MATRIZ
			for(y=0;y<COL;y++){ //COLUNA DA MATRIZ
				if(matriz[x][y] == palavras[p][0]){ //SE ENCONTRAR A PRIMEIRA LETRA NA MATRIZ
					if(LIN-x >= tam[p]){
						le=0;
						j=0;
						for(i=x;i<LIN;i++){ //ENQUANTO i FOR MENOR QUE FINAL DA MATRIZ, PROCURA RESTO DA PALAVRA
							if(palavras[p][i] == matriz[i][y]){
								le++; //Letras encontradas
								j++; //Contador da posição das letras
							}
						}
						if(le == tam[p]){ //SE NUMERO DE LETRAS ENCONTRADAS FOR IGUAL AO TAMANHO DA PALAVRA, SOMA OCORRENCIA
							occ[p]++;
						}
					}
				}
			}
		}
	}
	
	for(i=0;i<PAL;i++){
		printf("\nNumero de ocorrencias da palavra \"%s\" : %d", palavras[i], occ[i]);
	}
}
