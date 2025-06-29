#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};
typedef struct Node node;

int menu();
node* insert_BST(node* temp, node* nn);
node* min_node(node* current);
node* delete_BST(node* root, int key);
node* searchData(node* temp, int key);
void inorder(node* root);
void preorder(node* root);
void postorder(node* root);
int subtree_sum(node* root);
void sum_left_right_subtrees(node* root, int key);

int main() {
    node* root = NULL, *nn;
    int choice;
    choice = menu();
    while (choice != 0) {
        if (choice == 1) {
            nn = (node*)malloc(sizeof(node));
            nn->left = NULL;
            nn->right = NULL;
            printf("Enter data: ");
            scanf("%d", &nn->data);
            root = insert_BST(root, nn);
            printf("\nInserted!\n\n");
        } else if (choice == 2) {
            int key;
            printf("Key? ");
            scanf("%d", &key);
            root = delete_BST(root, key);
            printf("\n%d Deleted!\n\n", key);
        } else if (choice == 3) {
            int key;
            printf("Search Key? ");
            scanf("%d", &key);
            if (searchData(root, key) != NULL) {
                printf("\nFOUND!\n");
            } else {
                printf("\nNot Found!\n");
            }
        } else if (choice == 4) {
            printf("Inorder:\n");
            inorder(root);
            printf("\n\n");
        } else if (choice == 5) {
            printf("Pre-order:\n");
            preorder(root);
            printf("\n\n");
        } else if (choice == 6) {
            printf("Post-order:\n");
            postorder(root);
            printf("\n\n");
        } else if (choice == 7) {
            int key;
            printf("Enter node value to calculate left/right subtree sums: ");
            scanf("%d", &key);
            sum_left_right_subtrees(root, key);
        } else {
            printf("Invalid Input!!\n\n");
        }
        choice = menu();
    }
    return 0;
}

int menu() {
    printf("1) Insert\n");
    printf("2) Delete\n");
    printf("3) Search\n");
    printf("4) In-order\n");
    printf("5) Pre-order\n");
    printf("6) Post-order\n");
    printf("7) Sum of Left & Right Subtrees\n");  // New Option
    printf("0) Exit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

node* insert_BST(node* temp, node* nn) {
    if (temp == NULL) {
        return nn;
    } else if (nn->data < temp->data) {
        temp->left = insert_BST(temp->left, nn);
    } else {
        temp->right = insert_BST(temp->right, nn);
    }
    return temp;
}

node* min_node(node* current) {
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

node* delete_BST(node* root, int key) {
    if (root == NULL) {
        return root;
    } else if (key < root->data) {
        root->left = delete_BST(root->left, key);
    } else if (key > root->data) {
        root->right = delete_BST(root->right, key);
    } else {
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

node* searchData(node* temp, int key) {
    if (temp == NULL || temp->data == key) {
        return temp;
    }
    if (key < temp->data) {
        return searchData(temp->left, key);
    } else {
        return searchData(temp->right, key);
    }
}

int subtree_sum(node* root) {
    if (root == NULL) return 0;
    return root->data + subtree_sum(root->left) + subtree_sum(root->right);
}

void sum_left_right_subtrees(node* root, int key) {
    node* target = searchData(root, key);
    if (target == NULL) {
        printf("\nNode not found.\n");
        return;
    }

    int left_sum = subtree_sum(target->left);
    int right_sum = subtree_sum(target->right);

    printf("\nLeft Subtree Sum of %d = %d\n", key, left_sum);
    printf("Right Subtree Sum of %d = %d\n\n", key, right_sum);
}
