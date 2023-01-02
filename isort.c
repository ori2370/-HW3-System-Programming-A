#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

int shift_element(int *arr, int i)
{

    // arr = (int *)realloc(arr, sizeof(int)*1);
    for (int j = i; 0 < j; j--)
    {
        int tmp = *(arr + j + 1);
        *(arr + j + 1) = *(arr + j);
        *(arr + j) = tmp;
    }
    return 0;
}

int insertion_sort(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int j = i;
        while (j > 0 && *(arr + j - 1) > *(arr + j))
        {
            shift_element(arr + j - 2, 1);
            j = j - 1;
        }
    }
    return 0;
}

int main()
{
  
    int arr[SIZE];
    int num;

    for (int i = 0; i < 50; i++)
    {
        scanf("%d", &num);
        arr[i] = num;
    }
    insertion_sort(arr, 50);
    for (int i = 0; i < 50; i++)
    {
        if (i == 0)
        {
            printf("%d", arr[i]);
        }
        else
        {
            printf(",%d", arr[i]);
        }
    }
    printf("\n");
    return 0;
}