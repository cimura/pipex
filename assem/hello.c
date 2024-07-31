#include <stdio.h>
#include <stdlib.h>

int main() {
    char *s = malloc(6);
    s = "hello";
    printf("%s\n", s);
    free(s);
    // free(s);
}