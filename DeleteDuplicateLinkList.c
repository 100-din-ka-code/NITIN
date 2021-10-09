//Write a function that will delete all the duplicate elements of a linked list.
#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
} *head = NULL, *tail = NULL;

void create(struct node **head, int n)
{
  for (int i = 0; i < n; i++)
  {
    struct node *cur;
    cur = malloc(sizeof(struct node));
    cur->data = rand() % 100;
    cur->next = NULL;
    if (*head == NULL)
    {
      *head = tail = cur;
    }
    else
    {
      tail->next = cur;
      tail = cur;
    }
  }
}

void insert(struct node **head, int n, int a)
{
  struct node *cur;
  struct node *ptr = *head;
  cur = malloc(sizeof(struct node));
  cur->data = n;
  cur->next = NULL;
  if (*head == NULL || a == 0)
  {
    cur->next = *head;
    *head = cur;
  }
  else
  {
    int i = 1;
    while (ptr != NULL && i < a)
    {
      i++;
      ptr = ptr->next;
    }
    if (ptr != NULL)
    {
      cur->next = ptr->next;
      ptr->next = cur;
    }
  }
}

void remdup(struct node **head)
{
  struct node *ptr, *qtr, *dup;
  ptr = *head;

  while (ptr != NULL && ptr->next != NULL)
  {
    qtr = ptr;

    while (qtr->next != NULL)
    {
      if (ptr->data == qtr->next->data)
      {
        dup = qtr->next;
        qtr->next = qtr->next->next;
        free(dup);
      }
      else
        qtr = qtr->next;
    }
    ptr = ptr->next;
  }
}

void display(struct node *p)
{
  if (p == NULL)
  {
    printf("\nThe List Is Empty :(");
  }
  printf("\n");
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->next;
  }
}

int main()
{
  int n;
  printf("Enter the length of the list: ");
  scanf("%d", &n);
  create(&head, n);
  printf("List before insertion:");
  display(head);
  printf("\nList after insertion:");
  insert(&head, 34, 3);
  insert(&head, 57, 0);
  insert(&head, 24, 2);
  display(head);
  printf("\nList after deletion:");
  remdup(&head);
  display(head);
  return 0;
}
