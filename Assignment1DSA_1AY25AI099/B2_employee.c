
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int emp_id;
    int type;

    union {
        float salary;
        struct {
            float hourly_rate;
            int hours_worked;
        } contract_info;
    } pay;
} Employee;

int main() {
    int n, i;
    float total = 0, amount;
    Employee *e;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of employees.\n");
        return 1;
    }

    e = malloc(n * sizeof(Employee));

    if (e == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter name and employee ID: ");
        scanf("%19s %d", (e+i)->name, &(e+i)->emp_id);

        printf("Enter type (0 = Full-time, 1 = Contract): ");
        scanf("%d", &(e+i)->type);

        if ((e+i)->type == 0) {
            printf("Enter monthly salary: ");
            scanf("%f", &(e+i)->pay.salary);
        } else {
            printf("Enter hourly rate and hours worked: ");
            scanf("%f %d",
                  &(e+i)->pay.contract_info.hourly_rate,
                  &(e+i)->pay.contract_info.hours_worked);
        }
    }

    printf("\n--- Employee Payslips ---\n");

    for (i = 0; i < n; i++) {
        if ((e+i)->type == 0) {
            amount = (e+i)->pay.salary;
            printf("%s: Full-time, Pay = %.2f\n",
                   (e+i)->name, amount);
        } else {
            amount = (e+i)->pay.contract_info.hourly_rate *
                     (e+i)->pay.contract_info.hours_worked;

            printf("%s: Contract, Pay = %.2f\n",
                   (e+i)->name, amount);
        }

        total += amount;
    }

    printf("Total salary bill = %.2f\n", total);

    free(e);
    return 0;
}
