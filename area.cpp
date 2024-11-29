#include<stdio.h>
#include<stdlib.h>
void circle(){
    int *r;
    r = (int *)malloc(sizeof(int));
    printf("enter radius: ");
    scanf("%d",r);
    printf("area=%f\n", 3.14*(*r)*(*r));
}
void square(){
    int *s;
    s = (int *)malloc(sizeof(int));
    printf("enter side: ");
    scanf("%d",s);
    printf("area=%d\n", (*s)*(*s));
}
void rect(){
    int *l,*b;
    l = (int *)malloc(sizeof(int));
    b = (int *)malloc(sizeof(int));
    printf("enter length: ");
    scanf("%d",l);
    printf("enter breadth: ");
    scanf("%d",b);
    printf("area=%d\n", (*l)*(*b));
}

int main(){
    for(;;){
        int *choice;
        choice = (int *)malloc(sizeof(int));
        printf("1. circle\n2. square\n3. rectangle\n4. exit\n");
        printf("enter choice: ");
        scanf("%d",choice);
        if(*choice==1){
            circle();
        }
        if(*choice==2){
            square();
        }
        if(*choice==3){
            rect();
        }
        if(*choice==4){
            break;
        }
        
    }
    
}