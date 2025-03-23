#include <stdio.h>
#include "calculator.h"

int main() {
    int choice, a, b;

    printf("Simple Calculator\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    switch (choice) {
        case 1:
            printf("Result: %d\n", add(a, b));
            break;
        case 2:
            printf("Result: %d\n", subtract(a, b));
            break;
        case 3:
            printf("Result: %d\n", multiply(a, b));
            break;
        case 4:
            if (b == 0) {
                printf("Error: Division by zero!\n");
            } else {
                printf("Result: %d\n", divide(a, b));
            }
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
