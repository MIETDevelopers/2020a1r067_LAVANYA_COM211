#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int printarr(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {

        printf(" array is[%d] is %d\n", i, *(arr + i));
    }
    return size;
}
int insertele(int *arr, int size, int position, int element)
{

    int i, newsize;

    arr = realloc(arr, ((size + 1) * sizeof(int)));
    for (i = size; i > position; i--)
        arr[i] = arr[i - 1];
    arr[position] = element;
    newsize = ++size;
    return newsize;
}
int delelement(int *arr, int size, int index)
{
    int i;

    for (i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}
int search(int *arr, int query, int size)
{

    int i, newsize;

    for (i = 0; i < newsize; ++i)
        if (arr[i] == query)
            break;

    if (i < newsize)
        printf("Element found at index %d", i);
    else
        printf("Element not found");
    return size;
}
void red()
{
    printf("\033[1;31m");
}
void blue()
{
    printf("\033[0;34m");
}
void green()
{
    printf("\033[0;32m");
}
void white()
{
    printf("\033[0;37m");
}

int main()
{
    int i;
    int size = 0;
    int *arr;
    int position, element, newsize, index, query, choice;

    do
    {
        system("cls");
        green();

        printf("Implimentation of list\nchoose any operation\n");
        red();
        printf("print array is must otherwise you r not able to use rest function\n");
        blue();
        printf("1. Print an array\n2. Insert elements\n3. Delete an element\n4. Search\n5. View array after operations\n6. Exit \n");
        white();
        choice = (int)getch();
        switch (choice)
        {
        case 49:
            printf("size of array: \n");
            scanf(" %d", &size);
            arr = (int *)malloc(size * sizeof(int));
            for (i = 0; i < size; ++i)
            {
                printf("Enter the arrays:arr[%d]\n", i);
                scanf(" %d", (arr + i));
            }
            size = printarr(arr, size);

            break;
        case 50:
            if (size == 0)
            {
                printf("you should have to enter elements into the array");
            }
            else
            {
                printf("enter the position where u want to insert");
                scanf("%d", &position);
                if (position > size + 1)
                    printf("not valid");
                else
                    printf("enter the element u want to insert");
                scanf("%d", &element);

                size = insertele(arr, size, position, element);
                printf(" After Insertion:- \n");
                for (i = 0; i < size; ++i)
                {
                    printf(" arr[%d] = %d\n", i, *(arr + i));
                }
            }
            break;

        case 51:
            if (size == 0)
            {
                printf("you should have to enter elements into the array");
            }
            else
            {
                printf("enter the index you want to delete");
                scanf("%d", &index);
                size = delelement(arr, size, index);

                printf(" After deletion: ");
                for (i = 0; i < size; ++i)
                {
                    printf(" showing the arrays : arr[%d] = %d\n", i, *(arr + i));
                }
            }

            break;
        case 52:

            if (size == 0)
            {
                printf("you should have to enter elements into the array");
            }
            else
            {
                printf("Enter element to search:");
                scanf("%d", &query);
                size = search(arr, query, size);
            }
            break;

        case 53:
            system("cls");

            if (size == 0)
                printf("array is empty");
            else
                size = printarr(arr, size);
            break;
        case 54:
            printf("press enter to exit...");
            getch();
            free(arr);
            exit(0);
            break;
        default:

            printf("Wrong choice");
            break;
        }
        printf("\nPress enter to continue");
        getch();
    } while (1);
}