#include<iostream>
using namespace std;
int linearsearch(int elements[], int maxsize, int key)
{
    int i, j, temp;
    for (i = 0; i < maxsize ; i++)
    {
        if (key == elements[i])
            return i;
    }
    return -1;
}
int main()
{
    int maxsize, key;
    int i, pos;
    cout<<"Number of Elements:";
    cin>>maxsize;
    cout<<"\nKey: ";
    cin>>key;
    int elements[maxsize];
    cout<<"\nValues: ";
    for (i = 0; i < maxsize; i++)
    {
        cout<<"\nElement "<<i<<" ";
        cin>>elements[i];
    }
    pos = -1;
    pos = linearsearch(elements, maxsize, key);
    if (pos != -1)
        cout<<"\nThe key "<<key<<" is found at position "<< pos;
    else
        cout<<"\nThe key is not found in the list";
}
