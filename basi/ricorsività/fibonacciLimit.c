#include <stdio.h>

// Recursive function to print Fibonacci numbers up to a limit
void fibonacciUpToLimit(int a, int b, int limit) {
    if (a <= limit) {
        printf("%d ", a);
        fibonacciUpToLimit(b, a + b, limit);
        printf("Chiamata ricorsiva\n");
    }
    printf("Caso base\n");
}

int main() {
    int n;

    printf("Enter the limit (n) for Fibonacci numbers: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1; // Indicates an error
    }

    printf("Fibonacci numbers up to %d are: ", n);
    fibonacciUpToLimit(0, 1, n);

    return 0; // Indicates successful execution
}
