#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

int flag=1;

struct node* new_Node(int item)
{
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data= item;
    newnode->left = newnode->right = NULL;
    return newnode;
}


void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf(" %d   ", root->data);
        inorder(root->right);
    }
}


struct node* insert(struct node* node, int val)
{

    if (node == NULL)
        return new_Node(val);


    if(val == node->data){
        printf("Already Inserted\n");
        flag=0;
    }

    else if (val  <   node->data){
        node->left = insert(node->left, val);}

    else if (val   >   node->data){
        node->right = insert(node->right, val);
    }

    return node;
}


int main()
{

    struct node* root = NULL;
    root = insert(root, 27);
    insert(root, 10);
    insert(root, 12);
    insert(root, 24);
    insert(root, 3);
    insert(root, 8);
    insert(root, 80);

    inorder(root);



    int val;
    printf("\n Enter data of node to be inserted :  \n");
    scanf("%d", &val);

    insert(root,val);
    if(flag==1){
        inorder(root);
    }
    return 0;
}
