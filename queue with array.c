#include <stdio.h>
#include <stdlib.h>

int queue[50], n, element, rear = -1, front = 0;

void enqueue();
void dequeue();
void display();

void main()
{
    int ch;

    printf("\nEnter the size of the queue: ");
    scanf("%d", &n);

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

// ENQUEUE
void enqueue()
{
    if (rear == n - 1)
    {
        printf("\nQUEUE OVERFLOW");
    }
    else
    {
        printf("\nEnter the element to insert: ");
        scanf("%d", &element);

        rear++;
        queue[rear] = element;
    }
}

// DEQUEUE
void dequeue()
{
    if (front > rear)
    {
        printf("\nQUEUE UNDERFLOW");
    }
    else
    {
        printf("\nDeleted element is %d", queue[front]);
        front++;

        if (front > rear)
        {
            front = 0;
            rear = -1;
        }
    }
}

// DISPLAY
void display()
{
    int i;

    if (front > rear)
    {
        printf("\nThere are no elements in the queue");
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}
