
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* newNode(int x){
    Node* p = malloc(sizeof(Node));
    p->data = x; p->next = NULL; return p;
}

void push(Node **head, int x){
    Node *n = newNode(x);
    n->next = *head; *head = n;
}


void reverse_print(Node *head){
    if(!head) return;
    reverse_print(head->next);
    printf("%d ", head->data);
}

int main(){
    Node *head = NULL;
    
    push(&head,4); push(&head,3); push(&head,2); push(&head,1);
    printf("Forward order (head to tail): ");
    for(Node *p=head;p;p=p->next) printf("%d ", p->data);
    printf("\nReverse traversal output: ");
    reverse_print(head);
    printf("\n");
    return 0;
}