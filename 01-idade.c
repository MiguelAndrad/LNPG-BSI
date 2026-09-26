#include <stdio.h>

#define ANO_ATUAL 2026

int main(void) {
    int ano;

    printf("Ano de nascimento: ");
    scanf("%d", &ano);

    printf("Idade: %d\n", ANO_ATUAL - ano);

    return 0;
}
