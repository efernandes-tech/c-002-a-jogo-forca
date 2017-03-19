#include <stdio.h>
#include <string.h>

int main() {
	char palavrasecreta[20];
	
	sprintf(palavrasecreta, "MELANCIA"); // Ele escreve "MELANCIA\0", o "\0" informa que acabou a palavra.
	
	int acertou = 0;
	int enforcou = 0;
	
	char chutes[26];
	int tentativas = 0;
	
	do {
		int i, j;

		for (i = 0; i < strlen(palavrasecreta); i++) {
			int achou = 0;
			
			for (j = 0; j < tentativas; j++) {
				if (chutes[j] == palavrasecreta[i]) {
					achou = 1;
					break;
				}
			}
			
			if (achou) {
				printf("%c ", palavrasecreta[i]);
			} else {
				printf("_ ");
			}
		}
		printf("\n");
		
		char chute;
		
		printf("Qual letra?");
		scanf(" %c", &chute); // O espaço " " antes do "%c" resolve o problema do enter.

		chutes[tentativas] = chute;
		tentativas++;

		for (i = 0; i < strlen(palavrasecreta); i++) {
			if (palavrasecreta[i] == chute) {
				printf("A posição %d tem essa letra\n", i+1);
			}
		}
	} while (!acertou && !enforcou);
	
	system("pause");
}
