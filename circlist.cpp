#include <stdio.h>
#include <stdlib.h>

class list {
    struct node {
        int data;
        struct node* next;
    } *head;

public:
    list() {
        head = NULL;
    }
    int insertbeg(int);
    int insertend(int);
    int insertpos(int,int);
    int deletebeg();
    int deleteend();
    int deletepos(int);
    int search(int);
    int display();    
};

int main() {
    list myList;
    for (;;) {
        int choice;
        int num, pos;
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Delete from Beginning\n");
        printf("5. Delete from End\n6. Delete from Position\n7. Search\n8. Display\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter number to insert: ");
            scanf("%d", &num);
            myList.insertbeg(num);
        } else if (choice == 2) {
            printf("Enter number to insert: ");
            scanf("%d", &num);
            myList.insertend(num);
        } else if (choice == 3) {
            printf("Enter number to insert: ");
            scanf("%d", &num);
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            myList.insertpos(num, pos);
        } else if (choice == 4) {
            myList.deletebeg();
        } else if (choice == 5) {
            myList.deleteend();
        } else if (choice == 6) {
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            myList.deletepos(pos);
        } else if (choice == 7) {
            printf("Enter number to search: ");
            scanf("%d", &num);
            myList.search(num);
        } else if (choice == 8) {
            myList.display();
        } else if (choice == 9) {
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

int list:: insertbeg(int num) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = num;

        if (head == NULL) {
            head = newnode;
            newnode->next = head;  // Points to itself, making it circular
        } else {
            struct node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newnode->next = head;
            temp->next = newnode;
            head = newnode;
        }
        return 1;
    }

int list:: insertend(int num) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = num;

        if (head == NULL) {
            head = newnode;
            newnode->next = head;  // Points to itself, making it circular
        } else {
            struct node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;  // Points back to the head
        }
        return 1;
    }

 int list:: insertpos(int num, int pos) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = num;

        if (pos == 1) {
            insertbeg(num);
            return 1;
        }

        struct node* temp = head;
        for (int i = 1; i < pos - 1; ++i) {
            temp = temp->next;
            if (temp == head) {
                printf("Position out of range\n");
                free(newnode);
                return -1;
            }
        }

        newnode->next = temp->next;
        temp->next = newnode;
        return 1;
    }

int list:: deletebeg() {
        if (head == NULL) {
            printf("List is empty.\n");
            return -1;
        }

        struct node* temp = head;
        if (head->next == head) {
            head = NULL;
        } else {
            while (temp->next != head) {
                temp = temp->next;
            }
            struct node* delnode = head;
            temp->next = head->next;
            head = head->next;
            free(delnode);
        }
        return 1;
    }

int list:: deleteend() {
        if (head == NULL) {
            printf("List is empty.\n");
            return -1;
        }

        struct node* temp = head;
        if (head->next == head) {
            head = NULL;
            free(temp);
        } else {
            while (temp->next->next != head) {
                temp = temp->next;
            }
            struct node* delnode = temp->next;
            temp->next = head;
            free(delnode);
        }
        return 1;
    }

int list:: deletepos(int pos) {
        if (head == NULL) {
            printf("List is empty.\n");
            return -1;
        }

        if (pos == 1) {
            deletebeg();
            return 1;
        }

        struct node* temp = head;
        for (int i = 1; i < pos - 1; ++i) {
            temp = temp->next;
            if (temp->next == head) {
                printf("Position out of range\n");
                return -1;
            }
        }

        struct node* delnode = temp->next;
        temp->next = delnode->next;
        free(delnode);
        return 1;
    }

int list::search(int num) {
        if (head == NULL) {
            printf("List is empty.\n");
            return -1;
        }

        struct node* temp = head;
        int pos = 1;
        do {
            if (temp->data == num) {
                printf("Number %d found at position %d\n", num, pos);
                return pos;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);

        printf("Number %d not found in the list\n", num);
        return -1;
    }

int list::display() {
        if (head == NULL) {
            printf("List is empty.\n");
            return 1;
        }

        struct node* temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
        return 1;
    }


