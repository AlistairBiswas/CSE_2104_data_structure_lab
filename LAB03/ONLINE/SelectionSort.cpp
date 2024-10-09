#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n=5;
    int a[n] = {1,23,6,33,10};
    for(int i=0;i<n-1;i++)
    {
        int m=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[m])
            {
                m = j;
            }
        }
        if(m!=i)
        {
            t = a[i];
            a[i] = a[m];
            a[m] = t;
        }
    }

    for(int i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<endl;

    return 0;
}
