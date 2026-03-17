#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int x){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=x;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void inorder(struct Node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main(){
    int N;

    printf("Enter number of nodes: ");
    scanf("%d",&N);

    int arr[N];

    printf("Enter level order values (-1 for NULL):\n");
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);

    if(arr[0]==-1)
        return 0;

    struct Node* nodes[N];

    for(int i=0;i<N;i++){
        if(arr[i]==-1)
            nodes[i]=NULL;
        else
            nodes[i]=newNode(arr[i]);
    }

    for(int i=0;i<N;i++){
        if(nodes[i]!=NULL){
            int l=2*i+1;
            int r=2*i+2;

            if(l<N) nodes[i]->left=nodes[l];
            if(r<N) nodes[i]->right=nodes[r];
        }
    }

    printf("Inorder traversal: ");
    inorder(nodes[0]);

    return 0;
}