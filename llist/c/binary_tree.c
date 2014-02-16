#include<stdio.h>

struct _node {
  int data;
  struct _node *left;
  struct _node *right;
};

typedef struct _node node;

node *new_node(int);
node *build123();
node *insert(node*, node*);
void *BFS(node*);
main() {
  
}

node *new_node(int data) {
  node *new_node = (node*)malloc(sizeof(node));
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node build123() {
  node *root = new_node(2);
  node *left = new_node(1);
  node *right = new_node(3);
  root->left = left;
  root->right = right;
  return root;
}

node *insert(node *root, node *new_node) {
  if(NULL == root) {
    return new_node;
  } else {
    if(new_node->data <= root->data) {
      root->left = insert(root->left, new_node);
    } else {
      root->right = insert(root->right, new_node);
    }
    return root;
  }
}

void BFS(node *root) {
  
}
