#include <stdio.h>

int main()
{

    // Variable init
    int nbTerms = 0;
    int coefficent = 0;
    int n0 = 0;

    printf("\nE.g, f(n) = 2n + 5 + 3logn. This function has 3 terms.\n");
    printf("How many terms are in the function: ");
    scanf("%d", &nbTerms);
    printf("F(n) has %d terms\n", nbTerms);

    return 0;
}