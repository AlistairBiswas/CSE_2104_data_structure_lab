#include<bits/stdc++.h>
using namespace std;

typedef struct Node node;

struct Node{
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


void push(int value)
{
    if(head == NULL)
    {
        head = createNode(value,NULL);
        return;
    }
    node *newNode = createNode(value,NULL);
    newNode->next = head;
    head = newNode;

    return;
}

int pop()
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
        cout<<"0. End 1. Push, 2. Pop, 3. size, 4. checkEmpty"<<endl;
        cin>>n;
        switch(n)
        {
            case 0:
                return 0;
            case 1:
                cout<<"Enter number:"<<endl;
                cin>>num;
                push(num);
                break;
            case 2:
                cout<<pop()<<endl;
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

