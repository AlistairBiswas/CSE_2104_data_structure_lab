#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int main()
{
    clock_t st,et;

	st = clock();

    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int f=0,l=n-1,m;


    while(l>=f)
    {

        m = (f+l)/2;
        if(a[m]==x)
        {
            cout<<m+1<<endl;
            return 0;
        }
        else if(x>a[m])
            f = m+1;
        else
            l = m-1;
    }
    et = clock();

    double t = (double)(et-st)/CLOCKS_PER_SEC;

	cout<<t<<endl;
	return 0;

}

