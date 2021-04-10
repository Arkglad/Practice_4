#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//ВАРИАНТ 4

int main() {

    srand(time(NULL));
    int a, b, i, j, n, max1, max2, sum = 0;
    int **mass;
    printf("Введите размер массива: ");
    scanf("%d", &n);
    mass = (int **) calloc(n, sizeof(int *));

    for (i = 0; i < n; i++) {
        mass[i] = (int *) calloc(n, sizeof(int));
        for (j = 0; j < n; j++) {
            mass[i][j] = rand() % (10 - (-10) + 1) - 10;
            printf("%d\t", mass[i][j]);
        }
        printf("\n");
    }
    max1 = mass[0][0];
    max2 = mass[0][0];

    printf("\n\n");

    printf("Суммы над главной диагональю: \n");
    for (j = 1; j < n; j++) {
        for (i = 0, b = j; b < n; i++, b++) {
            sum += mass[i][b];
        }
        printf("%d\n", sum);
        if (sum > max1) {
            max1 = sum;
        }
        sum = 0;
    }
    printf ("Максимальная сумма над главной диагональю: %d\n", max1);

    printf("Суммы под главной диагональю: \n");
    for (j = 1; j < n; j++) {
        for (i = 0, b = j; b < n; i++, b++) {
            sum += mass[b][i];
        }
        printf("%d\n", sum);
        if (sum > max2) {
            max2 = sum;
        }
        sum = 0;
    }
    printf ("Максимальная сумма под главной диагональю: %d\n", max2);

    printf("\n");

    printf ("Максимальная сумма элементов параллельных диагоналей: ");
    if (max1 >= max2) {
        printf ("%d\n", max1);
    }
    else {
        printf ("%d\n", max2);
    }

    return 0;
}
