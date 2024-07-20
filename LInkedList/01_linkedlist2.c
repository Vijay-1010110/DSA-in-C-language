#include <stdio.h>
#include <stdlib.h>
//optimal code for insert at end time complexity O(1);

struct node{
    int data;
    struct node *link;
};

struct node* insert_at_end(struct node* lastNode, int data) {
    struct node* newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    newNode->data = data;
    newNode->link = NULL;

    if (lastNode == NULL) {
        // If the list is empty, make the new node the head
        return newNode;
    } else {
        lastNode->link = newNode;
        return newNode;
    }
}




void print_data(struct node *ptr){
    if (ptr == NULL) {
        printf("List is empty");
        return ;
        }
        while (ptr !=NULL ){
        printf("%d ", ptr -> data );
        ptr = ptr->link;
        }
        printf("\n");
}

struct node * insert_at_begining(struct node *head , int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link= head;
    return ptr;
}

//insert at certain position
void insert_at_pos(struct node *head , int data , int pos){
    
    struct node *ptr = head;
    struct node *ptr2 = malloc(sizeof(struct node));

    pos--;
    while(pos != 1){
        ptr = ptr->link;
        pos--;
    }
    ptr2->data = data;
    ptr2->link = ptr->link;
    ptr->link = ptr2;
}


//delete first node
struct node* delete_first(struct node *head){
    struct node *temp = head;
    if (head == NULL)
    printf("Empty List\n");
    else{
        head = head->link;
        free(temp);
        temp = NULL;
        }
        return head;
}

void delete_last(struct node *head){
    if(head == NULL)
    printf("List is empty.\n");
    else if(head->link == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct node*  temp = head;
        while(temp->link->link != NULL){
            temp = temp -> link ;
        }
        free(temp->link);
        temp->link = NULL;

        
    }
}

void delete_at_pos(struct node** head, int pos) {
    if (*head == NULL || pos <= 0) {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1) {
        struct node* temp = *head;
        *head = (*head)->link;
        free(temp);
        return;
    }

    struct node* current = *head;
    struct node* prev = NULL;

    while (pos != 1) {
        prev = current;
        current = current->link;
        pos--;

        if (current == NULL) {
            printf("Invalid Position\n");
            return;
        }
    }

    prev->link = current->link;
    free(current);
}


struct node* delete_entire_list(struct node* head) {
    struct node* temp;
    while (head != NULL) {
        temp = head->link;
        free(head);
        head = temp;
    }
    return NULL;
}


struct node* reverse_list(struct node *head){
    struct node * prev = NULL;
    struct node * next = NULL;

    while(head != NULL){
        next = head->link;
        head->link  = prev;
        prev= head;
        head = next;
    }
    head =  prev;
    return head;
}

int main(){

    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *lastNode = head;
    lastNode = insert_at_end(lastNode,56);
    lastNode = insert_at_end(lastNode,67);

    //insert at begining
    head = insert_at_begining(head,34);
    head = insert_at_begining(head,1);

    //insert at certain posintion
    insert_at_pos(head,89,2);

    //delete first node
    head = delete_first(head);

    //delete last node
    delete_last(head);
    delete_last(head);

    //delete at particular position
    //delete_at_pos(&head , 2);

    lastNode = insert_at_end(lastNode,44);
    lastNode = insert_at_end(lastNode,94);
    lastNode = insert_at_end(lastNode,76);
    lastNode = insert_at_end(lastNode,435);

    //delete entire list
  //  head = delete_entire_list(head);


  //reverse list
  head = reverse_list(head);


    print_data(head);


    return 0;
}


struct node* reverseDoublyList(struct node * head){
    struct node* temp = NULL;
    while(head->next != NULL){
        temp = head->prev;
        head->prev =  head->next;
        head->next = (struct node*)temp;
        head = head->next;
    }
    return head;
}