#include<stdio.h>
#include<stdlib.h>

class tree{
    public:
    struct node{
    int data;
    struct node* right;
    struct node* left;}* root;

    
    tree(){
        root=NULL;
    }
    struct node* insert(struct node* troot,int num);
    void postorder(struct node* troot);
    bool search(struct node* troot,int num);
};

int main(){
    tree t1;
    int choice, num;
    for(;;){
        printf("1. insert\n2. postorder\n3. search\n4. exit\n ");
        printf("enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("enter num to insert: ");
            scanf("%d",&num);
            t1.root=t1.insert(t1.root,num);
            break;

            case 2:
            t1.postorder(t1.root);
            break;

            case 3:
            printf("enter num to insert: ");
            scanf("%d",&num);
            if(t1.search(t1.root,num)){
                printf("present\n");
            }
            else{
                printf("absent\n");
            }
            break;

            case 4:
            return 0;
            break;

        }}


}

struct tree::node* tree::insert(struct node* troot,int num){
    
    if(troot==NULL){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        newnode->right=NULL;
        newnode->left=NULL;
        troot=newnode;
        return troot;
    }
    
    if(num<(troot->data)){
        troot->left=insert(troot->left,num);
    }
    if(num>(troot->data)){
        troot->right=insert(troot->right,num);
    }

    return troot;

}

void tree::postorder(struct node* troot){
    if(troot==NULL){
        return;
    }
    postorder(troot->left);
    postorder(troot->right);
    printf("%d ",troot->data);
    printf("\n");
}

bool tree::search(struct node* troot,int num){
    if(troot==NULL){
        return false;
    }
    if(troot->data==num){
        return true;
    }
    return(search(troot->left,num)||search(troot->right,num));
}