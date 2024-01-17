#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int *px, *py, *c;
    int a = 0, b = 1;

    px = &a;
    py = &b;

    printf("\nPX = %d PY = %d", *px, *py);
    
    c = px;
    px = py;
    py = c;

    printf("\nPX = %d PY = %d", *px, *py);

    char *ps, *pq, *x;

    char s[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};;
    char q[] = {'t', 'r', 'n', 'm', 'b', 'v', '\0'};

    ps = s;
    pq = q;

    printf("\n ps = %s pq = %s", ps, pq);

    x = ps;
    ps = pq;

    pq = x;

    printf("\n ps = %s pq = %s", ps, pq);

    return 0;
}