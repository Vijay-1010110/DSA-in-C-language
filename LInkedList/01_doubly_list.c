#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

int countNodes(struct node* head){
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head = head -> next ;
        }
        return cnt;
}

void displayList(struct node * head){
    if(head == NULL){
        printf("\nLinked list is empty\n");
    }else{
        while(head != NULL){
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

struct node* createNode(int data){
    struct node * head = malloc(sizeof(struct node));
    if(head == NULL){
        printf("memory allocation is failed!..");
    }else{
        head->prev = NULL;
        head->data = data;
        head->next = NULL;
    }
    return head;

}

struct node* insertAtBeg(struct node *head,int data){
    if(head == NULL){
        head = createNode(data);
    }else{
        struct node *newNode = createNode(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    return head;
}


struct node * insertAtEnd(struct node *tail , int data){
    if(tail == NULL){
        printf("the list is empty first create a list\n");
    }else{
        struct node* newNode = createNode(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    return tail;
}

struct node* insertAtPos(struct node * head,int data,int pos){
    if(pos == 1){
        head = insertAtBeg(head,data);
    }else{
        struct node* newNode = createNode(data);
        struct node* ptr = head;
        while(pos > 2){
            ptr = ptr->next;
            pos--;
        }
        newNode->next = ptr->next;
        ptr->next->prev = newNode;
        ptr->next = newNode;
        newNode->prev =  ptr;
    }
    return head;
}


struct node* deleteFirst(struct node* head){
    if(head == NULL){
        printf("the list is aleady empty..\n");
    }else{
        struct node* ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        ptr=NULL;
    }
    return head;
}


struct node* deleteLast(struct node* tail){
    if (tail==NULL) 
        printf("the list is already empty.\n");
    else{
        struct node* ptr = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(ptr);
        ptr = NULL;
    }
    return tail;
}

//delete  last element using head pointer
void deleteLastHead(struct node* head){
    if(head == NULL )
        printf("list is alreay empty\n");
    else{
        struct node *ptr = head;
        while(ptr->next != NULL ){
            ptr = ptr->next;
        }
        free(ptr);
        ptr = NULL;
    }
}

struct node* deleteAtPos(struct node* head,int pos){
    int count = countNodes(head);
    if( pos < 1 || pos > count){
    printf("Invalid position");
    }
    else if(pos == 1 ){
        head = deleteFirst(head);
    }else if(pos == count){
        deleteLastHead(head);
    }
    else{
        struct node * ptr = head;
        while(pos != 1){
            ptr = ptr->next;
            pos--;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
        ptr = NULL;
    }
    return head;
}


void deleteEntireList(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        struct node *temp = current;
        current = current->next;
        free(temp);
    }
}


void reverseList(struct node **head, struct node **tail) {
    struct node *current = *head;
    struct node *temp = NULL;

    *tail = *head;
    while (current != NULL) {
        // Swap next and prev pointers of the current node
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        *head = current;
        // Move to the next node
        current = current->prev;
    }
    // Update the head and tail pointers   
}



int main(){

    struct node * head = NULL;
    struct node *tail = NULL;
    head = createNode(22);
    tail = head;
    head = insertAtBeg(head,1);
    tail = insertAtEnd(tail,99);
    tail = insertAtEnd(tail,101);
    head = insertAtBeg(head,-99);
    head = insertAtPos(head,44,3);
    head = insertAtPos(head,55,3);
    head = deleteFirst(head);//-99
    tail = deleteLast(tail); //101
    head = deleteAtPos(head,2);//55
    reverseList(&head,&tail);
    displayList(head);

    return 0;
}