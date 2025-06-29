#include<stdio.h>
struct Node{
    int data;
    struct Node *left, *right;
};
typedef struct Node node;

int menu();
node* insert_BST(node* temp,node* nn);
node* min_node(node* current);
node* delete_BST(node* root, int key);
node* searchData(node* temp,int key);
void inorder(node* root);
void preorder(node* root);
void postorder(node* root);

int main(){
    node* root=NULL, *nn;
    int choice;
    choice = menu();
    while(choice!=0){
        if(choice==1){
            nn = new node();
            nn->left = NULL;
            nn->right = NULL;
            printf("Enter data:");
            scanf("%d",&nn->data);
            root = insert_BST(root,nn);
            printf("\nInserted!\n\n");
        }else if(choice==2){
            int key;
            printf("Key?");
            scanf("%d",&key);
            root = delete_BST(root, key);
            printf("\n%d Deleted!\n\n",key);
        }else if(choice==3){
            int key;
            printf("Search Key?");
            scanf("%d",&key);
            if(searchData(root,key)!=NULL){
                printf("\nFOUND!\n");
            }else{
                printf("\nNot Found!\n");
            }
        }else if(choice==4){
            printf("Inorder:\n");
            inorder(root);
            printf("\n\n");
        }else if(choice==5){
            printf("Pre-order:\n");
            preorder(root);
            printf("\n\n");
        }else if(choice==6){
            printf("Post-order:\n");
            postorder(root);
            printf("\n\n");
        }
        else{
            printf("Invalid Input!!\n\n");
        }
        choice = menu();
    }
return 0;
}

void postorder(node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void preorder(node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

node* searchData(node* temp,int key){
    if(temp==NULL || temp->data == key){
        return temp;
    }
    if(key<temp->data){
        return searchData(temp->left, key);
    }else{
        return searchData(temp->right, key);
    }
}

node* delete_BST(node* root, int key){
    if(root == NULL){
        return root;
    }else if(key<root->data){
        root->left = delete_BST(root->left, key);
    }else if(key>root->data){
        root->right = delete_BST(root->right, key);
    }else{
        if(root->left==NULL){ //Node has no left child
            node* x = root->right;
            return x;
        }else if(root->right==NULL){ //Node has no right child
            node* x = root->left;
            return x;
        }

        node* temp = min_node(root->right);
        root->data = temp->data;
        delete_BST(root->right, temp->data);
    }
    return root;
}

node* min_node(node* current){
    while(current->left!=NULL){
        current=current->left;
    }
    return current;
}

node* insert_BST(node* temp,node* nn){
    if(temp==NULL){
        return nn;
    }else if(nn->data < temp->data){
        temp->left = insert_BST(temp->left, nn);
    }else{
        temp->right = insert_BST(temp->right, nn);
    }
    return temp;
}

int menu(){
    printf("1) Insert\n");
    printf("2) Delete\n");
    printf("3) Search\n");
    printf("4) In-order\n");
    printf("5) Pre-order\n");
    printf("6) Post-order\n");
    printf("0) Exit\n");
    printf("Enter your choice:");
    int choice;
    scanf("%d",&choice);
    return choice;
}
