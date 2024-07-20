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

//delete cases
struct node * case1(struct node *, struct node * , struct node *);//case1: if node have no child 
struct node * case2(struct node * , struct node * , struct node *);//case2 : if node have only one child eighter left or right
struct node * case3(struct node * , struct node *);//case 3 : node have both child left and right
struct node * del_nonRec(struct node * , int ); 


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

root =  del_nonRec(root,52);
root = del_nonRec(root,0);




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


//case 1 node have no child
struct node * case1(struct node * root , struct node * ptr , struct node * par ){
    if(par == NULL)
    root = NULL;

    else if(ptr == par->left)
    par->left = NULL;

    else
    par->right = NULL;

    free(ptr);
    return root;
}

//case 2 node have only one child eighter left or right
struct node * case2(struct node * root , struct node * ptr , struct node * par ){
    struct node * child;
    if(ptr->left != NULL)
    child = ptr->left;

    else if(ptr->right != NULL)
    child = ptr->right;

    if(par == NULL)//node to be deleted is the root node
    root = child;

    else if(ptr ==  par->left)
    par->left = child;

    else 
    par->right = child;

    free(ptr);
    return root;
}

//case 3: node have two child
struct node * case3(struct node * root , struct node * ptr){
    struct node * successor , *par_successor;
    par_successor = ptr;
    successor = ptr->right;

    while(successor != NULL){
        par_successor = successor ;
        successor = successor->left;
    }
    ptr->data = successor->data;

    if(successor->left == NULL && successor->right == NULL)
    root = case1(root,successor,par_successor);

    else
    root = case2(root,successor,par_successor);

    return  root;

}

//
struct node * del_nonRec(struct node * root , int dkey){
    struct node * ptr , * par;
    ptr = root;
    par = NULL;

    while(ptr != NULL){
        if(dkey == ptr->data)
        break;

        par = ptr;

        if(dkey < ptr->data)
        ptr = ptr->left;

        else
        ptr = ptr->right;
    }

    if(ptr->left != NULL && ptr->right != NULL)
        root = case3(root,ptr);
    
    else if(ptr->left != NULL || ptr->right != NULL)
    root = case2(root,ptr,par);

    else
    root = case1(root,ptr,par);

    return root;
    
}

