#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
struct Stack
{
    int *arr;
    int top;    
    int size; 
};
struct Stack *createStack(int size)
{
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = size;
    sp->top = -1;
    sp->arr= (int *)malloc(sp->size * sizeof(int));
    return sp;
}
int isFull(struct Stack *sp)
{
    if (sp->top == sp->size - 1)
    { 
        return 1;
    }
    else
        return 0;
}
int isEmpty(struct Stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    else
        return 0;
}

void push(struct Stack *sp, int element)
{
    if (isFull(sp))
    {
        printf("Stack Overflow !!! \n");
    }
    else
    {
        sp->arr[++sp->top] = element; 
        printf("The element pushed to the stack is %d\n", element);
    }
}
int pop(struct Stack *sp)
{
    int elementpopped;
    if (isEmpty(sp))
    { 
        printf("Stack is empty!!!\n");
        printf("ERROR\n");
        return('\0');
    }
    else{
        elementpopped = sp->arr[sp->top];
        sp->top--;
        return elementpopped;
    }
        
}
void displayElements(struct Stack *sp)
{
    if (isEmpty(sp))
    {
        printf("Empty Stack!!!\n");
    }
    else
    {
        printf("Elements present in the stack are:\n");
        int tmp;
        tmp = sp->top;
        while (tmp != -1)
        {
            printf("%d \n", sp->arr[tmp]);
            --tmp;
        }
    }
}
int main()
{
    int choice, element, popped, size;
    printf("Enter the size of the stack : \n");
    scanf("%d", &size);
    struct Stack *sp = createStack(size); 
    do
    {
        printf("\t IMPLEMENTATIONS \n");
        printf("Press 1 to push an element in the stack\n");
        printf("Press 2 to pop an element from the stack\n"); 
        printf("Press 3 to display elements of the stack\n");
        printf("Press 4 to exit the stack\n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n \t Pushing element in stack \n");
            printf("Enter the element you want to push in the stack : \n");
            scanf("%d", &element);
            push(sp, element);
            break;
        case 2:
            printf("Pop the element from stack \n");
            popped = pop(sp);
            if (sp->top == -1 && popped == 0)
            {
                printf("Stack Underflow!!! \n");
            }
            else
                printf("The popped element is %d \n", popped);
            break;
        case 3:
            displayElements(sp);
            break;
        case 4:
            exit(0);
        default:
            printf("WRONG INPUT:( TRY AGAIN!! \n");
            break;
        }
        printf("Press ENTER if you wish to continue!!\n");
        getch();
    } while (1);
    return 0;
}