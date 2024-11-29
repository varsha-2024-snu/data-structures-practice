#include<stdio.h>
#include<stdlib.h>
#define size 10

class list{
    int arr[10];
    int front;
    int rear;
    public:
    list(){
        front=-1;
        rear=-1;
    }

    int push(int num);
    int pop();
    int peek();
    int display();
};

int main(){
    list l1;
    int choice, num;
    for(;;){
        printf("1. push\n2. pop\n3. peek\n4. display\n5. exit\n");
        printf("enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("enter num: ");
            scanf("%d",&num);
            l1.push(num);
            break;

            case 2:
            l1.pop();
            break;

            case 3:
            l1.peek();
            break;
            
            case 4:
            l1.display();
            break;

            case 5:
            return 0;
            break;
        }
    }
}

int list::push(int num){
    if(front==-1){
        front=0;
        rear=0;
        arr[front]=num;
        return 1;

    }
    if(rear==size-1){
        printf("queue is full");
        return -1;
    }
    rear++;
    arr[rear]=num;
    return 1;
}

int list::pop(){
    if(front==-1){
        printf("queue is empty");

    }
    int val=arr[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }else{
    front++;}
    return val;
}

int list::peek(){
    if(front==-1){
        printf("queue is empty");
        return 0;

    }
    printf("%d\n",arr[front]);
    return 0;
}

int list::display(){
    if(front==-1){
        printf("queue is empty");
        return 0;

    }
    for(int i=front;i<=rear;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

