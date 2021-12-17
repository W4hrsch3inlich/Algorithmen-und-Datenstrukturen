#include <stdio.h>
#include <stdlib.h>

typedef struct element *list;
struct element { int value; list next; };

void append(list* lp, int n)
{
  if(*lp != NULL)
  {
    append(&((*lp)->next), n);
    return;
  }
  *lp = (list) malloc(sizeof(struct element));
  (*lp)->value = n;
  (*lp)->next = NULL;
}

void printList(list l)
{
  if(l == NULL)
  {
    printf("\n");
    return;
  }
  printf("%i ", l->value);
  printList(l->next);
}

typedef struct node *tree;
struct node { int key; tree left, right; };

tree createNode(int n, tree l, tree r)
{
  tree t = (tree) malloc(sizeof(struct node));
  t->key = n;
  t->left = l;
  t->right = r;
  return t;
}

void insertl(tree* tp, int n)
{
  if(tp != NULL)
  {
    insertl(&((*tp)->left), n);
    return;
  }
  *tp = createNode(n, NULL, NULL);
}

int leafprod(tree t)
{
  if(t == NULL)return 1;
  if(t->left == NULL && t->right == NULL)return t->key;
  return leafprod(t->left)*leafprod(t->right);
}

list treeToList(tree t)
{
  if(t == NULL)return NULL; 
  list l = treeToList(t->left);
  if(t->key % 2 == 0)append(&l, t->key);
  list r = treeToList(t->right);
  while(r != NULL)
  {
    append(&l, r->value);
    r = r->next;
  }
  return l;
}

int main() 
{
  tree t = createNode(4, 
                      createNode(1, NULL, NULL), 
                      createNode(2, createNode(6, NULL, NULL), NULL)
                      );
  printf("%i \n", leafprod(t));
  list l = treeToList(t);
  printList(l);
  return 0;
}
