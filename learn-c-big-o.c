#include <stdio.h>

int main()
{

    // Variable Initialization
    int nbTerms = 0;
    double coefficent = 0;
    int n0 = 1;

    // Number of Terms
    printf("\nE.g, f(n) = 2n + 5 + 3logn. This function has 3 terms.\n");
    printf("How many terms are in the function: ");
    scanf("%d", &nbTerms);
    printf("F(n) has %d terms\n", nbTerms);

    // Initialize Array
    int terms[nbTerms][3]; // [i][0]=coefficient, [i][1]=powerOfN, [i][2]=isLogn

    // Fill the array
    for (int i = 0; i < nbTerms; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
                printf("Term %d - coefficient: ", i + 1);
            else if (j == 1)
                printf("Term %d - power of n: ", i + 1);
            else
                printf("Term %d - is log n (1/0): ", i + 1);

            scanf("%d", &terms[i][j]);
        }
        // Calculate coefficent (c)
        coefficent += terms[i][0];

        // n-log-n, the first 'n' can only be of power 1 if there is a log-n in the term.
        if (terms[i][2] == 1 && terms[i][1] > 1)
        {
            printf("Only n log n is supported, using n power 1 for term %d.\n", i + 1);
            terms[i][1] = 1;
        }

        // n0 will be set to 2 if one term has a log-n
        if (terms[i][2] == 1)
            n0 = 2;
    }

    printf("The c is %lf\n", coefficent);
    printf("The n0 is %d\n", n0);

    // Show the array
    for (int i = 0; i < nbTerms; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("(%d)\n", terms[i][j]);
        }
    }

    return 0;
}