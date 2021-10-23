#include <stdio.h>
#include <conio.h>

int main()
{
    int arr[100], i, j, key, n;
    printf("enter size of array: ");
    scanf("%d", &n);
    printf("enter elements of array: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("array before sorting: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("\n\narray after sorting: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}