#include<stdio.h>
#include<stdlib.h>

class list{
    struct node{
        int data;
        struct node* next;
    }*head;
    public:
    list(){
        head=NULL;
    }
    int insbeg(int num);
    int insend(int num);
    int delend();
    int delbeg();
    int display();
    int inspos(int num,int pos);
    int delpos(int pos);
    int search(int num);
};

int main(){
    list l1;
    int choice, num, pos;
    for(;;){
        printf("1. insert beg\n2. insert end\n3. delete beg\n4. delete end\n5. display\n6. exit\n7. insert pos\n8. del pos\n9. search\n");
        printf("enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("enter the number to insert: ");
            scanf("%d",&num);
            if(l1.insbeg(num)){
                printf("insertion successful\n");
            }
            else{
                printf("unsuccessful\n");
            }
            break;
            case 2:
            printf("enter the number to insert: ");
            scanf("%d",&num);
            if(l1.insend(num)){
                printf("insertion successful\n");
            }
            else{
                printf("unsuccessful\n");
            }
            break;
            case 3:
            if(l1.delbeg()){
                printf("deletion successful\n");
            }
            else{
                printf("unsuccessful\n");
            }
            break;
            case 4:
            if(l1.delend()){
                printf("deletion successful\n");
            }
            else{
                printf("unsuccessful\n");
            }
            break;
            case 5:
            l1.display();
            break;
            case 6:
            return 0;
            break;
            case 7:
            printf("enter the number to insert: ");
            scanf("%d",&num);
            printf("enter the position: ");
            scanf("%d",&pos);
            if(l1.inspos(num,pos)){
                printf("insertion successful\n");
            }
            else{
                printf("unsuccessful\n");
            }
            break;
            case 8:
            printf("enter the position: ");
            scanf("%d",&pos);
            if(l1.delpos(pos)){
                printf("deletion successful\n");
            }
            else{
                printf("unsuccessful\n");
            }
            break;
            case 9:
            printf("enter the num to search: ");
            scanf("%d",&num);
            if(l1.search(num)){
                printf("succefull\n");
            }
            else{
                printf("number absent\n");
            }
            break;

            
            default:
            printf("enter valid choice\n");
            
        }
 
}
}
int list::insbeg(int num){
    struct node* newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
    return 1;
}

int list::insend(int num){
    if(head==NULL){
        head->data=num;
        head->next=NULL;
        return 1;
    }
    struct node* newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return 1;
}

int list::delend(){
    if(head==NULL){
        printf("list is empty\n");
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
        printf("list is empty\n");
        return 0;
    }
    head=head->next;
    return 1;
}

int list:: display(){
    if(head==NULL){
        printf("list is empty\n");
        return 0;
    }
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
    return 1;
}

int list::inspos(int num, int pos){
    if(pos<1){
        printf("out of range\n");
        return 0;
    }
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    struct node* temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return 1;
}

int list::delpos(int pos){
    if(head==NULL){
        printf("list is empty\n");
        return 0;
    }
    struct node* temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return 1;
}

int list::search(int num){
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
