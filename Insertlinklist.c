 // CODE FOR INSERTING IN LINKLIST USING MANUALLY WHEN DECLARED LOCALLY

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
 

void display(struct node *head) // display
{
    struct node * ptr;
    printf("Link list : ");
    for (ptr = head ; ptr != NULL ; ptr = ptr -> next)
    {
        printf("%d " , ptr -> data);
         printf("\n");
    }
   // printf("\n");
}

void insert(struct node **head,int value , int pos) //  for inserting 
{
    struct node * current , *ptr ;
    current = malloc(sizeof(struct node));
    current -> data = value;
    current -> next = NULL;

    if(head == NULL && pos != 0)
        printf("Invalid\n");

    else if (pos == 0) // inserting at begining

    {
        current -> next = *head;
        *head = current;
    }
    else  // inserting in MIDDLE  and end
    {
        ptr = *head;
        for (int i = 0; i < pos - 1 ; i++)
        {
            ptr = ptr -> next;
            if(ptr == NULL)
            {
                printf("Invalid\n");
                return;
            }
        }
        current -> next = ptr -> next;
        ptr -> next = current;
    }
   
}

int main()  //main function
{
    struct node *head = NULL; // locally declare

        insert(&head,2,0); //calling of insert function

        insert(&head,8,1);  //calling of insert function
        
        insert(&head,9,2);  //calling of insert function
        
        insert(&head,7,3);  //calling of insert function
        
        insert(&head,6,4);  //calling of insert function
        

        display(head);
    

    return 0;
}
