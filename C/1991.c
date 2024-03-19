/* 포인터로 구현해야됨 배열로 못한다.. */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    char data;
    struct _node *Lchild;
    struct _node *Rchild;
}node;

typedef node* nodePointer;

nodePointer init_node(char data){
    nodePointer new_node = (nodePointer)malloc(sizeof(node));
    new_node->data = data;
    new_node->Lchild = NULL;
    new_node->Rchild = NULL;

    return new_node;
}

void search_make_tree(nodePointer root, char target, char Lchild, char Rchild){
    if(!root){
        return ;
    }

    if(root->data == target){
        root->Lchild = init_node(Lchild);
        root->Rchild = init_node(Rchild);
        return ;
    }
    search_make_tree(root->Lchild, target,Lchild,Rchild);
    search_make_tree(root->Rchild, target,Lchild,Rchild);

}

void inorder(nodePointer root){
    //printf("x\n");
    if(!root){
        return;;
    }
    if(root->data == '.'){
        return;
    }
    inorder(root->Lchild);
    printf("%c",root->data);
    inorder(root->Rchild);
}
void preorder(nodePointer root){
    //printf("x\n");
    if(!root){
        return;;
    }
    if(root->data == '.'){
        return;
    }
    printf("%c",root->data);
    preorder(root->Lchild);
    preorder(root->Rchild);
}
void postorder(nodePointer root){
    //printf("x\n");
    if(!root){
        return;;
    }
    if(root->data == '.'){
        return;
    }
    postorder(root->Lchild);
    postorder(root->Rchild);
    printf("%c",root->data);
}

int main(){
    int n;

    scanf("%d ",&n);

    char parent, Lchild, Rchild;

    scanf("%c %c %c",&parent, &Lchild, &Rchild);
    //printf("%c %c %c\n",parent, Lchild, Rchild);

    nodePointer root = init_node(parent);
    root->Lchild = init_node(Lchild);
    root->Rchild = init_node(Rchild);
    //printf("%c %c",root->Lchild->data, root->Rchild->data);

    for(int i = 1 ; i < n ; i++){
        scanf(" %c  %c %c",&parent, &Lchild, &Rchild);
        //printf("%c %c %c\n",parent, Lchild, Rchild);

        search_make_tree(root, parent,Lchild, Rchild);
    }
    preorder(root);printf("\n");
    inorder(root);printf("\n");
    postorder(root);printf("\n");
    //printf("%c %c %c\n",root->data, root->Lchild->data, root->Lchild->Lchild->data);
}