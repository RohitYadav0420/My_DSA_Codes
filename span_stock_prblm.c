#include <stdio.h>
#include <conio.h>

int main()
{
    int p[100], s[100], i, j, n;
    printf("enter no.of price quotes: ");
    scanf("%d", &n);
    printf("enter values of price quotes: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);
    for (i = 1; i < n; i++)
    {
        s[0] = 1;
        s[i] = s[0];
        j = i - 1;

        while (j >= 0 && p[j] <= p[i])
        {
            s[i]++;
            j--;
        }
    }
    printf("Span stock price's of given array of price's are: ");
    for (i = 0; i < n; i++)
        printf("%d ", s[i]);

    return 0;
}