#include<bits/stdc++.h>
using namespace std;

int graph[200][200];
int visited[100];

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

bool isEmpty()
{
    if(head == NULL)
    {

        return 1;
    }

    return 0;
}


void bfs(int start, int n)
{

    enqueue(start);
    visited[start] = 1;

    while(!isEmpty())
    {
        int pop = dequeue();
        cout << pop+1 << " ";
        for(int i=0; i<n; i++)
        {
            if(!visited[i] && graph[pop][i])
            {
                visited[i] = 1;
                enqueue(i);

            }

        }
    }
}
int main()
    {

        int n,e;
        cout<<"Node : ";
        cin>>n;
        cout<<"Edge : ";
        cin>>e;

        int source,dest,we;
        for(int i=1; i<=e; i++)
        {
            cin>>source>>dest>>we;
            graph[source][dest]=we;
            graph[dest][source]=we;

        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cout<<"\t"<<graph[i][j];
            }
            cout<<endl;

        }
        int start;
        cout<<"Enter start : ";
        cin>>start;

        bfs(start, n);
    }
