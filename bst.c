#include<stdlib.h>

struct Node{
    int data;
    struct Node *left,*right;
};

struct Node* create(){
    int x;
    struct Node *newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter the data (Press -1 for no node): ");
    scanf("%d",&x);

    if(x == -1){
        return 0;
    }else{
    newnode->data = x;
    
    printf("Enter the Value of the Left Child For %d\n ", x);
    newnode->left = create();
    printf("Enter the Value of the Right Child For %d\n ", x);
    newnode->right = create();
    return newnode;
    }
}

void inOrder(struct Node *root){
    if(root == 0)
        return;
    inOrder(root->left);
    printf("%d\t", root->data);
    inOrder(root->right);
}

int minValue(struct Node *root){
    struct Node *curr = root;
    if(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

struct Node* delete(struct Node *root,int value){
    if(root == NULL)
        return root;
    if(value < root->data){
        root->left = delete(root->left,value);
    }else if( value > root->data ){
        root->right = delete(root->right,value);
    }else{
        // Now Checking if Equal
        if(root->left == NULL){
            struct Node *temp;
            temp = root->right;
            free(root);
            return temp;
        }else  if(root->right == NULL){
            struct Node *temp;
            temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = minValue(root->right);

        root->data = temp;
        root->right = delete(root->right, temp->data);
    }
        return root;
}

void main(){
    struct Node *root;
    root = create();
    inOrder(root);
    delete(root,7);
    inOrder(root);


}