#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
void enqueue()
{
    int value;
    struct Node *newNode;
    printf("Enter value: ");
    scanf("%d", &value);
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
  }
    printf("%d inserted into queue.\n", value);
}
void dequeue()
{
    struct Node *temp;
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    temp = front;
    printf("%d deleted from queue.\n", front->data);
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    free(temp);
}
void display()
{
    struct Node *temp;
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
   }
    temp = front;
    printf("Queue elements are: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
   }
    printf("\n");
}
int main()
{
    int choice;
    while (1)
    {
        printf("\nQueue Using Linked List\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            enqueue();
        }
        else if (choice == 2)
        {
            dequeue();
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 4)
        {
            printf("Program end.\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}