#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;
void push(int value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
void pop() {
    struct Node *temp;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    temp = top;
    printf("Popped element = %d\n", top->data);
    top = top->next;
    free(temp);
}
void peek() {
    if (top == NULL)
        printf("Stack is empty\n");
    else
        printf("Top element = %d\n", top->data);
}
void display() {
    struct Node *temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int n, value, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }
    display();
    pop();
    pop();
    display();
    peek();
    return 0;
}
/*int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
        }
        else if (choice == 2)
        {
            pop();
        }
        else if (choice == 3)
        {
            peek();
        }
        else if (choice == 4)
        {
            display();
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
        
    }

    return 0;
}
    }*/