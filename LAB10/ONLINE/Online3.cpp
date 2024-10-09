#include<bits/stdc++.h>
using namespace std;

struct node
{
    int name;
    node* next;

    node(int _name)
    {
        name = _name;
        next = NULL;
    }
};
node* graph[10]; // graph[0..n] == NULL*/

void DFS(int start, int n)
{
    push(start);
    status[start]=2;
    while(!isEmpty())
    {
        int node= pop();

        status[node]=3;
        cout << node << " ";
        for(int i=1; i<=n; i++)
        {
            if(graph[node][i]&&status[i]==1)
            {
                push(i);
                status[i]=2;
            }
        }
    }
}

void inputGraph()
{
    int so, des;
    for(int i=1; i<=e; i++)
    {
        scanf("%d %d",&so,&des);
        graph[so][des]= true;

    }

}

int main()
{
    /*Lets say we have 3 nodes
        1 --> 2 -->3
    */

    node* n2 = new node(2);
    node* n3 = new node(3);

    graph[1]=n2;
    graph[2]=n3;

    inputGraph();


    for(int i=1;i<=3;i++)
    {
        node* temp = graph[i];
        cout<<i<<": ";
        while(temp!=NULL)
        {
            cout<<temp->name<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }


    return 0;
}
