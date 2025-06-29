#include<stdio.h>
void menu();

int main(){
    int data[100],qsize,front=0,rear=0,choice;
    printf("size?");
    scanf("%d",&qsize);
    menu();
    scanf("%d",&choice);
    while(choice!=0){
        if(choice==1){
            if(qsize==rear){
                printf("\nQUEUE FULL!\n");
            }else{
                printf("Data?");
                scanf("%d",&data[rear]);
                rear++;
            }
        }else if(choice==2){
            if(rear==front){
                printf("\nQueue Empty!\n");
            }else{
                printf("%d DEQUEUED!\n",data[front]);
                front++;
            }
        }else if(choice==3){
            if(front==rear){
                printf("No data found!\n");
            }else{
                printf("%d Front Element!\n",data[front]);
            }
        }else if(choice==4){
            printf("Current Size: %d",rear-front);
        }else{
            printf("\nInvalid Choice!\n");
        }
        menu();
        scanf("%d",&choice);
    }
return 0;
}

void menu(){
    printf("\n1)Enqueue\n");
    printf("2)Dequeue\n");
    printf("3)Front Element\n");
    printf("4)Current Queue Size\n");
    printf("0)Exit!\n");
    printf("Enter your choice:");
}
