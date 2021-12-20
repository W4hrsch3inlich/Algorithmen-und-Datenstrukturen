#include <stdio.h>
#include <stdlib.h>
#define MAX(x,y) ((x)>(y)) ? (x) : (y)

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

list treeToList(tree t)
{
  if(t == NULL)return NULL; 
  list l = treeToList(t->left);
  append(&l, t->key);
  list r = treeToList(t->right);
  while(r != NULL)
  {
    append(&l, r->value);
    r = r->next;
  }
  return l;
}

//////////////////////////////////////////////

int delmaxr(list* lp,int max)
{
  if(*lp == NULL)return max;
  max = delmaxr(&((*lp)->next), MAX(max, (*lp)->value));
  if((*lp)->value >= max)
  {
    list temp = *lp;
    *lp = (*lp)->next;
    free(temp);
  }
  return max;
}
void delmax(list* lp)
{
  if(*lp == NULL)return;
  delmaxr(lp, (*lp)->value);
}

int height(tree t)
{
  if(t == NULL)return 1;
  return MAX(height(t->left),height(t->right)) + 1;
}

tree bfs(tree t)
{
  if(t == NULL)return NULL;
  return createNode(height(t->right)-height(t->left), bfs(t->left), bfs(t->right));
}

int main() 
{
  int s = 3493;
  int a[s];
  for(int i = 0; i < s; i++)a[i] = 0;
  int count = primfac(a, s);
  for(int i = 0; i < count; i++)
  {
    printf("%i ", a[i]);
  } 
  printf("\n");
  
  list b = NULL;
  append(&b, 1);
  append(&b, 4);
  append(&b, 3);
  append(&b, 2);
  delmax(&b);
  printList(b);
  delmax(&b);
  printList(b);

  tree t = createNode
            (
                      1,
                      createNode(
                        2,
                        createNode(
                          3,
                          NULL,
                          NULL
                        ),
                        NULL
                      ),
                      createNode(
                        4,
                        createNode(
                          5,
                          NULL,
                          createNode(
                            6,
                            NULL,
                            NULL
                          )
                        ),
                        NULL
                      )
            );
  printf("%i\n", height(t));
  printList(treeToList(t));
  printList(treeToList(bfs(t)));
  return 0;
}
