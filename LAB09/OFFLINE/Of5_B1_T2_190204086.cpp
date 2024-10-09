#include<bits/stdc++.h>
using namespace std;

int graph[200][200];
int visited[100];


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
bool isEmpty()
{
    if(head == NULL)
    {
        return 1;
    }

    return 0;
}

void dfs(int start,int n){

    push(start);
    visited[start] = 1;

    while(!isEmpty()){
        int p = pop();
        cout << p+1 << " ";
        for(int i=0; i<n; i++){
            if(!visited[i] && graph[p][i]){
                visited[i] = 1;
                push(i);
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

    dfs(start, n);
}


