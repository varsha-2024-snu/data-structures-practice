#include <stdio.h>
#include <stdlib.h>
#define size 5

class hashlist {
    int arr[size];
    int cur;

public:
    hashlist() {
        cur = -1;
        for (int i = 0; i < size; i++) {
            arr[i] = -1;
        }
    }

    int insert(int n);
    int display();
    int search(int n);
    int deleteItem(int n);
};

int main() {
    hashlist h1;
    int choice, num;

    for (;;) {
        printf("1. insert\n2. display\n3. search\n4. delete\n5. exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter num to insert: ");
                scanf("%d", &num);
                h1.insert(num);
                break;

            case 2:
                h1.display();
                break;

            case 3:
                printf("Enter num to search: ");
                scanf("%d", &num);
                if (h1.search(num)) {
                    printf("Element %d found\n", num);
                } else {
                    printf("Element %d not found\n", num);
                }
                break;

            case 4:
                printf("Enter num to delete: ");
                scanf("%d", &num);
                if (h1.deleteItem(num)) {
                    printf("Element %d deleted\n", num);
                } else {
                    printf("Element %d not found\n", num);
                }
                break;

            case 5:
                return 0;
                break;
        }
    }
}

int hashlist::insert(int num) {
    if (cur == size - 1) {
        printf("Hash full\n");
        return 0;
    }
    int loc = num % size;
    while (arr[loc] != -1) {
        loc = (loc + 1) % size;
    }
    arr[loc] = num;
    cur++;
    return 1;
}

int hashlist::display() {
    for (int i = 0; i < size; i++) {
        if (arr[i] != -1) {
            printf("%d ", arr[i]);
        } else {
            printf("- ");
        }
    }
    printf("\n");
    return 1;
}

int hashlist::search(int num) {
    int loc = num % size;
    int start = loc;
    while (arr[loc] != -1) {
        if (arr[loc] == num) {
            return 1;
        }
        loc = (loc + 1) % size;
        if (loc == start) break;
    }
    return 0;
}

int hashlist::deleteItem(int num) {
    int loc = num % size;
    int start = loc;
    while (arr[loc] != -1) {
        if (arr[loc] == num) {
            arr[loc] = -1;
            cur--;
            return 1;
        }
        loc = (loc + 1) % size;
        if (loc == start) break;
    }
    return 0;
}
