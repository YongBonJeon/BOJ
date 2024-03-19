#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node *Lchild;
    struct _node *Rchild;
}node;

typedef node* nodePointer;

nodePointer init_node(int data){
    nodePointer new_node = (nodePointer)malloc(sizeof(node));
    new_node->data = data;
    new_node->Lchild = NULL;
    new_node->Rchild = NULL;

    return new_node;
}

nodePointer insert_node(nodePointer node, int data){
    if (node == NULL) {
        //printf("busin\n");
		node = init_node(data);
	}
	else if (data <= node->data){
		node->Lchild = insert_node(node->Lchild, data);
    }
	else{
		node->Rchild= insert_node(node->Rchild, data);
        //printf("tt %d\n",node->data);
    }
	return node;
}

void postorder(nodePointer node) {
	if (node->Lchild != NULL)
		postorder(node->Lchild);
	if (node->Rchild != NULL)
		postorder(node->Rchild);
	printf("%d\n",node->data);
}

int main(){

    int data;

    nodePointer root = NULL;
    while(scanf("%d",&data) != EOF){
        //printf("sibal\n");
        root = insert_node(root, data);
        //printf("subr %d\n",root->data);
    }
    postorder(root);
}