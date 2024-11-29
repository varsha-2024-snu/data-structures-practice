#include<stdio.h>
#include<stdlib.h>


int b_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]<arr[j+1]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    return 1;
}

int i_sort(int arr[], int n){
    for(int i=1;i<n+1;i++){
        for(int j=0;j<i;j++){
            if(arr[i]<arr[j]){
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    return 1;
}

int s_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        int s=arr[i];
        for(int j=i+1;j<n;j++){
            if(s>arr[j]){
                int temp=s;
                s=arr[j];
                arr[j]=temp;
            }
        }
        arr[i]=s;
    }
}

int c_sort(int arr[], int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }

    int count_arr[max+1];
    for(int i=0;i<max+1;i++){
        count_arr[i]=0;
    }

    for(int j=0;j<n;j++){
        count_arr[arr[j]]++;
    }

    //display
    for(int i=0;i<max+1;i++){
        for(int j=0;j<count_arr[i];j++){
            printf("%d ",i);
        }
    }
    printf("\n");
    return 1;
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
int n;
printf("enter num of elements: ");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
    printf("enter elmt: ");
    scanf("%d",&arr[i]);
}

c_sort(arr,n);}
//display(arr,n);



