#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createCircularLinkedList() {
    return NULL;
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (1) {
        if (current->data == data) {
            if (prev == NULL) {  // Deleting the first node
                struct Node* lastNode = current;
                while (lastNode->next != *head) {
                    lastNode = lastNode->next;
                }
                *head = current->next;
                lastNode->next = *head;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Node with data %d deleted.\n", data);
            return;
        }

        if (current->next == *head) {
            printf("Node with data %d not found.\n", data);
            return;
        }

        prev = current;
        current = current->next;
    }
}

void reverseList(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);

    (*head)->next = prev;
    *head = prev;
}

void concatenateLists(struct Node** list1, struct Node** list2) {
    if (*list1 == NULL) {
        *list1 = *list2;
    } else if (*list2 != NULL) {
        struct Node* lastNodeList1 = *list1;
        while (lastNodeList1->next != *list1) {
            lastNodeList1 = lastNodeList1->next;
        }
        lastNodeList1->next = *list2;
        struct Node* lastNodeList2 = *list2;
        while (lastNodeList2->next != *list2) {
            lastNodeList2 = lastNodeList2->next;
        }
        lastNodeList2->next = *list1;
    }

    *list2 = NULL;  // Clear the second list
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("...\n");
}

int main() {
    struct Node* list = createCircularLinkedList();
    struct Node* list2 = createCircularLinkedList();
    int choice, data;

    do {
        printf("\nCircular Linked List Menu:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Reverse List\n");
        printf("4. Concatenate Lists\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertNode(&list, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&list, data);
                break;
            case 3:
                reverseList(&list);
                break;
            case 4:
                printf("Create the second list to concatenate:\n");
                list2 = createCircularLinkedList();
                printf("Enter data for the second list (end with -1):\n");
                while (1) {
                    scanf("%d", &data);
                    if (data == -1) {
                        break;
                    }
                    insertNode(&list2, data);
                }
                concatenateLists(&list, &list2);
                break;
            case 5:
                printf("Circular Linked List: ");
                displayList(list);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    // Free allocated memory
    struct Node* current = list;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

