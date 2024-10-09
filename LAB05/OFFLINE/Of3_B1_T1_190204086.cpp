#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
Node* head,*node1,*temp,*temp2;

void insert(int x)
{
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void createList(int arr[],int len)
{
    /*Create a Linked list using the global head and supplied array*/
    int i = len;
    while(i >= 0)
    {
        insert(arr[i]);
        i--;
    }

}
void nodeInsert(int node, int choice)
{
    /*Add an element to the created list based on the choice given below
        choice = 0,
            Add a node before the first node of the list.
        choice = Any positive number,
            Insert a node in between choice-1 and choice+1 position of the list.
        choice = -1, Add a node at the end of the list.*/
    if(choice ==0)
    {
        node1 = (struct Node*)malloc(sizeof(struct Node));
        node1->data = node;
        node1->next =head;
        head = node1;
    }
    else if(choice ==-1)
    {
        temp = head;
        while(temp->next!=0 )
        {
            temp = temp->next;
        }
        node1 = (struct Node*)malloc(sizeof(struct Node));
        temp->next=node1;
        temp->data = node;
        temp->next =0;
    }
    else
    {
        int c=1;
        node1=head;
        temp2=NULL;
        while(node1!=NULL)
        {
            if(c+1==choice)
            {
                temp=node1;
            }

            if(c==choice)
            {
                temp2=node1;
            }
            node1=node1->next;
            c++;
        }


        node1= (struct Node*)malloc(sizeof(struct Node));
        node1->data =node;
        node1->next=temp2;
        temp->next=node1;
    }

}
void nodeDelete(int choice)
{
    /*Add an element to the created list based on the choice given below
        choice = 0,
            Delete the first node of the linked list.
        choice = Any positive number,
            Delete the node in between choice-1 and choice+1 position.
        choice = -1, Delete the last node of the list.*/
    Node *temp1=head;
    Node *temp2;
    if(choice==0)
    {
        head=temp1->next;
        free(temp1);
        return;
    }
    if(choice==-1)
    {
        int count=0;
        while(temp1!=NULL)
        {
            temp1=temp1->next;
            count++;
        }
        choice=count-1;
        temp1=head;

    }

    int i;
    for(i=0; i<=choice-2; i++)
        temp1=temp1->next;

    temp2=temp1->next;
    temp1->next=temp2->next;
    free(temp2);

}
bool nodeSearch(int node)
{
    /*Search the given node in the linked list*/

    Node* temp = head;
    while(temp->next != NULL)
    {
        if(temp->data==node)
            return true;
        temp  = temp->next;
    }

}
void print()
{
    Node* temp = head;
    cout << "\nList is:";
    while(temp != NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void printChoice()
{
    cout<<"\n1. Node Insert\n" << "2. Node Delete\n"<<
        "3. Node Search\n"<<"4. Print the list\n"<<
        "5. Program Exit\n"<<"Your Choice: ";
}
void printChoice2()
{
    cout<<"\nFor first node enter 0\n" << "For any node enter the position\n"
        <<"For last node enter -1\n"<<"Your Choice: ";
}
int main()
{
    head = NULL;

    //Initialization of a list
    int arr[] = {1,5,8,7,9,2,4,3};
    int len = sizeof(arr)/sizeof(arr[0]);

    createList(arr,len);

    while(true)
    {
        printChoice();
        int x, node, choice;
        cin>>x;
        switch(x)
        {
        case 1:
            cout<<"\nNode value: ";
            cin>>node;

            printChoice2();
            cin>>choice;

            nodeInsert(node,choice);
            break;
        case 2:
            printChoice2();
            cin >> choice;

            nodeDelete(choice);
            break;
        case 3:
            cout<<"\nNode value: ";
            cin>>node;

            cout<<"\nSearch Result(1/0): "<<nodeSearch(node)<<endl;
            break;
        case 4:
            print();
            break;
        case 5:
            return 0;
        default:
            cout << "Wrong Choice....\n";
        }

    }
}

