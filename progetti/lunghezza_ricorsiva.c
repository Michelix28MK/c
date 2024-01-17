#include <stdio.h>
#include <stdlib.h>

int lung(char* stringa)
{
    if (stringa == NULL)
    {
        return -1;
    }
    int i = 0;
    while (stringa[i] != '\0')
        i++;
    return i;
}

int main(void)
{
    char s[] = {"Viva la Figa"};
    printf("lunghezza della stringa: %d",lung(s));

    return 0;
}