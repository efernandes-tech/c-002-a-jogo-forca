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

int jachutou(char letra, char* chutes, int tentativas) {
	int j, achou = 0;
    for(j = 0; j < tentativas; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
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
			if(jachutou(palavrasecreta[i], chutes, tentativas)) {
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
