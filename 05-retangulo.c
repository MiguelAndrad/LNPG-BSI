#include <stdio.h>

int main(void) {
    float base, altura;

    printf("Base e altura: ");
    scanf("%f %f", &base, &altura);

    printf("Area: %.2f\n", base * altura);
    printf("Perimetro: %.2f\n", 2 * (base + altura));

    return 0;
}
