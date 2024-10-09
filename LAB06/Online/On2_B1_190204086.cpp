#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* createList(int arr[],int len)
{
    Node* hd = new Node();
    hd->data = arr[0];
    hd->next = NULL;

    Node* temp = hd;

    for (int i = 1; i < len; i++)
    {
        Node* newNode = new Node();
        newNode->data = arr[i];
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }
    return hd;
}

Node* sortedMerge(Node* list1, Node* list2)
{
    //write your code from below
    Node demo;
    Node* tail = &demo;
    demo.next = NULL;
    while(1)
    {
        if(list1 == NULL)
        {
            tail-> next = list2;
            break;
        }
        else if(list2 == NULL)
        {
            tail-> next = list1;
            break;
        }
        if(list1->data <= list2 -> data)
            MoveNode(&(tail->next))
            else
                MoveNode(&(tail -> next))
                tail = tail->next;
    }
    return (demo.next);
}

void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    int arr1[] = {1,5,20,100};
    int arr1Len = sizeof(arr1)/sizeof(arr1[0]);
    Node* ll1 = createList(arr1,arr1Len);
    print(ll1);

    int arr2[] = {2,10,50,250,725};
    int arr2Len = sizeof(arr2)/sizeof(arr2[0]);
    Node* ll2 = createList(arr2,arr2Len);
    print(ll2);

    cout<<"New List: ";
    Node* newll = sortedMerge(ll1,ll2);
    print(newll);

    return 0;
}
