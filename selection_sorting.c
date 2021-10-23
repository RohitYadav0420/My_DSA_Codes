#include<stdio.h>
#include<conio.h>

int main()
{
    int arr[100],i,j,n,max,max_index,temp;

    printf("enter no.of elements in array: ");
    scanf("%d",&n);
    printf("enter elements of array: \n");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("array before sorting: ");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    for(i=0;i<n-1;i++)
    { 
        max=arr[0];
        max_index=0;
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j+1]>max)
            {
                max=arr[j+1];
                max_index=j+1;
            }
        }
        temp=arr[n-1-i];
        arr[n-1-i]=max;
        arr[max_index]=temp;
         

    }
   printf("\n\n arrary after sorting: ");
   for(i=0;i<n;i++)
   printf("%d ",arr[i]);

   return 0;

}