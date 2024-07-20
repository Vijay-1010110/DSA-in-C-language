#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void num_of_nodes(struct node *head){
    int count = 0;
    if (head == NULL) {
        printf("List is empty\n");
        return ;
    }
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        count++;
        printf("%d ",ptr->data);
        ptr = ptr->link;        
    }
    printf("\n%d nodes",count);

}

void insert_at_end(struct node *head , int data){
    struct node *new_node,*ptr;
    new_node=(struct node*)malloc(sizeof(struct node));
    ptr = head;

    new_node->data = data;
    new_node->link = NULL;

    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = new_node;
}

int main(){

    struct node *head = malloc(sizeof(struct node));
    head->data = 111;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data=222;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data=333;
    current->link = NULL;
    head->link->link = current;

    insert_at_end(head,444);
    insert_at_end(head,555);
        num_of_nodes(head );

    return 0;
}