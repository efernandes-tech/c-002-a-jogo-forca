# c-002-a-jogo-forca
Jogo da forca em C. (projeto prático)

##### Anotações:

1 - O espaço " " antes do "%c" resolve o problema do enter.
    scanf(" %c", &chute);
2 - Ele escreve "MELANCIA\0", pq o "\0" informa que acabou a palavra.
	sprintf(palavrasecreta, "MELANCIA");
3 - O compilador dispara um erro quando ele encontra uma função que ainda não foi declarada.
    3.1 - A solução e fazer somente a declaração da função em um arquivo header file e incluilo no topo do arquivo de classe:
        teste.h
		    void chuta();
		teste.c
		    #include "teste.h"
    	    int teste() {
    	        ...
            }
4 - Sempre feche o arquivo aberto com "fopen()" e "fclose()", se não a maquina não salva alterações.
