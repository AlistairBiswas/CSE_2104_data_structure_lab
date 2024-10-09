#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};


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
struct node* search(struct node* root, int key)
{

    if (root == NULL )
    {
        printf(" %d is Not Found in The Tree \n",key);
        return 0;
    }
    if(root->data == key )
    {
        printf("%d is found in the tree",key);
        return root;
    }

    if (root->data > key)
        return search(root->left, key);

    if(root->data < key)
    {
        return search(root->right, key);
    }
}


int main()
{

    struct node* root = NULL;
    root = insert(root, 20);
    insert(root, 1);
    insert(root, 10);
    insert(root, 25);
    insert(root, 44);
    insert(root, 27);
    insert(root, 12);

    printf("The tree is :\n");
    inorder(root);
    printf("\n");

    int num;
    printf("Enter the value to  be  searched : \n ");
    scanf("%d",&num);


    root=search (root,num);


    return 0;
}

