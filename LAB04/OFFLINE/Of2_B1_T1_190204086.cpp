#include<bits/stdc++.h>
using namespace std;

void swapp(int a[],int i,int j)
{
    int t = a[j];
    a[j] = a[i];
    a[i] = t;
}

void quickSort(int a[],int f,int l)
{

    if(f<l)
    {
        int i = f+1,j = l;
        while(a[i]<a[f])
            i++;

        while(a[j]>a[f])
            j--;

        while(i<j)
        {
            swapp(a,i,j);

            while(a[i]<a[f])
                i++;

            while(a[j]>a[f])
                j--;
        }

        swapp(a,j,f);

        quickSort(a,f,j-1);
        quickSort(a,j+1,l);
    }

}

int main()
{
    int n;
    cout<<"Enter Array Size : ";
    cin>>n;
    int a[n];
    cout<<"Enter Array Inputs :"<<endl;
    for(int i=0; i<n; i++)
        cin>>a[i];

    quickSort(a,0,n-1);

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}


