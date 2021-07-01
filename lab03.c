#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
struct Stack
{
    char *arr; 
    int top;    
    int size; 
};
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
void push(struct Stack *sp, char ch)
{
    if (isFull(sp))
    {
       printf("Stack Overflow!!\n");
    }
    sp->arr[++sp->top] = ch;
}
int pop(struct Stack *sp)
{
    char elremoved;
    if (isEmpty(sp))
    {
        printf("Stack is empty!!!\n");
        printf("ERROR!!\n");
        return('\0');
    }
    else{
        elremoved = sp->arr[sp->top];
        sp->top--;
        return elremoved;
    }
    
}
int main()
{
    int expSize, i, ret;
    char exp[30];
    struct Stack sp;
    sp.top = -1;                    
    
    printf("Enter the expression : \n");
    gets(exp);                   
    expSize = strlen(exp);    
    sp.size = expSize;       
    sp.arr = (char *)malloc(sp.size * sizeof(char));
    for (i = 0; i < expSize; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(&sp, exp[i]);
        }
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if ((sp.arr[sp.top] == '(' && exp[i] == ')') || (sp.arr[sp.top] == '{' && exp[i] == '}') || (sp.arr[sp.top] == '[' && exp[i] == ']'))  //Thank you Aditya Kotwal for this part
            {
                ret = pop(&sp);
            }
            else
            {
                printf("This expression is NOT BALANCED!!! \n");
                return 0;
            }    
        }
    }
    if (isEmpty(&sp))
    {
        printf(" This expression is BALANCED!! \n");
    }
    else
    {
        printf("This expression is NOT BALANCED!! \n");
    }
    return 0;
}