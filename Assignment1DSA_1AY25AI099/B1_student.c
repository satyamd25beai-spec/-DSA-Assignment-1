
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int roll_no;
    char name[20];
    float marks;
} Student;

int main() {
    int n, i, add;
    float sum = 0;
    Student *ptr, *temp, *topper;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }

    ptr = malloc(n * sizeof(Student));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter roll, name, marks: ");
        scanf("%d %19s %f", &(ptr+i)->roll_no,
              (ptr+i)->name, &(ptr+i)->marks);
    }

    topper = ptr;
    for (i = 0; i < n; i++) {
        sum += (ptr+i)->marks;
        if ((ptr+i)->marks > topper->marks)
            topper = ptr+i;
    }

    printf("Average marks: %.2f\n", sum/n);
    printf("Topper: %s (Roll %d, Marks %.2f)\n",
           topper->name, topper->roll_no, topper->marks);

    printf("Add 2 more students? (1 = Yes, 0 = No): ");
    scanf("%d", &add);

    if (add == 1) {
        temp = realloc(ptr, (n+2) * sizeof(Student));
        if (temp == NULL) {
            printf("Reallocation failed.\n");
            free(ptr);
            return 1;
        }

        ptr = temp;
        for (i = n; i < n+2; i++) {
            printf("Enter roll, name, marks: ");
            scanf("%d %19s %f", &(ptr+i)->roll_no,
                  (ptr+i)->name, &(ptr+i)->marks);
        }

        n += 2;
        sum = 0;
        for (i = 0; i < n; i++)
            sum += (ptr+i)->marks;

        printf("Updated average marks: %.2f\n", sum/n);
    }

    free(ptr);
    return 0;
}
