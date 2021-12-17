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

int sum(list l)
{
  if(l == NULL)return 0;
  return l->value + sum(l->next);
}

void rmEvens(list* lp)
{
  if(*lp == NULL)return;
  if((*lp)->value % 2 == 0)
  {
    list tmp = *lp;
    *lp = (*lp)->next;
    free(tmp);
    rmEvens(lp);
    return;
  }
  rmEvens(&((*lp)->next));
}

int main() 
{
  list l = NULL;
  append(&l, 4);
  append(&l, 1);
  append(&l, 2);
  append(&l, 3);
  append(&l, 0);
  printList(l);
  printf("%i \n", sum(l));
  rmEvens(&l);
  printList(l);
  return 0;
}
