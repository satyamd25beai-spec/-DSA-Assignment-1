
#include <stdio.h>

#define MAX 100

typedef struct {
    int degree;
    float coef[MAX + 1];
} Polynomial;

Polynomial add(Polynomial a, Polynomial b) {
    Polynomial c;
    int exp, max;

    max = (a.degree > b.degree) ? a.degree : b.degree;
    c.degree = max;

    for (exp = 0; exp <= max; exp++) {
        float x = 0, y = 0;

        if (exp <= a.degree)
            x = a.coef[a.degree - exp];

        if (exp <= b.degree)
            y = b.coef[b.degree - exp];

        c.coef[max - exp] = x + y;
    }

    return c;
}

void display(Polynomial p) {
    int i, exp, first = 1;
    float value;

    for (i = 0; i <= p.degree; i++) {
        value = p.coef[i];
        exp = p.degree - i;

        if (value == 0)
            continue;

        if (!first)
            printf(value > 0 ? " + " : " - ");
        else if (value < 0)
            printf("-");

        if (value < 0)
            value = -value;

        if (exp == 0)
            printf("%g", value);
        else if (exp == 1)
            printf("%gx", value);
        else
            printf("%gx^%d", value, exp);

        first = 0;
    }

    if (first)
        printf("0");

    printf("\n");
}

int main() {
    Polynomial a = {4, {3, 0, 2, 0, 1}};
    Polynomial b = {3, {5, 0, -2, 4}};
    Polynomial c;

    printf("Polynomial A: ");
    display(a);

    printf("Polynomial B: ");
    display(b);

    c = add(a, b);

    printf("Sum: ");
    display(c);

    return 0;
}
