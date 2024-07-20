#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}


struct Node* insertAtEnd(struct Node *lastNode, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return lastNode;
    }

    if (lastNode == NULL) {
        // If the list is empty, the new node becomes the head.
        return newNode;
    }

    // Connect the new node to the last node.
    lastNode->next = newNode;
    
    // Update the last node pointer to the new node.
    lastNode = newNode;
    
    return lastNode; // Return the new last node.
}



struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    if (head == NULL) {
        // If the list is empty, the new node becomes the head.
        return newNode;
    } else {
        // Make the new node the head of the list.
        newNode->next = head;
        return newNode;
    }
}


struct Node* insertAtPos(struct Node head* , int data , int pos){

}

struct Node* insertAtPos(struct Node* head, int data, int pos) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    if (pos == 1) {
        // Insert at the beginning.
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    int currentPos = 1;

    while (current != NULL && currentPos < pos - 1) {
        current = current->next;
        currentPos++;
    }

    if (current == NULL) {
        printf("Position %d is beyond the end of the list.\n", pos);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    
    return head;
}


struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete the first node.\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);

    return head;
}


struct Node* deleteLast(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete the last node.\n");
        return NULL;
    }

    // If there's only one node in the list, delete it and set the head to NULL.
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* current = head;
    struct Node* previous = NULL;

    // Traverse the list to find the last node.
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    // Update the previous node to remove the reference to the last node.
    previous->next = NULL;

    // Free the memory of the last node.
    free(current);

    return head;
}


struct Node* deleteAtPos(struct Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty. Cannot delete at position %d.\n", pos);
        return NULL;
    }

    if (pos == 1) {
        // Delete the first node.
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int currentPos = 1;
    struct Node* current = head;
    struct Node* previous = NULL;

    while (current != NULL && currentPos < pos) {
        previous = current;
        current = current->next;
        currentPos++;
    }

    if (current == NULL) {
        printf("Position %d is beyond the end of the list. Cannot delete.\n", pos);
        return head;
    }

    // Update the previous node to skip the current node.
    previous->next = current->next;
    free(current);

    return head;
}


void deleteEntireList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}



void displayNodes(struct Node *head){
    while (head != NULL) {
        printf("%d ", head->data);
        head=head->next;
        }
        printf("\n");
    
}



int main(){
    struct Node *head = NULL;
    head = createNode(22);
    struct Node* lastNode = head;
    lastNode = insertAtEnd(lastNode,45);
    head = insertAtBegining(head,55);

    displayNodes(head);


    return 0;
}