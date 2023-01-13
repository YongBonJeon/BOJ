#include <bits/stdc++.h>
using namespace std;

int N;
int tre[100];

typedef struct node_{
    int num;
    struct node_ *left;
    struct node_ *right;
}node;

node* find(node *root, int target)
{
    if(!root)
        return NULL;
    
    if(root->num == target)
        return root;

    return find(root->left, target);
    return find(root->right, target);
}

node* traverse(node* root, int *cnt)
{
    int flag = 0;   
    if(!root)
        return NULL;

    if(traverse(root->left, cnt) == NULL)
        flag++;
    if(traverse(root->right, cnt) == NULL)
        flag++;
    
    if(flag == 2)
        (*cnt)++;
}

void delete_node(node **root, int target)
{
    if(!(*root))
        return ;

    if((*root)->num == target){
        *root = NULL;
        return ;
    }

    delete_node(&((*root)->left), target);
    delete_node(&((*root)->right), target);
}

int main()
{
    node *root;
    cin >> N;

    int parent;
    
    for(int i = 0 ; i < N ; i++)
    {
        cin >> parent;

        if(parent == -1)
        {
            root = (node*)malloc(sizeof(node));
            root->num = i;
            root->left = NULL;
            root->right = NULL;
        }
        else
        {
            node *new_node = (node*)malloc(sizeof(node));
            new_node->num = i;
            new_node->left = NULL;
            new_node->right = NULL;

            node* parent_node = find(root, parent);
            if(!parent_node->left)
                parent_node->left = new_node;
            else
                parent_node->right = new_node; 
        }
    }
    int del_num;
    cin >> del_num;
    int cnt = 0;
    traverse(root, &cnt);
    printf("%d\n",cnt);
    printf("\n");
    
    delete_node(&root, del_num);
    cnt = 0;
    traverse(root, &cnt);
    printf("%d\n",cnt);

}