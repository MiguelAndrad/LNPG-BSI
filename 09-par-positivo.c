#include <stdio.h>

int main(void) {
    int n;

    printf("Um inteiro: ");
    scanf("%d", &n);

    /* Em C, a expressao vale 1 (verdadeiro) ou 0 (falso) */
    printf("Par e positivo? %d\n", (n % 2 == 0) && (n > 0));

    return 0;
}
