#include <stdio.h>

int main(void) {
    char c;

    printf("Um caractere: ");
    c = getchar();

    /* O char ja guarda o codigo ASCII: %c mostra o caractere, %d o numero */
    printf("Codigo ASCII de %c: %d\n", c, c);

    return 0;
}
