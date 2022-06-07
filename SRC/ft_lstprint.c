#include "pushswap.h"

void    ft_lstprint(t_stack *stack)
{
    t_list *tmp;

    tmp = stack->head;
    while(tmp)
    {
        printf("%5d |", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void    ft_initprintf(t_stack *stack)
{
    t_list *tmp;

    tmp = stack->head;
    while(tmp)
    {
        printf("%5d |", tmp->lis_l);
        tmp = tmp->next;
    }
    printf("\n");
}

void ft_initsorted(t_stack *stack)
{
    t_list *tmp;

    tmp = stack->head;
    while(tmp){
        printf("%5d |", tmp->sorted);
        tmp = tmp->next;
    }
    printf("\n");
}

