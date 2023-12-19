//
// 2023.10.24 C main
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 100

struct element
{
  int data;
  struct element *next;
};

struct element *make_sequence(int);
struct element *prime(struct element *list);
void print_list(struct element *list);
struct element *new_element(int);

int main()
{
  struct element *list;

  srandom(time(NULL));
  list = make_sequence(N);
  print_list(list);
  printf("\nPrime numbers <= %d:\n", N);
  list = prime(list);
  print_list(list);
  return 0;
}

struct element *make_sequence(int n)
{
  int i;
  struct element *list, *current;

  current = list = new_element(2);
  for (i = 3; i <= 100; i++)
  {
    current->next = new_element(i);
    current = current->next;
  }

  return list;
}

struct element *prime(struct element *list)
{
  struct element *p, *previous, *current;

  p = list;

  while (p->data <= sqrt(N))
  {
    current = p->next;
    previous = p;
    while (current != NULL)
    {
      if (current->data % p->data == 0)
      {
        current = current->next;
        free(previous->next);
        previous->next = current;
      }
      else
      {
        current = current->next;
        previous = previous->next;
      }
    }
    p = p->next;
  }
  return list;
}

struct element *new_element(int i)
{
  struct element *new;

  if ((new = malloc(sizeof(struct element))) == NULL)
  {
    fprintf(stderr, "Error: failure in malloc()\n");
    exit(1);
  }

  new->data = i;
  new->next = NULL;
  return new;
}

void print_list(struct element *list)
{
  while (list != NULL)
  {
    printf("%d ", list->data);
    list = list->next;
  }
  printf("\n");
}
