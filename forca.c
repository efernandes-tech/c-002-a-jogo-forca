#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Header file desta aplicação.
#include "forca.h"

// Variaveis globais.
char palavrasecreta[TAMANHO_PALAVRA];
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
    int erros = chuteserrados();

	printf("  _______       \n");
	printf(" |/      |      \n");
	printf(" |      %c%c%c  \n",
		(erros>=1?'(':' '),
	    (erros>=1?'_':' '),
		(erros>=1?')':' ')
	);
	printf(" |      %c%c%c  \n",
		(erros>=3?'\\':' '),
	    (erros>=2?'|':' '),
		(erros>=3?'/': ' ')
	);
	printf(" |       %c     \n",
		(erros>=2?'|':' ')
	);
	printf(" |      %c %c   \n",
		(erros>=4?'/':' '),
	    (erros>=4?'\\':' ')
	);
	printf(" |              \n");
	printf("_|___           \n");
	printf("\n\n");

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
    FILE* f;

    f = fopen("palavras.txt", "r");
    if(f == 0) {
        printf("Banco de dados de palavras não disponível.\n\n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

	// Gera um numero aleatório.
    srand(time(0));
    int randomico = rand() % qtddepalavras;

	int i;
    for(i = 0; i <= randomico; i++) {
        fscanf(f, "%s", palavrasecreta);
    }

	// SEMPRE feche o arquivo, se não outro sistema não consegue abrir.
    fclose(f);
}

int enforcou() {
	// Se tivermos mais do que 5 erros, retornamos 1, caso contrario, retornamos 0.
    return chuteserrados() >= 5;
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

void adicionapalavra() {
    char quer;

    printf("Você deseja adicionar uma nova palavra no jogo (S/N)?");
    scanf(" %c", &quer); // O " " ignora o enter.

    if (quer == 'S') {
        char novapalavra[TAMANHO_PALAVRA];

        printf("Digite a nova palavra, em letras maiúsculas: ");
        scanf(" %s", novapalavra);

        // Ponteiro que aponta para um arquivo.
        FILE* f;

	    // Abre arquivo para leitura e escrita.
	    f = fopen("palavras.txt", "r+");
	    if (f == 0) {
	        printf("Banco de dados de palavras não disponível.\n\n");
	        exit(1);
	    }

	    int qtd;
	    fscanf(f, "%d", &qtd);
	    
	    qtd++;
	    
	    // Coloca o ponteiro de leitura do arquivo no inicio novamente.
	    fseek(f, 0, SEEK_SET);
	    
	    // Reescreve a quantidade de palavras do arquivo.
	    fprintf(f, "%d", qtd);
	    
	    // Vai para o final do arquivo.
	    fseek(f, 0, SEEK_END);

	    // Escreve a palavra no final do arquivo.
	    fprintf(f, "%s", novapalavra);

	    // Fecha.
	    fclose(f);
    }
}

int chuteserrados() {
    int erros = 0, i;
    // Faz um loop em todos os chutes dados.
    for(i = 0; i < chutesdados; i++) {
    	if (!letraexiste(chutes[i])) {
            erros++;
        }
    }
    return erros;
}

int letraexiste(char letra) {
	int j;
    // Olha letra a letra da palavra secreta e ve se encontra o chute aqui.
    for(j = 0; j < strlen(palavrasecreta); j++) {
        if (letra == palavrasecreta[j]) {
            return 1;
        }
    }
    return 0;
}

int main() {
	abertura();
	escolhepalavra();

	do {
		desenhaforca();

		chuta();
	} while (!ganhou() && !enforcou());
	
	adicionapalavra();
}
