  // ADD TWO SPARSE MATRIX
  
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int r;
    int c;
    int v;
    struct node *next;
};

//----------------CREATE--------------------------

void create(struct node **h)
{
    struct node *cur, *ptr;
    cur = (struct node *)malloc(sizeof(struct node));
    cur->next = NULL;

    printf("Enter the no. of row:-");
    scanf("%d", &cur->r);
    printf("Enter the no. of col:-");
    scanf("%d", &cur->c);
    printf("Enter the no. of non zero elements:-");
    scanf("%d", &cur->v);
    *h = ptr = cur;
    for (int i = 1; i <= (*h)->v; i++)
    {
        cur = (struct node *)malloc(sizeof(struct node));
        cur->next = NULL;
        printf("Enter the row no.:-");
        scanf("%d", &cur->r);
        printf("Enter the col no.:-");
        scanf("%d", &cur->c);
        printf("Enter the value:-");
        scanf("%d", &cur->v);
        ptr->next = cur;
        ptr = cur;
    }
}
//--------------------------DISPLAY-------------------------------

void display(struct node *h)
{
    while (h != NULL)
    {
        printf("%d\t%d\t%d\n", h->r, h->c, h->v);
        h = h->next;
    }
}

//---------ADDITION------------------------------------------
void add(struct node *h)
{
    struct node *ptr = h->next, *ptr1, *prv;
    while (ptr != NULL)
    {
        prv = ptr;
        ptr1 = ptr->next;
        while (ptr1 != NULL)
        {
            if ((ptr->c == ptr1->c) && (ptr->r == ptr1->r))
            {
                hz->v--;
                ptr->v += ptr1->v;
                prv->next = ptr1->next;
                free(ptr1);
                ptr1 = prv;
            }
            prv = ptr1;
            ptr1 = ptr1->next;
        }
        ptr = ptr->next;
    }
}

//-----------------------JOIN FUNCTION----------------

void join(struct node *h1, struct node *h2, struct node **h)
{
    if (h1->c != h2->c || h1->r != h2->r)
    {
        printf("The matrix are not same\n");
        return;
    }
    *h = NULL;
    h1->v += h2->v;
    struct node *cur, *ptr;
    while (h1 != NULL)
    {
        cur = (struct node *)malloc(sizeof(struct node));
        *cur = *h1;
        cur->next = NULL;
        if (*h == NULL)
        {
            *h = ptr = cur;
        }
        else
        {
            ptr->next = cur;
            ptr = cur;
        }
        h1 = h1->next;
    }
    h2 = h2->next;
    while (h2 != NULL)
    {
        cur = (struct node *)malloc(sizeof(struct node));
        *cur = *h2;
        cur->next = NULL;
        ptr->next = cur;
        ptr = cur;
        h2 = h2->next;
    }
    add(*h);
    printf("After addition\n");
    display(*h);
}

//------------- MAIN FUNCTION ------------------------

int main()
{
    struct node *h1, *h2, *h;

    printf("Enter the data for 1st matrix\n");
    create(&h1);

    printf("Enter the data for 2nd matrix\n");
    create(&h2);

    printf("The 1st matrix:-\n");
    display(h1);

    printf("The 2nd matrix:-\n");
    display(h2);

    join(h1, h2, &h);
}