#include <stdio.h>

#define MAX 100001

int n;
int inorder[MAX];
int postorder[MAX];
int idx[MAX];

void preorder(int inStart, int inEnd, int postStart, int postEnd){
    if(inStart > inEnd || postStart > postEnd){
        return;
    }
    /* postorder의 끝 값이 root 값 */
    int rootIndex = idx[postorder[postEnd]];
    int left_size = rootIndex - inStart;
    int right_size = inEnd - rootIndex;
    printf("%d ",inorder[rootIndex]);

    preorder(inStart, rootIndex-1, postStart, postStart + left_size -1);
    preorder(rootIndex+1, inEnd, postStart+left_size, postEnd -1);
}

int main(){
    scanf("%d",&n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d",&inorder[i]);
    }
    for(int i = 1 ; i <= n ; i++){
        scanf("%d",&postorder[i]);
    }
    for(int i = 1 ; i <= n ; i++){
        idx[inorder[i]] = i;
    }
    
    preorder(1, n, 1, n);
    printf("\n");

}