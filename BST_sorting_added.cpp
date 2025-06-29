
#include<stdio.h>
#include<stdlib.h>

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

// Function to compute sum of a subtree
int subtreeSum(node* root) {
    if (root == NULL)
        return 0;
    return root->data + subtreeSum(root->left) + subtreeSum(root->right);
}

// Global array to store traversal results
int sorted_array[1000];
int index = 0;

// Reset array before filling
void reset_array() {
    index = 0;
}

// Inorder traversal for ascending sort
void store_inorder(node* root) {
    if (root != NULL) {
        store_inorder(root->left);
        sorted_array[index++] = root->data;
        store_inorder(root->right);
    }
}

// Reverse inorder for descending sort
void store_reverse_inorder(node* root) {
    if (root != NULL) {
        store_reverse_inorder(root->right);
        sorted_array[index++] = root->data;
        store_reverse_inorder(root->left);
    }
}

// Print the array
void print_array() {
    for (int i = 0; i < index; i++) {
        printf("%d ", sorted_array[i]);
    }
    printf("\n");
}

int main(){
    node* root=NULL, *nn;
    int choice;
    choice = menu();
    while(choice!=0){
        if(choice==1){
            nn = (node*)malloc(sizeof(node));
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
            node* found = searchData(root, key);
            if (found != NULL)
                printf("Found: %d\n", found->data);
            else
                printf("Not Found\n");
        }else if(choice==4){
            printf("Inorder: ");
            inorder(root);
            printf("\n");
        }else if(choice==5){
            printf("Preorder: ");
            preorder(root);
            printf("\n");
        }else if(choice==6){
            printf("Postorder: ");
            postorder(root);
            printf("\n");
        }else if(choice==9){
            if (root == NULL) {
                printf("Tree is empty.\n");
            } else {
                int leftSum = subtreeSum(root->left);
                int rightSum = subtreeSum(root->right);
                printf("Sum of Left Subtree: %d\n", leftSum);
                printf("Sum of Right Subtree: %d\n", rightSum);
            }
        }else if(choice==10){
            reset_array();
            store_inorder(root);
            printf("Ascending order: ");
            print_array();
        }else if(choice==11){
            reset_array();
            store_reverse_inorder(root);
            printf("Descending order: ");
            print_array();
        }
        choice = menu();
    }
    return 0;
}

int menu(){
    int ch;
    printf("\n1. Insert\n2. Delete\n3. Search\n4. Inorder\n5. Preorder\n6. Postorder\n");
    printf("9. Print sum of left and right subtrees\n");
    printf("10. Sort Ascending\n11. Sort Descending\n");
    printf("0. Exit\nEnter choice: ");
    scanf("%d", &ch);
    return ch;
}

node* insert_BST(node* temp,node* nn){
    if(temp==NULL)
        return nn;
    if(nn->data < temp->data)
        temp->left = insert_BST(temp->left, nn);
    else
        temp->right = insert_BST(temp->right, nn);
    return temp;
}

node* min_node(node* current){
    while(current && current->left != NULL)
        current = current->left;
    return current;
}

node* delete_BST(node* root, int key){
    if (root == NULL) return root;
    if (key < root->data)
        root->left = delete_BST(root->left, key);
    else if (key > root->data)
        root->right = delete_BST(root->right, key);
    else {
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = min_node(root->right);
        root->data = temp->data;
        root->right = delete_BST(root->right, temp->data);
    }
    return root;
}

node* searchData(node* temp,int key){
    if(temp==NULL || temp->data==key)
        return temp;
    if(key < temp->data)
        return searchData(temp->left, key);
    else
        return searchData(temp->right, key);
}

void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
