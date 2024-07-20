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
int main(){

    struct node* head = NULL;
    printf("Enter Polynomial\n");
    head = create(head);
    print(head);
    printf("\n%d",countNodes(head));
    return 0;
}