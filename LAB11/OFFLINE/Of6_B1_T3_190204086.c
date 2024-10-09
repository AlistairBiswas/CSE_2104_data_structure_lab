#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node*right;

};

struct node *Delete(struct node *root,int data)
{

    if(root == NULL)
    {
        return root;
    }

    else if (data  <  root->data)
    {
        root->left=Delete(root->left,data);

    }
    else if (data > root->data)
    {
        root->right=Delete(root->right,data);
    }

    else
    {


        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root=NULL;

        }

        else if(root->left ==NULL)
        {
            struct node *temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL)
        {
            struct node* temp=root;
            root=root->left;
            free(temp);
        }

        else
        {
            struct node *temp=Find_Min(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp-> data);
        }
        return root;
    }
}

int Find_Min(struct  node*root)
{
    if(root==NULL)
    {
        return -1;
    }
    while(root->left != NULL)
    {
        root=root->left;
    }
    return root->data;
}

struct node* create_node(int value)
{
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("  %d  ", root->data);
        inorder(root->right);
    }
}


struct node* insert(struct node* node, int key)
{

    if (node == NULL)
        return create_node(key);


    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);


    return node;
}



int main()
{

    struct node* root = NULL;
    root = insert(root, 20);
    insert(root, 5);
    insert(root, 10);
    insert(root, 25);
    insert(root, 34);
    insert(root, 27);
    insert(root, 18);

    printf("The tree is :\n");
    inorder(root);
    printf("\n");

    printf("Enter the number you want to delete :\n");
    int del;
    scanf("%d",&del);


    Delete(root,del);

    printf("\n After deleting %d \n The tree is :\n",del);
     inorder(root);


    return 0;
}
