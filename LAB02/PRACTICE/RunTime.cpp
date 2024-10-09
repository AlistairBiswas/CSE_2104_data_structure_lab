#include<iostream>
#include<time.h>
using namespace std;
int main()
{
    int i,j;
    clock_t start_time, end_time;
    double run_time;

    start_time = clock();
    for(i=0;i<10000;i++)
        for(j=0;j<9999;j++)

    end_time = clock();

    run_time = (double) (end_time - start_time)/CLOCKS_PER_SEC;
    cout<<"A"<<endl;
    cout<<run_time<<endl;

    return 0;
}
