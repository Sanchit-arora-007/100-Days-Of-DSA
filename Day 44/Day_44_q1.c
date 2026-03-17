#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left,*right;
};

struct Node* newNode(int x){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=x;
    n->left=n->right=NULL;
    return n;
}

void inorder(struct Node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct Node* root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){
    int N;

    printf("Enter number of nodes: ");
    scanf("%d",&N);

    int arr[N];

    printf("Enter level order values (-1 for NULL):\n");
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);

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

    inorder(nodes[0]);
    printf("\n");
    preorder(nodes[0]);
    printf("\n");
    postorder(nodes[0]);

    return 0;
}