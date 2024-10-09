#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n=29;
    int a[n] = {50,30,20,11,17,56,89,89,54,26,35,78,14,23,24,25,26,47,85,1,4,56,87,8,2,1,45,65,47};
    for(int i=0;i<n-1;i++)
    {
        int m=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]>a[m])
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

