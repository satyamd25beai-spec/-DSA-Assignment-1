
#include <stdio.h>

#define MAX 100

typedef struct {
    int row, col, value;
} Term;

void fast_transpose(Term a[], Term b[]) {
    int row_terms[MAX] = {0};
    int starting_pos[MAX] = {0};
    int i, j;
    int num_cols = a[0].col;
    int num_terms = a[0].value;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = num_terms;

    if (num_terms == 0)
        return;

    for (i = 1; i <= num_terms; i++)
        row_terms[a[i].col]++;

    starting_pos[0] = 1;

    for (i = 1; i < num_cols; i++)
        starting_pos[i] =
            starting_pos[i - 1] + row_terms[i - 1];

    printf("\nrow_terms: ");
    for (i = 0; i < num_cols; i++)
        printf("%d ", row_terms[i]);

    printf("\nstarting_pos: ");
    for (i = 0; i < num_cols; i++)
        printf("%d ", starting_pos[i]);

    for (i = 1; i <= num_terms; i++) {
        j = starting_pos[a[i].col]++;

        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
    }
}

void display(Term a[]) {
    int i;

    printf("Row Col Value\n");

    for (i = 0; i <= a[0].value; i++)
        printf("%3d %3d %5d\n",
               a[i].row, a[i].col, a[i].value);
}

int main() {
    Term a[MAX], b[MAX];
    int rows, cols, i, j, x, count = 0;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 || cols <= 0 ||
        rows >= MAX || cols >= MAX) {
        printf("Invalid matrix dimensions.\n");
        return 1;
    }

    printf("Enter matrix elements:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &x);

            if (x != 0) {
                if (count >= MAX - 1) {
                    printf("Too many non-zero elements.\n");
                    return 1;
                }

                count++;
                a[count].row = i;
                a[count].col = j;
                a[count].value = x;
            }
        }
    }

    a[0].row = rows;
    a[0].col = cols;
    a[0].value = count;

    printf("\nOriginal triples:\n");
    display(a);

    fast_transpose(a, b);

    printf("\n\nTransposed triples:\n");
    display(b);

    printf("\nFast transpose completed.\n");

    return 0;
}
