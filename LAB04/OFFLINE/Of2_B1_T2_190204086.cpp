#include<bits/stdc++.h>
using namespace std;

void mergee(int a[],int l,int m,int r);

void merge_sort(int a[],int l,int r)
{

    if(l>=r)
        return;

    int m = (r+l)/2;

    merge_sort(a,l,m);

    merge_sort(a,m+1,r);

    mergee(a,l,m,r);

}

void mergee(int a[],int l,int m,int r)
{

    int index_a,index_l,index_r;
    int size_l,size_r;

    size_l = m - l+1;
    size_r = r - m;

    int L[size_l], R[size_r];

    for(int i=0; i<size_l; i++)
        L[i] = a[l+i];

    for(int i=0; i<size_r; i++)
        R[i] = a[m+1+i];

    index_l=0,index_r=0;

    for(index_a = l; index_l<size_l && index_r<size_r; index_a++)
    {

        if(L[index_l]<R[index_r])
        {
            a[index_a] = L[index_l];
            index_l++;
        }
        else
        {
            a[index_a] = R[index_r];
            index_r++;
        }


    }


    while(index_l<size_l)
    {
        a[index_a] = L[index_l];
        index_l++;
        index_a++;
    }
    while(index_r<size_r)
    {
        a[index_a] = R[index_r];
        index_r++;
        index_a++;
    }

}


int main()
{
    int n;
    cout<<"Enter Array Size : ";
    cin>>n;
    int a[n];
    cout<<"Enter Array Size :"<<endl;
    for(int i=0; i<n; i++)
        cin>>a[i];

    merge_sort(a, 0, n-1);

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
