#include <stdio.h>

int main(void) {
    int total;

    printf("Total de segundos: ");
    scanf("%d", &total);

    printf("%dh %dmin %ds\n", total / 3600, (total % 3600) / 60, total % 60);

    return 0;
}
