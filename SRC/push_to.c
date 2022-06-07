#include "pushswap.h"


void    push_to_b(t_stack **stack_a, t_stack **stack_b)
{
    t_list *tmp;
    t_list *tmp2;

    if(!stack_a)
        return ;
    tmp2 = (*stack_a)->head;  
    tmp = (*stack_a)->head->next;
    ft_creatlst(stack_b, tmp2);
    (*stack_a)->head = tmp;
     if(tmp)
             (*stack_a)->head->previous = (*stack_a)->tail; 
    printf("pb\n");
}

void    push_to_a(t_stack **stack_b, t_stack **stack_a)
{
    t_list *tmp;
    t_list *tmp2;

    if(!stack_b || !stack_a)
        return ;
        tmp2 = (*stack_b)->head;  
        tmp = (*stack_b)->head->next;
        ft_creatlst(stack_a, tmp2);
        (*stack_b)->head = tmp;
        if(tmp)
             (*stack_b)->head->previous = (*stack_b)->tail;
        printf("pa\n");
}