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
        printf("Enter the coefficient for term %d : [",i+1);
        scanf("%f",&coeff);
        printf("\b]");

        printf("Enter the exponent for term %d : X^",i+1);
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

void multiplyPolynomial(struct node* head1 , struct node* head2){
    struct node* result = NULL;
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;

    if(ptr1 == NULL || ptr2 == NULL){
        printf("zero polynomial \n");
        return;
    }

    while(ptr1 != NULL){
        ptr2 = head2;
        while(ptr2 != NULL){
            result = insert(result , ptr1->coefficient * ptr2->coefficient ,ptr1->exponent + ptr2->exponent);
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }

    printf("\nMultification result\n");
    print(result);

    //add the same exponent values
    struct node* ptr3 = result;
    struct node *temp = NULL;
    while(ptr3->link != NULL){
        if(ptr3->exponent == ptr3->link->exponent){
            ptr3->coefficient = ptr3->coefficient + ptr3->link->coefficient;
            temp = ptr3->link;
            ptr3->link = ptr3->link->link;
            free(temp);
        }else{
            ptr3 = ptr3->link;
        }
    }
    //after simpilification
    printf("\nsimplified multiplication result\n");
    print(result);
}


int main(){

    struct node* head1 = NULL;
    printf("Enter first Polynomial \n");
    head1 = create(head1);
    print(head1);

    struct node* head2 = NULL;
    printf("Enter second Polynomial \n");
    head2 = create(head2);
    print(head2);
    // printf("\n%d",countNodes(head));
    //resultiply two polynomial
    printf("\nmultiply two polynomial \n");
    multiplyPolynomial(head1,head2);
    return 0;
}