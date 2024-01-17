#include <stdio.h>
#include <stdlib.h>

int fgetss(char *str) {
    printf("\nInserisci la stringa: ");

    if (fgets(str, BUFSIZ, stdin) == NULL) {
        printf("Err:w");
        return -1;
    }

    int i = 0;
    for (; str[i] != '\n'; i++);
    str[i] = '\0';

    return 0;
}

int my_strlen(char *t) {
    char c;
    int i = 0;

    do {
        c = t[i];
        i++;
    } while (c != '\0');

    return i;
}

void ordina_stringhe(char *t[], int n) {
    int c;
    char *p;
    do {
        c = 1;
        for (int i = 1; i < n; i++) {
            if (my_strlen(t[i - 1]) > my_strlen(t[i])) {
                p = t[i - 1];
                t[i - 1] = t[i];
                t[i] = p;
                c = 0;
            }
        }
    } while (c == 0);
}

int main(void) {
    char str1[BUFSIZ], str2[BUFSIZ], str3[BUFSIZ], str4[BUFSIZ], str5[BUFSIZ];
    char *registro[5];

    fgetss(str1);
    fgetss(str2);
    fgetss(str3);
    fgetss(str4);
    fgetss(str5);

    registro[0] = str1;
    registro[1] = str2;
    registro[2] = str3;
    registro[3] = str4;
    registro[4] = str5;

    ordina_stringhe(registro, 5);

    for (size_t i = 0; i < 5; i++) {
        printf("\n%s\n", registro[i]);
    }

    return 0;
}
