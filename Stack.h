//
// Created by misha on 3/31/2021.
//

#ifndef PRACTICE_STACK_H
#define PRACTICE_STACK_H
struct n{
    char data;
    struct n * next;
};

typedef struct n* Node;

void push(Node* top_p,  char e){
    Node new_node = (Node)malloc(sizeof (struct n));
    if(new_node == NULL){
        printf("Stack Overflow\n");
        exit(0);
    }
    new_node->data = e;
    new_node->next = (*top_p);
    *top_p = new_node;
}

char pop(Node* top_p){
    char ret;
    Node top = *top_p;
    ret = top->data;
    *top_p = top->next;
    free(top);
    return ret;
}

#endif //PRACTICE_STACK_H
