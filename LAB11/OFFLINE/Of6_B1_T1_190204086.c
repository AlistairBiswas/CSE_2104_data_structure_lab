#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data ;
    struct node *left,*right;
    struct node*parent;
};

struct node *root;


struct node *create_node(int val)
{

    struct node *newnode=(struct node *)malloc(sizeof(struct node));

    newnode->data=val;
    newnode->parent=NULL;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

void left_child(struct node *temp, struct node* child)
{

    temp->left=child;
    if(child!=NULL)
    {
        child->parent=temp;
    }


}

void right_child(struct node *temp, struct node* child)
{

    temp->right=child;
    if(child!=NULL)
    {
        child->parent=temp;
    }


}
struct node *insert(struct node *temp, struct node * n )
{
    struct node *parent_node, *current_node;
    if(temp==NULL)
    {
        temp=n;
        return temp;
    }
                parent_node=NULL;
                current_node=temp;

    while(current_node!= NULL)
    {
        parent_node=current_node;
        if(n->data  <  current_node->data)
        {
            current_node=current_node->left;
        }
        else
        {
            current_node=current_node->right;
        }
    }
    if(n->data  <parent_node->data)
    {
        left_child(parent_node,n);
    }
    else
    {
        right_child(parent_node,n);
    }
    return temp;
}

struct node *create_bst()
{
    struct node *temp,*node;

    int i;
    int ara[]= {56,74,33,7,0,19,1,49};
    temp=create_node(50);
    for(i=0; i<8; i++)
    {
        node=create_node(ara[i]);
        root=insert(temp,node);
    }
}

void inorder(struct node *curr)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    if (curr->left != NULL)
        inorder(curr->left);
    printf("  %d   ", curr->data);
    if (curr->right != NULL)
        inorder(curr->right);
}


int main()
{
     root =create_bst();
     inorder(root);

    printf("\n");
    return 0;

}
