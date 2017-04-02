#include <stdio.h>
#include <string.h>

// Variaveis globais.
char palavrasecreta[20];
char chutes[26];
int tentativas = 0;

void abertura() {
	printf("/*****************/\n");
	printf("/* Jogo de Forca */\n");
	printf("/*****************/\n\n");
}

void chuta() {
	char chute;

	printf("Qual letra? ");
	scanf(" %c", &chute);

	chutes[tentativas] = chute;
	tentativas++;
}

int jachutou(char letra) {
	int j, achou = 0;
    for(j = 0; j < tentativas; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaforca() {
    printf("Voc� j� deu %d chutes\n", tentativas);
	int i;
    for(i = 0; i < strlen(palavrasecreta); i++) {
        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void escolhepalavra() {
    sprintf(palavrasecreta, "MELANCIA");
}

int main() {
	int acertou = 0;
	int enforcou = 0;

	abertura();
	escolhepalavra();

	do {
		desenhaforca();

		chuta();
	} while (!acertou && !enforcou);
}
