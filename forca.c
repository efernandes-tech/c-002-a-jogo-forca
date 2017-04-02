#include <stdio.h>
#include <string.h>
// Header file desta aplicação.
#include "forca.h"

// Variaveis globais.
char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;

void abertura() {
	printf("/*****************/\n");
	printf("/* Jogo de Forca */\n");
	printf("/*****************/\n\n");
}

void chuta() {
	char chute;

	printf("Qual letra? ");
	scanf(" %c", &chute);

	chutes[chutesdados] = chute;
	chutesdados++;
}

int jachutou(char letra) {
	int j, achou = 0;
    for(j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaforca() {
    printf("Você já deu %d chutes\n", chutesdados);
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

int enforcou() {
    int erros = 0, i;
    // Vamos fazer o loop em todos os chutes dados.
    for(i = 0; i < chutesdados; i++) {
        int existe = 0, j;
        // Agora vamos olhar letra a letra da palavra secreta e ver se encontramos o chute aqui.
        for(j = 0; j < strlen(palavrasecreta); j++) {
            if (chutes[i] == palavrasecreta[j]) {
                // Encontramos, vamos quebrar o loop.
                existe = 1;
                break;
            }
        }
        // Se nao encontrou, soma um na quantidade de erros.
        if (!existe)
			erros++;
    }
    // Se tivermos mais do que 5 erros, retornamos 1, caso contrario, retornamos 0.
    return erros >= 5;
}

int ganhou() {
	int i;
    for(i = 0; i < strlen(palavrasecreta); i++) {
        if (!jachutou(palavrasecreta[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
	abertura();
	escolhepalavra();

	do {
		desenhaforca();

		chuta();
	} while (!ganhou() && !enforcou());
}
