#include<stdio.h>
#include<stdlib.h>

struct node_ {
  int data;
  struct node_ *next;
};

typedef struct node_ node;

node *build123();
void print_list(node*);

main() {
  node *head;
  head = build123();
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
