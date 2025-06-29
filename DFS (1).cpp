#include<stdio.h>
int data[100],top=0,stsize=0;
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

void push_data(int value);
int check_existence(int visited[],int now,int n);
void pop_data();


int main()
{
    int n;
    printf("Vertex?");
    scanf("%d",&n);
    int graph[n][n];
    node *nn;
    //initialized with 0
    for(int row=0; row<n; row++)
    {
        for(int col=0; col<n; col++)
        {
            graph[row][col]=0;
        }
    }

    //taking user input
    for(int row=0; row<n; row++)
    {
        for(int col=row+1; col<n; col++)
        {
            printf("%c-%c:",row+'A',col+65);
            scanf("%d",&graph[row][col]);
            graph[col][row] = graph[row][col];
        }
    }

    //adjacency List
    node* head_arr[n];
    for(int i=0; i<n; i++)
    {
        nn = createNode(i);
        head_arr[i]=nn;
    }

    for(int row=0; row<n; row++)
    {
        for(int col=0; col<n; col++)
        {
            if(graph[row][col]==1)
            {
                nn = createNode(col);
                head_arr[row] = insert_tail(head_arr[row],nn);
            }
        }
    }

    printf("Data in Graph:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d\t\t",graph[i][j]);
        }
        printf("\n");
    }

    printf("Adjacency List:\n");
    for(int i=0; i<n; i++)
    {
        printList(head_arr[i]);
    }

    int visited[n];
    printf("Start Node: ");
    char ch;
    fflush(stdin); //getchar();
    scanf("%c",&ch); //0A,1B,2C,3D...
    int start = ch-65;
    visited[0] = start;

    node* temp = head_arr[start]->next;
    while(temp!=NULL)
    {
        push_data(temp->data);
        temp=temp->next;
    }

    int now, i=1;
    while(top!=0)
    {
        now = data[top-1]; //stack first element
        int check = check_existence(visited,now,i);

        if(check==0)
        {
            visited[i]=now;
            i++;
            pop_data();

            temp = head_arr[now]->next;
            while(temp!=NULL)
            {
                push_data(temp->data);
                temp=temp->next;
            }

        }
        else
        {
            pop_data();
        }
    }

    printf("DFS:\n");
    for(int i=0;i<n;i++){
        printf("%c ",visited[i]+65);
    }

    return 0;
}

void pop_data()
{
    if(top==0)
    {
        printf("\nStack Empty!\n");
    }
    else
    {
       top--;

    }
}

int check_existence(int visited[],int now,int n)
{
    for(int i=0; i<n; i++)
    {
        if(now==visited[i])
        {
            return 1; //already visited-->just pop
        }
    }
    return 0; //not visited-->visited -->adjacent push
}

void push_data(int value)
{
    int len = sizeof(data)/sizeof(data[0]);
    if(len==top)
    {
        printf("\nFULL!\n");
    }
    else
    {
        data[top] = value;
        top++;
    }
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




