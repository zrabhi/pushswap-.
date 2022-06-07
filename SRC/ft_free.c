#include "pushswap.h"

void    ft_free_all(t_stack **stack)
{
    t_list *tmp;
    if(stack && *stack)
    {
        if((*stack)->head)
        {
            tmp = (*stack)->head;
            while(tmp)
            {
                (*stack)->head =(*stack)->head->next;
                free(tmp);
                tmp = (*stack)->head;
            }
            (*stack)->head = NULL;
            free((*stack)->head);
        }
        free(*stack);
    }
}

int  check_args(int num, t_stack *stack)
{
    t_list *head;

    head = stack->head;
    while(head)
    {
        if(head->data == num)
            return(1);
        head = head->next;
    }
    return(0);
}

void ft_get_array(int ac, char **av, int *array)
{
    int count;
    int i;
    int j;

    i = 1;
    j = 0;
    count = ac;
    while(av[i] && i != count)
    {
        array[j] = ft_atoi(av[i]);
        i++;
        j++;
    }
    quicksort(array, 0, i - 1);
}

t_stack    *ft_get_lst(int ac , char **av, t_stack *stack)
{
    int count;
    int num;
    t_list *lst;

    count = ac - 1;
    while(count != 0)
    {
        num = ft_atoi(av[count]);
        if(num < INT_MIN || num > INT_MAX)
        {
            printf("\nERROR\n");
            return(ft_free_all(&stack), NULL);
        }
        else if(check_args(num , (stack)))
        {
            printf("here");
            printf("\nERROR\n");
           return(ft_free_all(&stack), NULL);
        }
        lst = ft_creatnewnode(num);
        ft_creatlst(&stack, lst);
        count--;
    }
    return (stack);
}
