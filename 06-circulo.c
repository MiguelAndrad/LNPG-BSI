#include <stdio.h>

#define PI 3.14159

int main(void) {
    float raio;

    printf("Raio: ");
    scanf("%f", &raio);

    printf("Area: %.2f\n", PI * raio * raio);

    return 0;
}
