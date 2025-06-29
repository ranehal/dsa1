#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next,*prev;
};
typedef struct Node node;

void menu();
node* createNode();
void printList(node* head);
node* insert_head(node* head, node* nn);
node* insert_tail(node* head, node* nn);
node* insertAtNthPosition(node* head, node* nn, int n, int position);
node* delete_head(node *head);
int ListSize(node* head);
node* delete_tail(node *head);
node* delete_nth(node *head, int n, int position);

int main()
{
    node* head = NULL, *nn;
    //printf("use free() in c or including stdlib.h, use delete() in c++\n");
    int choice;
    menu();
    scanf("%d",&choice);

    while(choice!=0)
    {
        if(choice==1)
        {
            printList(head);
        }
        else if(choice==2)
        {
            nn= createNode();
            head = insert_head(head,nn);
        }
        else if(choice==3)
        {
            nn=createNode();
            head=insert_tail(head, nn);
        }
        else if(choice==4)
        {
            int len = ListSize(head);
            printf("List Size: %d\n\n",len);
        }
        else if(choice==5)
        {
            nn=createNode();
            int n = ListSize(head);
            printf("Enter position:");
            int position;
            scanf("%d",&position);
            if(position>=1 && position<=n+1)
            {
                head=insertAtNthPosition(head,nn,n, position);
            }
            else
            {
                printf("Invalid Position!\n\n");
            }

        }
        else if(choice==6)
        {
            head = delete_head(head);
        }
        else if(choice==7)
        {
            head = delete_tail(head);
        }
        else if(choice==8)
        {
            int n, position;
            n = ListSize(head);
            printf("enter position: ");
            scanf("%d",&position);

            if(position >= 1 && position <= n)
            {
                head = delete_nth(head, n, position);
            }
            else
            {
                printf("invalid position\n\n");
            }
        }
        else
        {
            printf("Invalid Choice!\n");
        }
        menu();
        scanf("%d",&choice);
    }

    printf("\nYour pressed the Exit button!\nbye...\n");
}

//changed
node* createNode()
{
    node* nn=new node();
    printf("Enter data:");
    scanf("%d",&nn->data);
    nn->next = NULL;
    nn->prev = NULL; //new
    return nn;
}

void printList(node* head)
{
    node* temp = head;
    printf("Data in Linked List:\n\n");
    if(temp==NULL)
    {
        printf("No Data Found!\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    printf("\n\n");
}

//changed
node* insert_head(node* head, node* nn)
{
    node* temp = head;
    if(head!=NULL)
    {
        nn->next = head;
        head->prev = nn; //new
    }
    head=nn;
    printf("Node inserted in Head!\n\n");
    return head;
}

//changed
node* insert_tail(node* head, node* nn)
{
    node* temp = head;
    if(temp==NULL)
    {
        head = insert_head(head,nn);
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
        nn->prev = temp; //new
    }
    printf("Node inserted in Tail!\n\n");
    return head;
}

//changed
node* insertAtNthPosition(node* head, node* nn, int n, int position)
{
    node* temp = head;
    if(position==1)
    {
        head=insert_head(head,nn);
    }
    else if(position==n+1)
    {
        head=insert_tail(head,nn);
    }
    else
    {
        for(int i=1; i<=position-2; i++)
        {
            temp=temp->next;
        }
        nn->prev = temp; //new
        nn->next = temp->next;
        temp->next->prev = nn; //new
        temp->next = nn;
    }
    printf("Data inserted at nth position!\n\n");
    return head;
}

//unchanged
node* delete_head(node *head)
{
    if(head == NULL)
    {
        printf("nothing to delete\n\n");
    }
    else
    {
        node *temp;
        temp = head;

        head = head->next;
        if(head!=NULL){
            head->prev = NULL; //new
        }

        delete(temp);
    }
    printf("Node deleted!\n\n");
    return head;
}

int ListSize(node* head)
{
    node* temp= head;
    int counter=0;
    while(temp != NULL)
    {
        counter++;
        temp=temp->next;
    }
    return counter;
}

node* delete_tail(node *head)
{
    int n;
    n = ListSize(head);

    if(n <= 1)
    {
        head = delete_head(head);
    }
    else
    {
        int i;
        node *temp;
        temp = head;

        for(i = 1; i <= n-2; i++)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
    printf("Tail Node deleted!\n\n");
    return head;
}

//chnaged
node* delete_nth(node *head, int n, int position)
{
    if(position == 1)
    {
        head = delete_head(head);
    }
    else if(position == n)
    {
        head = delete_tail(head);
    }
    else
    {
        node *temp, *del;
        temp = head;
        int i;

        for(i = 1; i <= position-2; i++)
        {
            temp = temp->next;
        }
        del = temp->next;
        temp->next = del->next;
        del->next->prev = temp; //new
        delete(del);

    }
    printf("%d position Node deleted!\n\n",position);
    return head;
}


void menu()
{
    printf("1) Print List\n");
    printf("2) Insert Data at Head\n");
    printf("3) Insert Data at Tail\n");
    printf("4) Size of Linked List\n");
    printf("5) Insert Data at Nth Position\n");
    printf("6) Delete Head data\n");
    printf("7) Delete Tail data\n");
    printf("8) Delete Nth position data\n");
    printf("0) Exit\n");
    printf("Enter your choice:");
}
