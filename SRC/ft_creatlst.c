#include "pushswap.h"
#include <unistd.h>


void    ft_creatlst(t_stack **stack, t_list *lst)
{
    t_list *tmp;

    if ((*stack))
    {
        if (!(*stack)->head)
        {
            (*stack)->head = lst;
            (*stack)->tail = lst;
            (*stack)->head->next = NULL;
            (*stack)->head->previous = (*stack)->tail;
        }
        else
        {
            tmp = (*stack)->head;
            (*stack)->head = lst;
            (*stack)->head->previous = (*stack)->tail;
            lst->next = tmp;
            tmp->previous = (*stack)->head;
            (*stack)->tail->next = NULL;
        } 
    }
}