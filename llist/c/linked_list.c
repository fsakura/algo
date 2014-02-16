#include<stdio.h>
#include<stdlib.h>

struct node_ {
  int data;
  struct node_ *next;
};

typedef struct node_ node;

node *build123();
void print_list(node*);
void reverse_list(node**);
void append_node(node*, int);
void append_node_atstart(node**, int);
int delete_node(node**, int);

main() {
  node *head;
  head = build123();
  print_list(head);
  reverse_list(&head);
  print_list(head);
  append_node(head, 4);
  print_list(head);
  append_node_atstart(&head, 5);
  print_list(head);
  reverse_list(&head);
  print_list(head);
  delete_node(&head, 4);
  print_list(head);
}

node *build123() {
  node *head, *second, *third;
  head = (node*)malloc(sizeof(node));
  second = (node*)malloc(sizeof(node));
  third = (node*)malloc(sizeof(node));  
  
  head->data = 1;
  second->data = 2;
  third->data = 3;
  
  head->next = second;
  second->next = third;
  
  return head;
}

void print_list(node *head) {
  while(head) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

void reverse_list(node **headRef) {
  node *prev, *curr, *next;
  curr = *headRef;
  prev = NULL;
  next = NULL;
  
  while(curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  
  *headRef = prev;
}

void append_node(node *head, int data) {
  node *new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  
  while(NULL != head->next) {
    head = head->next;
  }
  
  head->next = new_node;
}

void append_node_atstart(node **headRef, int data) {
  node *new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  
  new_node->next = *headRef;
  *headRef = new_node;
}

int delete_node(node **headRef, int data) {
  node *head = *headRef;
  
  if(!head) return;
  
  if(head->data == data) {
    head = head->next;
    *headRef = head;
  }
  
  while(head->next) {
    if((head->next)->data == data) {
      node *next_node = head->next;
      head->next = next_node->next;
      free(next_node);
      return 1;
    }
    
    head = head->next;
  }
  
  return 0;
}
