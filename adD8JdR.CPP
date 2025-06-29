#include<stdio.h>
struct Node{
    int data;
    struct Node *left, *right;
};
typedef struct Node node;
int internal_count = 0;
int leaf_count = 0;

int menu();
node* insert_BST(node* temp,node* nn);
node* min_node(node* current);
node* delete_BST(node* root, int key);
node* searchData(node* temp,int key);
void inorder(node* root);
void preorder(node* root);
void postorder(node* root);
int isPrime(int n);
node* pri_del(node* root);
void internal(node* root);
void leaf(node* root);

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
        }else if(choice==7){
            printf("Deleting all prime numbers...\n");
            root = pri_del(root);

    printf("\nAll prime numbers deleted!\n\n");
        }else if(choice==8){
            internal_count = 0;
            leaf_count = 0;
            printf("Internal nodes: ");
            internal(root);
            printf("\nLeaf nodes: ");
            leaf(root);
            printf("\nTotal internal nodes: %d\n", internal_count);
            printf("Total leaf nodes: %d\n\n", leaf_count);
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
            delete root;
            return x;
        }else if(root->right==NULL){ //Node has no right child
            node* x = root->left;
            delete root;
            return x;
        }

        node* temp = min_node(root->right);
        root->data = temp->data;
        root->right = delete_BST(root->right, temp->data);
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
    printf("7) Search & Delete Prime Numbers\n");
    printf("8) Special Operation (Internal & Leaf nodes)\n");
    printf("0) Exit\n");
    printf("Enter your choice:");
    int choice;
    scanf("%d",&choice);
    return choice;
}

int isPrime(int n){
    if(n < 2) return 0;
    for(int i=2; i*i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}
node* pri_del(node* root) {
    if (root == NULL) {
        return root;
    }
    
    root->left = pri_del(root->left);
    root->right = pri_del(root->right);
    
    if (isPrime(root->data)) {
        printf("Deleting prime number: %d\n", root->data);
        return delete_BST(root, root->data);
    }
    return root;
}

void internal(node* root) {
    if (root == NULL) {
        return;
    }
    
    if (root->left != NULL || root->right != NULL) {
        printf("%d, ", root->data);
        internal_count++;
    }
    
    internal(root->left);
    internal(root->right);
}

void leaf(node* root) {
    if (root == NULL) {
        return;
    }
    
    if (root->left == NULL && root->right == NULL) {
        printf("%d, ", root->data);
        leaf_count++;
    }
    
    leaf(root->left);
    leaf(root->right);
}