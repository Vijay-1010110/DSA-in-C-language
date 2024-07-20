 #include <stdio.h>
 #include <stdlib.h>

 struct node {
    struct node * left;
    struct node * right;
    int data;
 };

 //protocols
 struct node * insert_nonRec(struct node *, int );
 struct node * insert_rec(struct node * , int);
 struct node * createNode(int);
 void printBST(struct node *);
 
 int main(){
    
    struct node * root = NULL ;

    root = insert_nonRec(root,55);
    root = insert_nonRec(root,45);
    root = insert_nonRec(root,5);
    root = insert_nonRec(root,566);
    root = insert_nonRec(root,11);
    root = insert_nonRec(root,52);
    root = insert_nonRec(root,56);
    
    root = insert_rec(root,99);
    root = insert_rec(root,0);


    printBST(root);
    
 
    return 0;
 }


 //
 struct node * insert_nonRec(struct node * root , int ikey){
    struct node * ptr , *par;
    ptr = root;
    par = NULL;
    while(ptr){
        par = ptr;
        if(ikey < ptr->data)
            ptr= ptr->left;
        else if(ikey > ptr->data)
            ptr =  ptr->right;
        else{
            printf("Duplicate entry\n");
            return root;
        }
    }
    struct node * temp = createNode(ikey);
    if(par == NULL)
    root = temp ;
    else if (ikey < par->data )
    par->left =temp ;
    else
    par->right = temp ;

    return root;
 }

 //
 struct node * insert_rec(struct node * root, int ikey){
    if(root == NULL)
    return createNode(ikey);

    else if(ikey < root->data)  
    root->left = insert_rec(root->left , ikey);

    else if(ikey > root->data)
    root->right = insert_rec(root->right, ikey);

    else
    printf("Duplicate Entry!\n");

    return root;
 }


 //
 struct node* createNode(int data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

//
void printBST(struct node * root){
    if(root == NULL)
        return;
    printBST(root->left);
    printf("%d ",root->data);
    printBST(root->right);
}