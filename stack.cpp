#include<stdio.h>
#include<stdlib.h>

class stack{
    struct node{
        int data;
        struct node* next;
    }* head;

    public:
    stack(){
        head=NULL;
    }

   
    int push(int num);
    int pop();
    int peek();
    int display();
};

int main(){
    stack s1;
    int choice, num;
    for(;;){
        printf("1. push\n2. pop\n3. peek\n4. display\n5. exit\n ");
        printf("enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("enter num to insert: ");
            scanf("%d",&num);
            s1.push(num);
            break;

            case 2:
            s1.pop();
            break;

            case 3:
            s1.peek();
            break;

            case 4:
            s1.display();
            break;

            case 5:
            return 0;
            break;

        }}


}

int stack::push(int num){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
    return 1;
    
}

int stack::pop(){
    if(head==NULL){
        printf("underflow\n");
        return 0;
    }
    head=head->next;
    return 1;
}

int stack::peek(){
    if(head==NULL){
        printf("stack empty\n");
        return 0;
    }
    printf("%d\n",head->data);
    return 1;
}

int stack::display(){
    if(head==NULL){
        printf("list is empty");
        return 0;
    }
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    return 1;

}