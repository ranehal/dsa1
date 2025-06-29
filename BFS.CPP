#include<stdio.h>
int data[100],qsize=0,frnt=0,rear=0,vcount=0;
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

void enqueue_data(int value);
int front_element();
int check_existence(int visited[],int now,int n);
void deque_data();


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
    qsize = 25;
    printf("Start Node: ");
    char ch;
    fflush(stdin); //getchar();
    scanf("%c",&ch); //0A,1B,2C,3D...
    int start = ch-65;
    visited[0] = start;

    node* temp = head_arr[start]->next;
    while(temp!=NULL)
    {
        enqueue_data(temp->data);
        temp=temp->next;
    }

    int now, i=1;
    while(vcount!=0)
    {
        now = front_element(); //queue first element
        int check = check_existence(visited,now,i);

        if(check==0)
        {
            visited[i]=now;
            i++;
            deque_data();

            temp = head_arr[now]->next;
            while(temp!=NULL)
            {
                enqueue_data(temp->data);
                temp=temp->next;
            }

        }
        else
        {
            deque_data();
        }
    }

    printf("BFS:\n");
    for(int i=0;i<n;i++){
        printf("%c ",visited[i]+65);
    }

    return 0;
}
void deque_data()
{
    if(vcount==0)
    {
        printf("\nQueue Empty!\n");
    }
    else
    {
        frnt=(frnt+1)%qsize;

    }
    vcount--;
}


int check_existence(int visited[],int now,int n)
{
    for(int i=0; i<n; i++)
    {
        if(now==visited[i])
        {
            return 1; //already visited-->just dequeue
        }
    }
    return 0; //not visited-->visited -->adjacent enqueue
}
int front_element()
{
    return data[frnt];
}

void enqueue_data(int value)
{

    if(vcount==qsize)
    {
        printf("\nFULL!\n");
    }
    else
    {
        data[rear] = value;
        rear=(rear+1)%qsize;
    }
    vcount++;
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



