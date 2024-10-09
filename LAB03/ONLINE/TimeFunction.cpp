#include <bits\stdc++.h>
#include<time.h>
using namespace std;

int main()
{
	clock_t st,et;

	st = clock();
	for(int i=0;i<10000;i++)
		for(int j=0;j<10000;j++)

	et = clock();

	double t = (double)(et-st)/CLOCKS_PER_SEC;

	cout<<t<<endl;

	return 0;
}
