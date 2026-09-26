#include <stdio.h>

int main(void) {
    int a, b;

    printf("Dividendo e divisor: ");
    scanf("%d %d", &a, &b);

    /* Entre dois int, / ja e divisao inteira (equivale ao // do Python) */
    printf("Quociente: %d\n", a / b);
    printf("Resto: %d\n", a % b);

    return 0;
}
