/*
Solicitaram para que você construisse um programa simples de criptografia. Este programa deve possibilitar enviar mensagens codificadas sem que alguém consiga lê-las.
 O processo é muito simples. São feitas três passadas em todo o texto.

Na primeira passada, somente caracteres que sejam letras minúsculas e maiúsculas devem ser deslocadas 3 posições para a direita, segundo a tabela ASCII: 
letra 'a' deve virar letra 'd', letra 'y' deve virar caractere '|' e assim sucessivamente. Na segunda passada, a linha deverá ser invertida. 
Na terceira e última passada, todo e qualquer caractere a partir da metade em diante (truncada) devem ser deslocados uma posição para a esquerda na tabela ASCII. Neste caso, 'b' vira 'a' e 'a' vira '`'.

Por exemplo, se a entrada for “Texto #3”, o primeiro processamento sobre esta entrada deverá produzir “Wh{wr #3”. 
O resultado do segundo processamento inverte os caracteres e produz “3# rw{hW”. Por último, com o deslocamento dos caracteres da metade em diante, o resultado final deve ser “3# rvzgV”.

Entrada
A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém um inteiro N (1 = N = 1*104), 
indicando a quantidade de linhas que o problema deve tratar. As N linhas contém cada uma delas M (1 = M = 1*103) caracteres.
Saída
Para cada entrada, deve-se apresentar a mensagem criptografada

4
Texto #3             3# rvzgV
abcABC1              1FECedc
vxpdylY .ph          ks. \n{frzx
vv.xwfxo.fd          gi.r{hyz-xx

*/

#include<stdio.h>
#include<string.h>
int main(){
	int n,i,j,k;
	char vetor[1000], temp;
	scanf("%d ",&n);
	for (i = 0; i<n; i++){
		gets(vetor);
		k = strlen(vetor) -1;
			for(j=0; j<(strlen(vetor)); j++){
					if(vetor[j]>64 && vetor[j]<91 || vetor[j]<123 && vetor[j]>96){vetor[j] +=3;}
			}
			for(j=0; j<(strlen(vetor)/2); j++){
				temp = vetor[j];
				vetor[j] = vetor[k];
				vetor[k] = temp;
				k -=1;
			}
			for(j=(strlen(vetor)/2 ); j<(strlen(vetor)); j++){vetor[j] -=1;}
			printf("%s\n",vetor);	
	}
	return 0;
}
