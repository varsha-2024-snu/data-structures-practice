#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

class list{
    int arr[SIZE];
    int cur;
    public:
    list(){
        cur=-1;
    }

    int insbeg(int n);
    int insend(int n);
    int delbeg();
    int delend();
    int display();
    int insertpos(int n,int pos);
    int delpos(int pos);
    int search(int n);
};

int main(){
    list l1;
    int choice, num,pos;
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
            if(l1.insertpos(num,pos)){
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

int list::insend(int num){
    if(cur>=5){
        printf("list is full");
        return 0;
    }
    arr[cur+1]=num;
    cur++;
    return 1;
}

int list::insbeg(int num){
    if(cur>5){
        printf("list is full");
        return 0;
    }
    if(cur==-1){
        arr[0]=num;
        cur++;
        return 1;
    }
    for(int i=cur;i>=0;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=num;
    cur++;
    return 1;
}

int list::delbeg(){ 
    if(cur==-1){
        printf("list is empty\n");
        return 0;
    }
    for(int i=0;i<=cur;i++){
        arr[i]=arr[i+1];
    }
    cur--;
    return 1;
}

int list::delend(){
    if(cur==-1){
        printf("list is empty\n");
        return 0;
    }
    cur--;
    return 1;
}

int list::display(){
    if(cur==-1){
        printf("list is empty\n");
        return 0;
    }
    printf("elemets of the list: ");
    for(int i=0;i<=cur;i++){
        printf("%d ",arr[i]);
    
    }
    printf("\n");
}

int list::insertpos(int num,int pos){
    if(cur==5){
        printf("list is full\n");
        return 0;
    }
    if(pos>cur||pos<=0){
        printf("not valid\n");
        return 0;
    }
    for(int i=cur;i>=pos;i--){
        arr[i+1]=arr[i];

    }
    arr[pos]=num;
    cur++;
    return 1;

}
int list::delpos(int pos){
    if(cur==-1){
        printf("list is empty\n");
        return 0;
    }

    for(int i=pos;i<=cur;i++){
        arr[i]=arr[i+1];
    }
    cur--;
}
int list::search(int num){
    for(int i=0;i<=cur;i++){
        if(arr[i]==num){
            printf("number present\n");
            return 1;
        }
    }
    return 0;

}