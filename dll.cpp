#include<stdio.h>
#include<stdlib.h>

class list{
    public:
    struct node{
        int data;
        struct node* next;
        struct node* prev;
    }* head;

    
    list(){
        head=NULL;
    }
    public:
    int insertbeg(int num);
    int insertend(int num);
    int delbeg();
    int delend();
    int search(int num);
    void disrev(struct node* head);
    int display();
};

int main(){
    list l1;
    int choice, num;

    for(;;){
        printf("1. insertbeg\n2. deletebeg\n3. search\n4. display reverse\n 5. display\n6. insert end\n7. del end\n8. exit\n ");
        printf("enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("enter num to insert: ");
            scanf("%d",&num);
            l1.insertbeg(num);
            break;

            case 2:
            l1.delbeg();
            break;

            case 3:
            printf("enter num to search: ");
            scanf("%d",&num);
            l1.search(num);
            break;

            case 4:
            l1.disrev(l1.head);
            break;

            case 5:
            l1.display();
            break;

            case 6:
            printf("enter num to insert: ");
            scanf("%d",&num);
            l1.insertend(num);
            break;

            case 7:
            l1.delend();
            break;


            case 8:
            return 0;
            break;

        }
    }
}

int list::insertbeg(int num){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    newnode->prev=NULL;
    head=newnode;
    return 1;
    
    
}

int list::insertend(int num){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    if(head==NULL){
        newnode->prev=NULL;
        head=newnode;
        return 1;
    }

    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    return 1;

}

int list::search(int num){
    if(head==NULL){
        printf("list is empty");
        return 0;
    }
    struct node* temp=head;
    while(temp!=NULL){
        if(temp->data==num){
            printf("number present\n");
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

int list::display(){
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

void list::disrev(struct node* head){
    if (head == NULL) {
        return;
    }
    disrev(head->next);
    printf("%d ",head->data);
        return;}


int list::delend(){
    if(head==NULL){
        printf("list is empty");
        return 0;
    }
    struct node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;

    }
    temp->next=NULL;
    return 1;

}

int list::delbeg(){
    if(head==NULL){
        printf("list is empty");
        return 0;
    }
    head=head->next;
    return 1;
}