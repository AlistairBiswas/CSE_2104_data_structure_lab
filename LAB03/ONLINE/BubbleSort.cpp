#include<iostream>
using namespace std;

void bubblesort(int arr[])
{
    int i, j, temp;
    for (i = 0; i < 5 - 1; i++)
    {
        for (j = i+1; j < 5; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main()
{

    int arr[] = {12,76,34,67,94};
    cout<<"Before sort:";
    for (int i = 0; i < 5; i++)
        cout<<arr[i]<<" ";
    bubblesort(arr);
    cout<<"\n";
    cout<<"After sort:";
    for (int i = 0; i < 5; i++)
        cout<<arr[i]<<" ";

}

