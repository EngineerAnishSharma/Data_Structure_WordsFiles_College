#include <stdio.h>
#include <stdlib.h>

#define size 3
int queue[size];
int front=-1;
int rear=-1;


void insert(int x){
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else if(front==rear+1 || (front==0 && rear==size-1)){
        printf("Overflow\n");
    }
    else{
        rear=(rear+1)%size;
        queue[rear]=x;
    }
}

void del(){
    if(front==-1 && rear==-1){
        printf("Underflow\n");
    }
    else if(front==rear){
        printf("\nDelete element:%d",queue[front]);
        front=rear=-1;
    }
    else{
        printf("\nDelete element:%d",queue[front]);
        front=(front+1)%size;
    }
}
void display(){
    if(front==-1 && rear==-1){
        printf("There is no element\n");
    }
    else{
        printf("\nDisplaying element:\n");
        int i=front;
        while(i!=rear){
            printf("%d ",queue[i]);
            i=(i+1)%size;
        }
        printf("%d ",queue[i]);
    }


}
int main()
{
    int choice,x;
    printf("Implementation of Circular queue\n");
    while(1){
        printf("\nInsertion- 1\nDeletion  -2\nDisplay -3\nExit -0\n");
        scanf("%d",&choice);
        if(choice==0)
            break;
        else if(choice==1){
            printf("Enter a element:\n");
            scanf("%d",&x);
           insert(x);
        }
        else if(choice==2){
            del();
        }
        else if(choice==3){
            display();
        }

    }
    return 0;
}
