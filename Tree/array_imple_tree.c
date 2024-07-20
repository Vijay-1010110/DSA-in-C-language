#include <stdio.h>
#include <stdlib.h>
#define MAX 10

char tree[MAX];

//protocols
void root(char);
void left(char, int);
void right(char, int);
void print();

int main(){
    root('A');
    left('B',0);
    right('c',0);
    left('D',1);
    right('E',2);
    print();
}

void root(char c){
    if(tree[0] != '\0')
        printf("Root already exist \n");
    else
        tree[0] = c;
}

void left(char c, int parent){
    if(tree[parent] == '\0')
        print("Can't insert %c . Perent of %c doesn't exist . \n",c,c);
    else
        tree[(2 * parent) + 1] = c;
}

void right(char c, int parent){
    if(tree[parent] == '\0')
        print("Can't insert %c . Perent of %c doesn't exist . \n",c,c);
    else
        tree[(2 * parent) + 2] = c;
}

void print(){
    for(int i = 0 ; i < MAX ; i++){
        if(tree[i] == '\0')
            printf("* ");
        else
            printf("%c ",tree[i]);
    }
}