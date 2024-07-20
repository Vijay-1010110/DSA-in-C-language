//create a a funtion in c that perform operation on circluar singly linked list the insertAfter the position?
struct node* insertAfterPos(struct node* tail , int data , int pos){
    struct node * newNode = createNode(data);
    if(tail == NULL)
    printf("list not found!\n");
    if (pos == 0) {
        // Insert at the beginning.
        newNode->link = tail->link;
        tail->link = newNode;
        return tail;
    }
    struct node* current = tail->link;
    while(pos > 1){
        current = current->link;
        pos--;
    }
    if(current->link == tail->link){
        //insertAtEnd
        tail = insertAtEnd(tail,data);
    }
    newNode->link = current->link;
    current->link = newNode;

    return tail;
}