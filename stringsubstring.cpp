#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int subsequence(string s, string output[])
{
    if(s.empty())
    {
        output[0]="";
        return 1;
    }

    int count= subsequence(s.substr(1), output);

    for(int i=0;i<count;i++)
    {
        output[i+count]=s[0]+output[i];
    }

    return 2*count ;
}

int main()
{
    string str;

    cin>>str;

    int n=pow(2, str.size());

    string name[n];

    subsequence(str, name);

    for(int i=0;i<n;i++)
    {
        cout<<name[i]<<endl;
    }

    return 0;

}