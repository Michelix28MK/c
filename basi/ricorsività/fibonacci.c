#include <stdio.h>

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    printf("Chiamata ricorsiva\n");
    if (n <= 1) {
        printf("Caso base\n");
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
    } else {
        printf("Fibonacci series up to %d terms:\n", n);
        for (int i = 0; i < n; ++i) {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }

    return 0;
}
