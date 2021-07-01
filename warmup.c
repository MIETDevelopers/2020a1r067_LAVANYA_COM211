#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *arr;
	int i, number ,query;
	printf("size of array: \n");
	scanf(" %d", &number); 
	arr = (int *)malloc(number*sizeof(int));
	for (i = 0; i < number; ++i)
	{
		printf("Enter the arrays:arr[%d]\n", i);
		scanf(" %d", (arr+i));
	}
	for (i = 0; i < number; ++i)
	{
		printf(" showing the arrays : arr[%d] = %d\n", i, *(arr+i));
	}
	arr = realloc(arr,(number* sizeof(int)+1));
	printf("enter the new array element : arr[%d]\n", number);
	scanf(" %d", (arr+number));
	for (i = 0; i < number+1; ++i)
	{
		printf(" showing the arrays : arr[%d] = %d\n", i, *(arr+i));
	}
   
    printf("Enter element to search:"); 
    scanf("%d",&query);
     
    for(i=0;i<number+1;++i)
        if(arr[i]==query)
            break;
     
    if(i<number+1)
        printf("Element found at index %d",i); 
    else
        printf("Element not found"); 
  
    return 0;
}