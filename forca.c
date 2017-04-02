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
    printf("Você já deu %d chutes\n", tentativas);
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
    for(i = 0; i < tentativas; i++) {
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

int main() {
	int acertou = 0;

	abertura();
	escolhepalavra();

	do {
		desenhaforca();

		chuta();
	} while (!acertou && !enforcou());
}
