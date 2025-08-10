
#include <stdio.h>
#include <stdlib.h>

typedef struct DNode{
    int data;
    struct DNode *prev, *next;
} DNode;

DNode* newNode(int x){
    DNode* p = malloc(sizeof(DNode));
    p->data=x; p->prev=p->next=NULL; return p;
}

void insert_after(DNode *node, int val){
    if(!node) return;
    DNode *n = newNode(val);
    n->next = node->next;
    n->prev = node;
    if(node->next) node->next->prev = n;
    node->next = n;
}

void delete_node(DNode **head, DNode *node){
    if(!node || !head || !*head) return;
    if(node->prev) node->prev->next = node->next;
    else *head = node->next;
    if(node->next) node->next->prev = node->prev;
    free(node);
}

void print_forward(DNode *head){
    for(DNode *p=head;p;p=p->next) printf("%d ", p->data);
    printf("\n");
}

int main(){
    
    DNode *head = newNode(10);
    insert_after(head, 20);
    insert_after(head->next, 30);
    printf("Original list: ");
    print_forward(head);
    printf("Insert 25 after 20:\n");
    insert_after(head->next, 25);
    print_forward(head);
    printf("Delete node with 20:\n");
    delete_node(&head, head->next); 
    print_forward(head);
    return 0;
}