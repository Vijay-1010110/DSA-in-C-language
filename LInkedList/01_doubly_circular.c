#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} doublyList;

doublyList *createNode(int data)
{
    doublyList *tail = malloc(sizeof(doublyList));
    if (tail == NULL)
        printf("Memory allocation failed\n");
    tail->data = data;
    tail->prev = tail;
    tail->next = tail;
    return tail;
}

doublyList *insertAtBeg(doublyList *tail, int data)
{
    if (tail == NULL)
    {
        return createNode(data);
    }

    doublyList *newNode = createNode(data);
    newNode->next = tail->next;
    newNode->prev = tail;
    tail->next = newNode;
    newNode->next->prev = newNode; // Update the previous node's next pointer

    return tail;
}

doublyList *insertAtEnd(doublyList *tail, int data)
{
    if (tail == NULL)
    {
        tail = createNode(data);
        return tail;
    }

    doublyList *temp = createNode(data);
    temp->next = tail->next;
    tail->next = temp;
    temp->prev = tail;
    temp->next->prev = temp; // Update the previous node's next pointer

    tail = temp; // Move the tail pointer to the new last node

    return tail;
}

doublyList *insertAtPos(doublyList *tail, int data, int pos)
{
    if (pos <= 0)
    {
        printf("The position must be a non-negative and non-zero value.\n");
        return tail;
    }

    if (pos == 1)
    {
        return insertAtBeg(tail, data);
    }

    if (tail == NULL)
    {
        printf("The list is empty.\n");
        return tail;
    }

    doublyList *newNode = createNode(data);
    doublyList *current = tail->next;

    while (pos > 2 && current->next != tail->next)
    {
        current = current->next;
        pos--;
    }

    newNode->next = current->next;
    newNode->prev = current;

    current->next = newNode;
    newNode->next->prev = newNode;

    if (current == tail)
    {
        tail = newNode;
    }

    return tail;
}

// under construction
doublyList *deleteFirst(doublyList *tail)
{
    if (tail == NULL)
    {
        printf("the list is empty!\n");
    }
    else
    {
        doublyList *ptr = tail->next;
        tail->next = ptr->next;
        ptr->next->prev = tail;
        free(ptr);
        ptr = NULL;
    }
    return tail;
}

doublyList *deleteLast(doublyList *tail)
{
    if (tail == NULL)
    {
        printf("the list is empty!\n");
    }
    else
    {
        doublyList *ptr = tail;
        tail = tail->prev;
        tail->next = ptr->next;
        ptr->next->prev = tail;
        free(ptr);
        ptr = NULL;
    }
    return tail;
}

doublyList *deleteAtPos(doublyList *tail, int pos)
{
    if (pos == 1)
        return deleteFirst(tail);
    else if (pos <= 0)
    {
        printf("Position should be greater than zero\n");
        return tail;
    }
    else
    {
        doublyList *temp = tail->next;
        for (int i = 2; i <= pos - 1; i++)
        {
            temp = temp->next;

            if (temp == tail && pos > 2)
            {
                printf("Position out of range\n");
                return tail;
            }
        }
        if (temp == tail)
            return deleteLast(tail);

        doublyList *temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        free(temp2);
        temp2 = NULL;
        return tail;
    }
}


void deleteEntireList(doublyList* tail) {
    if (tail == NULL) {
        printf("The list is already empty.\n");
        return;
    }

    doublyList* current = tail->next;

    do {
        doublyList* temp = current;
        current = current->next;
        free(temp);
    } while (current != tail->next);

    tail = NULL;
    printf("The entire list has been deleted.\n");
}




int countNodes(doublyList *tail)
{
    doublyList *ptr = tail->next;
    int count = 0;
    while (ptr != tail)
    {
        ptr = ptr->next;
        count++;
    }
    count++;
    return count;
}

void print(doublyList *tail)
{
    if (tail == NULL)
    {
        printf("The list is empty!\n");
        return;
    }

    doublyList *ptr = tail->next;

    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next);

    printf("\n");
}

void revPrint(doublyList *tail)
{
    if (tail == NULL)
    {
        printf("The list is empty!\n");
        return;
    }

    doublyList *ptr = tail;

    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    } while (ptr != tail);

    printf("\n");
}

int main()
{

    doublyList *tail = NULL;
    tail = insertAtBeg(tail, 29);
    tail = insertAtBeg(tail, 25);
    tail = insertAtEnd(tail, 45);
    tail = insertAtEnd(tail, 89);
    tail = insertAtBeg(tail, 22);
    tail = insertAtBeg(tail, 78);
    tail = insertAtEnd(tail,99);
    tail = insertAtPos(tail,1,1);
    tail = insertAtPos(tail,6,6);
    tail = insertAtBeg(tail, 0);
    tail = insertAtPos(tail, 777, 8);
    tail = deleteAtPos(tail, 3);
    tail = deleteAtPos(tail, 3);

    //  tail = deleteLast(tail);
    //  tail = deleteFirst(tail);

    // tail = deleteFirst(tail);
    // tail = deleteLast(tail);
    // tail = deleteLast(tail);

    /*
    // debuging
    // */
    // doublyList *ptr = tail->next;

    // printf("\n*********************************\n");

    // printf("%d ", ptr->data);
    // ptr = ptr->next;
    // printf("%d ", ptr->data);
    // ptr = ptr->next;
    // printf("%d ", ptr->data);
    // ptr = ptr->next;
    // printf("%d ", ptr->data);
    // ptr = ptr->next;
    // printf("%d ", ptr->data);
    // ptr = ptr->next;
    // printf("%d ", ptr->data);
    // ptr = ptr->next;
    // printf("%d ", ptr->data);
    // ptr = ptr->next;
    // printf("%d ", ptr->data);

    // // reverse
    // printf("\n*********************************\n");
    // ptr = tail;
    // printf("%d ", ptr->data);
    // ptr = ptr->prev;
    // printf("%d ", ptr->data);
    // ptr = ptr->prev;
    // printf("%d ", ptr->data);
    // ptr = ptr->prev;
    // printf("%d ", ptr->data);
    // ptr = ptr->prev;
    // printf("%d ", ptr->data);
    // ptr = ptr->prev;
    // printf("%d ", ptr->data);
    // ptr = ptr->prev;
    // printf("%d ", ptr->data);
    // ptr = ptr->prev;
    // printf("%d ", ptr->data);

    // printf("\n*********************************\n\n");

    //

    //for debuging^^^^^^^^^


     printf("\n*********************************\n");
    print(tail);
    // printf("\n*********************************\n");
    // revPrint(tail);
    printf("\n*********************************\n");
    printf("no of nodes : %d", countNodes(tail));
    printf("\n*********************************\n");

    return 0;
}