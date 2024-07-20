#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* createNode(int data){
    struct node * tail = malloc(sizeof(struct node));
    tail->data = data;
    tail->link = tail;
    return tail;
}

struct node* insertAtEnd(struct node* tail , int data){
    if(tail == NULL){
        tail = createNode(data);
        return tail;
    }
    
    struct node* ptr = createNode(data);
    ptr->link = tail->link;
    tail->link = ptr;
    tail = ptr;
    return tail;
}


struct node* insertAtBegining(struct node* tail, int data){
    if(tail == NULL){
        tail = createNode(data);
        return tail;
    }
    struct node* ptr = createNode(data);
    ptr->link = tail->link;
    tail->link = ptr;
    return tail;
}
struct node* insertAtPos(struct node* tail, int data, int pos) {
    if(pos <= 0){
        printf("\nInvalid position the position must be non negative or greater than zero");
        return tail;
    }
    if (tail == NULL) {
        printf("Circular linked list is empty.\n");
        return NULL;
    }

    struct node* newNode = createNode(data);
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return tail;
    }

    if (pos == 1) {
        newNode->link = tail->link;
        tail->link = newNode;
        return tail;
    }

    struct node* current = tail->link;
    int currentPos = 1;

    while (currentPos < pos - 1) {
        current = current->link;
        if (current == tail->link) {
            printf("Position %d is out of bounds.\n", pos);
            free(newNode);
            return tail;
        }
        currentPos++;
    }

    newNode->link = current->link;
    current->link = newNode;

    if (current == tail) {
        // If we inserted after the tail, update the tail to the new node.
        tail = newNode;
    }

    return tail;
}

struct node* deleteFirst(struct node* tail ){
    struct node* ptr = tail->link;
    tail->link = ptr->link;
    free(ptr);
    ptr = NULL;
    return tail;
}

struct node* deleteLast(struct node* tail){
    struct node* ptr = tail;
    do{
        tail = tail->link;
    }while(ptr != tail->link);
    tail->link = ptr->link;
    free(ptr);
    ptr = NULL;
    return tail;
}

struct node* deleteAtPos(struct node* tail, int pos){
    if(pos == 1){
        tail = deleteFirst(tail);
        return tail;
    }
    struct node* ptr = tail->link;
    while(pos > 2){
        ptr = ptr->link;
        if(tail == ptr->link){
            if(pos != 3){
                printf("position is out of bound!...");
                return tail;
            }

            tail = deleteLast(tail);
            return tail;
        }
        pos--;
    }
    struct node* temp = ptr->link;
    ptr->link = temp->link;
    free(temp);
    temp = NULL;
    return tail;
}

int countNodes(struct node * tail){
    struct node* ptr = tail->link;
    int count = 0;
    while(ptr != tail){
        ptr = ptr->link;
        count++;
    }
    count++;
    return count;
}


void print(struct node* tail){
     if (tail == NULL) {
        // If the list is empty (tail is NULL), print a message and return.
        printf("Circular linked list is empty.\n");
        return;
    }
    struct node* ptr = tail->link;
    do{
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }while (ptr != tail->link);
    printf("\n"); 
}


int main(){

    struct node * tail = NULL;  
    // tail = createNode(45);
    // tail = insertAtBegining(tail,3);
    // tail = insertAtEnd(tail,99);
    // tail = insertAtPos(tail,22,2);
    // tail = insertAtPos(tail,23,1);
    // tail = insertAtEnd(tail,34);
    // tail = insertAtEnd(tail,88);
    // tail = insertAtEnd(tail,555);

    // tail = deleteFirst(tail);
    // tail = deleteLast(tail);
    // tail = deleteAtPos(tail,1);
    // tail = deleteAtPos(tail,1);
    // tail = deleteAtPos(tail,3);

    int n;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);

    for(int i = 1 ; i <= n ; i++){
        int data;
        printf("Enter the value %d node : ",i);
        if(i == 1){
            scanf("%d", &data);
            tail = createNode(data);
        }else{
            scanf("%d", &data);
            tail = insertAtEnd(tail,data);
        }

    }

    print(tail);
    printf("count %d\n",countNodes(tail));


    //tail = insertAtBegining(tail,1);

    // printf("\n no of nodes %d\n",countNodes(tail));

    // print(tail);
    return 0;
}