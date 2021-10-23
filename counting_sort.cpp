#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter length of array: ";
    cin>>n;
    int a[n+1];
    cout<<"enter elements of array: \n";
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<"\n\ngiven array is: ";
    for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";
    cout<<"\n\n";
    int max=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]>max)
        max=a[i];
    }
    int k=max;
    int c[k+1];
    for(int i=0;i<=k;i++)
    c[i]=0;
    for(int i=1;i<=n;i++)
    {
        c[a[i]]++;
    }

    cout<<"frequency array is: ";
    for(int i=0;i<=k;i++)
    cout<<c[i]<<" ";
    cout<<"\n\n";
    for(int i=1;i<=k;i++)
    c[i]=c[i]+c[i-1];

    cout<<"cummulative frequency array is: ";
    for(int i=0;i<=k;i++)
    cout<<c[i]<<" ";
    cout<<"\n\n";

    int b[n+1];

    for(int i=n;i>=1;i--)        //counting sort is stable sort so from n we go down to 1.
    {
        b[c[a[i]]]=a[i];
        c[a[i]]--;

    }

    cout<<"sorted array is: ";
    for(int i=1;i<=n;i++)
    cout<<b[i]<<" ";

    return 0;

}