#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL, *temp, *new_node;

void enqueue();
void dequeue();
void display();

void main()
{
    int ch;

    printf("\n***** MENU *****");
    printf("\n1. INSERT");
    printf("\n2. DELETE");
    printf("\n3. DISPLAY");
    printf("\n4. EXIT");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
        }
    }
}

// ENQUEUE (INSERT)
void enqueue()
{
    new_node = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the element to insert: ");
    scanf("%d", &new_node->data);

    new_node->next = NULL;

    if (rear == NULL)
    {
        front = rear = new_node;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
}

// DEQUEUE (DELETE)
void dequeue()
{
    if (front == NULL)
    {
        printf("\nQUEUE UNDERFLOW");
    }
    else
    {
        temp = front;
        printf("\nDeleted element is %d", front->data);
        front = front->next;

        if (front == NULL)
            rear = NULL;

        free(temp);
    }
}

// DISPLAY
void display()
{
    if (front == NULL)
    {
        printf("\nThere are no elements in the queue");
    }
    else
    {
        temp = front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
