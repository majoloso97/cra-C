#include <cs50.h>
#include <stdio.h>

int main(void) {
    int n;
    while (n < 1) {
        n = get_int("Height: ");
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        printf("\n");
    }
}
