#include<bits/stdc++.h>
using namespace std;

string arr[100];
int top = -1;

void browse(string x)
{
    //Browse a new website
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
    //Go to the previous website
    if(top==-1)
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {

        top--;

    }
}

void frwd()
{
    //Go to the next website
    if(top==100-1)
    {
        cout<<"Invalid"<<endl;
    }
    else
    {
        top++;
    }
}

void curWebsite()
{
    //This functions print the current browsing website
    cout<<"\nCurrent Website: "<<arr[top]<<endl;

}
void printOptions()
{
    printf("\n\n1.Browse\n2.bck\n3.frwd\n4.Current Website\n5.End\n\n");
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
            browse(x);
            curWebsite();
            break;
        }
        case 2:
        {
            bck();
            curWebsite();
            break;
        }
        case 3:
        {
            frwd();
            curWebsite();
            break;
        }
        case 4:
        {
            curWebsite();
            break;
        }
        case 5:
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
