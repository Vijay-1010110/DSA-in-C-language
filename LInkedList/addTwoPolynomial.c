#include <stdio.h>
#include <stdlib.h>

struct node{
    float coefficient;
    int exponent;
    struct node *link;
};

struct node* insert(struct node *head , float co , int ex){
    struct node* temp = NULL;
    struct node* newP = malloc(sizeof(struct node));
    newP->coefficient = co;
    newP->exponent = ex;
    newP->link = NULL;

    //if there is no node in the list or exponent greter thatn the first node exponent
    if(head == NULL || ex > head->exponent){
        newP -> link = head ;
        head = newP;
    }else{
        temp = head;
        while(temp->link != NULL && temp->link->exponent >= ex)
            temp= temp->link;
        newP->link = temp->link;
        temp->link = newP;
    }
    return head;
}


struct node* create(struct node* head){
    int n,i;
    float coeff;
    int expo;

    printf("Enter the number of terms : ");
    scanf("%d",&n);

    for(i = 0 ; i < n ; i++){
        printf("Enter the coefficient for term %d : ",i+1);
        scanf("%f",&coeff);
        printf("Enter the exponent for term %d : ",i+1);
        scanf("%d",&expo);

        head = insert(head,coeff,expo);
    }
    return head;
}

void print(struct node* head) {
    if (head == NULL) {
        printf("No Polynomial found\n");
    } else {
        struct node* temp = head;
        while (temp != NULL) {
            printf("(%.1fx^%d)", temp->coefficient, temp->exponent);
            if (temp->link != NULL) {
                printf(" + ");
            }
            temp = temp->link;
        }
        printf("\n");
    }
}


int countNodes(struct node* head) {
    int count = 0;
    struct node* current = head;

    while (current != NULL) {
        count++;
        current = current->link;
    }

    return count;
}

void addPolynomial(struct node* head1, struct node* head2){
    struct node* result = NULL;
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->exponent == ptr2->exponent){
            result = insert(result, (ptr1->coefficient + ptr2->coefficient), ptr1->exponent);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if(ptr1->exponent > ptr2->exponent){
            result = insert(result , ptr1->coefficient , ptr1->exponent);
            ptr1 = ptr1->link;
        }
        else if(ptr1->exponent < ptr2->exponent){
            result = insert(result , ptr2->coefficient , ptr2->exponent);
            ptr2 = ptr2->link;
        }
    }
    while(ptr1 != NULL){
        result = insert(result , ptr1->coefficient , ptr1->exponent);
        ptr1 = ptr1->link;
    }
    while(ptr2 != NULL){
        result = insert(result , ptr2->coefficient , ptr2->exponent);
        ptr2 = ptr2->link;
    }
    printf("Added polynomial is : \n");
    print(result);
}


int main(){

    struct node* head1 = NULL;
    printf("Enter Polynomial 1\n");
    head1 = create(head1);
    print(head1);

    //second node
    struct node* head2 = NULL;
    printf("Enter Polynomial 2\n");
    head2 = create(head2);
    print(head2);
    //printf("\n%d",countNodes(head));

    //addtwoPolnomial
    addPolynomial(head1,head2);
    return 0;
}