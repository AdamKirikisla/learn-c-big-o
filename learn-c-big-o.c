#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    // Variable Initialization
    int nbTerms = 0;
    double coefficent = 0;
    int n0 = 1;
    char gn[][10] = {"1", "log-n", "n", "n-log-n", "n^"};
    char bigO[20] = "";
    int bestPow = 0, bestLog = 0;

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
        coefficent += abs(terms[i][0]);

        // n-log-n, the first 'n' can only be of power 1 if there is a log-n in the term.
        if (terms[i][2] == 1 && terms[i][1] > 1)
        {
            printf("Only n log n is supported, using n power 1 for term %d.\n", i + 1);
            terms[i][1] = 1;
        }

        // n0 will be set to 2 if one term has a log-n
        if (terms[i][2] == 1)
            n0 = 2;

        // Track the dominant term (highest power of n, then log-n as tie-breaker)
        int p = terms[i][1], l = terms[i][2];
        if (p > bestPow || (p == bestPow && l > bestLog))
        {
            bestPow = p;
            bestLog = l;
        }
    } // Close outer loop

    // Choose bigO
    if (bestPow == 0 && bestLog == 0)
        strcpy(bigO, gn[0]);
    else if (bestPow == 0 && bestLog == 1)
        strcpy(bigO, gn[1]);
    else if (bestPow == 1 && bestLog == 0)
        strcpy(bigO, gn[2]);
    else if (bestPow == 1 && bestLog == 1)
        strcpy(bigO, gn[3]);
    else
        snprintf(bigO, sizeof bigO, "n^%d", bestPow);

    printf("The c is %lf\n", coefficent);
    printf("The n0 is %d\n", n0);
    printf("f(n) is O(%s)\n", bigO);

    return 0;
}