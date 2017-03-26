#include <stdio.h>
#include <string.h>

void abertura() {
	printf("/*****************/\n");
	printf("/* Jogo de Forca */\n");
	printf("/*****************/\n\n");
}

void chuta(char chutes[], int* tentativas) { // Declaracao de ponteiro.
	char chute;

	printf("Qual letra? ");
	scanf(" %c", &chute);

	// 
	chutes[*tentativas] = chute; // Usando o ponteiro.
	(*tentativas)++;
}

int main() {
	char palavrasecreta[20];
	sprintf(palavrasecreta, "MELANCIA");

	int acertou = 0;
	int enforcou = 0;

	char chutes[26];
	int tentativas = 0;

	abertura();

	do {
		printf("Você já deu %d chutes\n", tentativas);

		int i;
		for(i = 0; i < strlen(palavrasecreta); i++) {
			int achou = 0;

			int j;
			for(j = 0; j < tentativas; j++) {
				if(chutes[j] == palavrasecreta[i]) {
					achou = 1;
					break;
				}
			}

			if(achou) {
				printf("%c ", palavrasecreta[i]);
			} else {
				printf("_ ");
			}
		}
		printf("\n");

		// Passagem de parametro por referencia (ponteiro) e nao por copia.
		chuta(chutes, &tentativas);
	} while (!acertou && !enforcou);

}
