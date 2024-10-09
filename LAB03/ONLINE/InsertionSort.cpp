#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n=5;
    int a[n] = {1,23,6,33,10};
    for(int i=1;i<n;i++)
    {
        t = a[i];
        int j = i-1;
        while(j>=0 && a[j]>t)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = t;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<endl;

    return 0;
}
