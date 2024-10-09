#include<bits/stdc++.h>
using namespace std;

typedef struct Node node;

struct Node
{
    int value;
    node *next;
};

node *head;

node *createNode(int value,node *next)
{
    node *newNode = (node*)malloc(sizeof(node));

    if(newNode == NULL)
    {
        perror("Can't create memory!\n");
        exit(1);
    }

    newNode->value = value;
    newNode->next = next;

    return newNode;
}


void enqueue(int value)
{
    if(head == NULL)
    {
        head = createNode(value,NULL);
        return;
    }
    node *newNode = createNode(value,NULL);
    node *currentNode = head;

    while(currentNode->next!=NULL)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;

    return;
}

int dequeue()
{
    if(head == NULL)
    {
        cout<<"No node to delete!"<<endl;
        return -1;
    }

    if(head->next == NULL)
    {
        int c = head->value;
        head = NULL;
        return c;
    }
    node *n = head;
    int c = n->value;
    head = n->next;
    free(n);
    return c;
}

int Size()
{
    node *currentNode = head;
    int c = 0;
    while(currentNode!=NULL)
    {
        c++;
        currentNode = currentNode->next;
    }
    return c;
}

void isEmpty()
{
    if(head == NULL)
    {
        cout<<"Empty!\n"<<endl;
        return;
    }
    cout<<"Not Empty!\n"<<endl;
    return;
}


int main()
{
    int n,num;
    while(1)
    {
        cout<<"What operation you want to do?"<<endl;
        cout<<"0. End 1. Enqueue, 2. Dequeue, 3. size, 4. checkEmpty"<<endl;
        cin>>n;
        switch(n)
        {
        case 0:
            return 0;
        case 1:
            cout<<"Enter number:"<<endl;
            cin>>num;
            enqueue(num);
            break;
        case 2:
            cout<<dequeue()<<endl;
            break;
        case 3:
            cout<<Size()<<endl;
            break;
        case 4:
            isEmpty();
            break;
        }
    }
}

