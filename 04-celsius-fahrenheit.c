#include <stdio.h>

int main(void) {
    float c, f;

    printf("Celsius: ");
    scanf("%f", &c);

    /* c * 9 e avaliado primeiro (float), entao a divisao por 5 ja e real */
    f = c * 9 / 5 + 32;

    printf("Fahrenheit: %.1f\n", f);

    return 0;
}
