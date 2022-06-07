#include "pushswap.h"

void    ft_swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

static int sort_call(int *array, int low, int high)
{
    int pivot;
    int i;

    pivot = array[high];
    i = (low -1);
    while(low < high)
    {
        if(array[low] < pivot)
        {
            i++;
            if(i != low)
                ft_swap(&array[i], &array[low]);
        }
        low++;
    }
    ft_swap(&array[i + 1], &array[high]);
    return(i + 1);
}

void quicksort(int *array, int low, int high)
{
    int part;

    if(low >= high)
        return ;
    part = sort_call(array, low, high); 
    quicksort(array,low, part - 1);
    quicksort(array, part + 1 ,high);
}
    