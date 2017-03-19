#include <stdio.h>

void abertura(int multiplicador) {
    printf("Tabuada do %d\n", multiplicador);
}

int main() {
    int multiplicador = 2;

    abertura(multiplicador);

	int i;
    for(i = 1; i <= 10; i++) {
        int resultado = multiplicador * i;
        printf("%d x %d = %d\n", i, multiplicador, resultado);
    }
}
