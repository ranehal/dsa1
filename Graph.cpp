#include<stdio.h>
struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node node;

node* createNode(int x);
void printList(node* head);
node* insert_head(node* head, node* nn);
node* insert_tail(node* head, node* nn);


int main(){
    int n;
    printf("n?");
    scanf("%d",&n);
    int graph[n][n];
    node *nn;
    //initialized with 0
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            graph[row][col]=0;
        }

    }

    //taking user input
    for(int row=0;row<n;row++){
        for(int col=row+1;col<n;col++){
            printf("%c-%c:",row+'A',col+65);
            scanf("%d",&graph[row][col]);
            graph[col][row] = graph[row][col];
        }
    }

    //adjacency List
    node* head_arr[n];
    for(int i=0;i<n;i++){
        nn = createNode(i);
        head_arr[i]=nn;
    }

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(graph[row][col]==1){
                nn = createNode(col);
                head_arr[row] = insert_tail(head_arr[row],nn);
            }
        }
    }

    printf("Data in Graph:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d\t\t",graph[i][j]);
        }
        printf("\n");
    }

    printf("Adjacency List:\n");
    for(int i=0;i<n;i++){
        printList(head_arr[i]);
    }

return 0;
}


node* createNode(int x)
{
    node* nn=new node();
    nn->data = x;
    nn->next = NULL;
    return nn;
}

void printList(node* head)
{
    node* temp = head;
    if(temp==NULL)
    {
        printf("No Data Found!\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%c ",temp->data+'A');
            temp=temp->next;
        }
    }
    printf("\n");
}

node* insert_head(node* head, node* nn)
{
    node* temp = head;
    if(head!=NULL)
    {
        nn->next=head;
    }
    head=nn;
    return head;
}

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
    }
    return head;
}



