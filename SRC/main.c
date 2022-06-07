#include "pushswap.h"

void    ft_init(t_stack **stack_a, t_stack **stack_b)
{
    (*stack_a)->head = NULL;
    (*stack_b)->head = NULL;
}

int check_sorting(t_stack **stack)
{
    int i;
    t_list *curr;
    t_list *next;

    i = 1;
    curr = (*stack)->head;
    next = (*stack)->head->next;
    while(i != (*stack)->size)
    {
        if(curr->data > next->data)
            return(0);
        i++;
        curr = curr->next;
        next = next->next;
    }
    return(1);
}


int    ft_index_min(t_stack **stack)
{
    t_list *head;
    int count;
    int min;
    int pos;
     
    head = (*stack)->head;
    count = 1;
    max_min(stack);
    min = (*stack)->min->data;
    while(head)
    {
        if(head->data == min)
                 pos = count;
        count++;
        head = head->next;
    }  
   return(pos);
}

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int *array;

    stack_a = malloc(sizeof(t_stack));
    if (!stack_a)
        return 0;
    stack_b = malloc(sizeof(t_stack));
    if (!stack_b)
        return (0);
    array = malloc(sizeof(int)* (ac - 1));
    if(!array)
        return(0);
    ft_init(&stack_a, &stack_b);
    stack_a = ft_get_lst(ac, av, stack_a);
    if (stack_a)
    {
        ft_get_array(ac, av, array);
        ft_pushswap(&stack_a, &stack_b, array);
        ft_lstprint(stack_a);
        ft_free_all(&stack_a);
        ft_free_all(&stack_b);
    }
} 

