#include<bits/stdc++.h>

using namespace std;

string arr[100];
int top = -1;

void cd(string x)
{
     if(top==100-1)
        cout<<"stack is full"<<endl;
    else
    {
        top++;
        arr[top]=x;
    }
}

void bck()
{
 if(top==-1)
    {
        cout<<"stack is empty"<<endl;
        return ;
    }
    else
    {

        top--;

    }
}

void pwd()
{
    for(int i=0; i<=top; i++)
    {
        cout<<arr[i]<<"\\";
    }
    cout<<endl;
}
void printOptions()
{
    printf("\n\n1.cd\n2.bck\n3.pwd\n4.End\n");
    printf("Provide your choice: ");
}

int main()
{
    while(true)
    {
        int choice;
        bool needEnd = false;
        printOptions();
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
        {
            string x;
            cin>>x;
            cd(x);
            pwd();
            break;
        }
        case 2:
        {
            bck();
            pwd();
            break;
        }
        case 3:
        {
            pwd();
            break;
        }
        case 4:
        {
            needEnd = true;
            break;
        }
        default:
            printf("Invalid choice try Again.");
        }

        if(needEnd)
            break;
    }

    return 0;
}

