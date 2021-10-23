#include<stdio.h>
#include<conio.h>

int main()
{
    int arr[100], i, j, n, temp;

    printf("enter no.of elements in array: ");
    scanf("%d",&n);
    printf("enter elements of array: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

    }
    printf("array before sorting: ");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("\n\narray after sorting: ");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    return 0;
}