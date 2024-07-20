#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* push(struct node* head ,int val){
    struct node * newP = malloc(sizeof(struct node));
    newP->data = val;
    newP->link = head;
    head = newP;
    return head;
}

struct node* add(struct node * head1, struct node * head2) {
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;
    int sum = 0, carry = 0;

    while (ptr1 != NULL || ptr2 != NULL) {
        int num1 = (ptr1 != NULL) ? ptr1->data : 0;
        int num2 = (ptr2 != NULL) ? ptr2->data : 0;
        sum = num1 + num2 + carry;

        carry = sum / 10;
        sum = sum % 10;

        head3 = push(head3, sum);

        if (ptr1 != NULL) ptr1 = ptr1->link;
        if (ptr2 != NULL) ptr2 = ptr2->link;
    }

    if (carry > 0) {
        head3 = push(head3, carry);
    }

    return head3;
}

struct node* reverseLL(struct node* head){
    if (head == NULL ) return head;
    struct node* current = NULL;
    struct node* next = head->link;
    head->link = NULL;
    while(next != NULL){
        current = next;
        next = next->link;
        current->link = head;
        head = current;
    }
    return head;
}

struct node* addNode(struct node* head , int data){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;

    newNode->link = head;
    head = newNode;
    return head;
}

struct node* createLL(struct node* head , int n){
    while(n != 0){
        head = addNode(head,n%10);
        n = n/10;
    }
    return head;
}


void print(struct node* head){
    struct node* temp = head;
    if(temp == NULL)
    printf("NO number ");
    else{
        while(temp->link != NULL){
            printf("%d -> ",temp->data);
            temp = temp->link;
        }
        printf("%d\n",temp->data);
    }

}

void back2num(struct node *head){
    struct node* temp = head;
    printf("Result\n");
    while(temp){
        printf("%d",temp->data);
        temp = temp->link;
    }
    return;
}

int main(){

    int a,b;
    printf("Enter Two Numbers : ");
    scanf("%d %d",&a,&b);

    printf("Linked List representataion of first number\n");
    struct node* head1 = NULL;
    head1 = createLL(head1,a);
    print(head1);

    printf("Linked List representataion of second number\n");
    struct node* head2 = NULL;
    head2 = createLL(head2,b);
    print(head2);

    printf("***************reverse list***********************\n");
    head1 = reverseLL(head1);
    print(head1);
    head2 = reverseLL(head2);
    print(head2);

    printf("******************Resultant LinkedList*****************\n");
    struct node* head3 = NULL;
    head3 = add(head1,head2);
    print(head3);

    printf("**********rResult********\n");
    back2num(head3);


    return 0;
}