//queue using linked list
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

// Function to insert an element into the queue
void insert(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to delete the front element from the queue
int delete() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = front->data;
    struct node* temp = front;
    front = front->next;
    free(temp);
    if(front == NULL) {
        rear = NULL;
    }
    return data;
}

// Function to display the queue
void display() {
    struct node* current = front;
    if(front == NULL) {
        printf("Queue is empty\n");
    } else {
        while(current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, data;
    while(1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                data = delete();
                if(data != -1) {
                    printf("Deleted element: %d\n", data);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}