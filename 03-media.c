#include <stdio.h>

int main(void) {
    float n1, n2, n3, media;

    printf("Tres notas: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    /* Como as notas sao float, a divisao por 3 e real */
    media = (n1 + n2 + n3) / 3;

    printf("Media: %.2f\n", media);

    return 0;
}
