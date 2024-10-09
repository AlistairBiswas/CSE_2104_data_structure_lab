#include<stdio.h>
void main()
{
    int A[10] = {5,3,1,3,2,0,1,3,2,0};
    int T[6]= {0,0,0,0,0,0};
    for(int i=0; i<10; i++)
    {
        int j=A[i];
        T[j]=T[j]+1;
    }
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<T[i]; j++)
            printf("%d",i);
    }
}
