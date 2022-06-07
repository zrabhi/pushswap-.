#include "pushswap.h"

void    ft_pushswap(t_stack **stack_a, t_stack **stack_b, int *array)
{
    int total;
    int count;
    int piv;
    int size;

    count = 0;
    size = ft_lstsize(stack_a);
    total = ft_lstsize(stack_a);
    if (total == 3)
        three_sort(stack_a);
    else if(total == 5)
        five_sort(stack_a, stack_b);
    ft_get_index(stack_a);
    flash_bools(stack_a, stack_b);
    if(total >= 6)
    {
        while(size-- != 0)
        {
            piv = mark_stack(stack_a, array + count , total);
            count += push_to_stack_b(stack_a, stack_b, array + count, piv / 2);
            flash_bools(stack_a, stack_b);
        }
       ft_push_max(stack_a, stack_b);
    }
}

int mark_stack(t_stack **stack, int *array, int total)
{
    int i;
    int piv;
    t_list *tmp;

    if (total >= 499)
        piv = ft_lstsize(stack) / 5;
    else 
        piv = ft_lstsize(stack) / 3;
    tmp = (*stack)->head;
    i = 0;
    while(i++ < ft_lstsize(stack))
    {
        if(tmp->data <= array[piv])
            tmp->mark = true;
        tmp = tmp->next;
    }
    return(piv);
}

int mark_stack_count(t_list *head, int size)
{
    t_list *tmp;
    int i;
    int count;

    i = -1;
    count = 0;
    tmp = head;
    while(++i < size)
    {
        if(tmp->mark == true)
            count++;
        tmp = tmp->next;
    }
    return(count);
}

void  ft_increment(t_list *head, int size)
{
    int i;

    i = 0;
    if (head)
    {
        while (i < size)
        {
            head = head->next;
            i++;
        }
    }
}

int push_to_stack_b(t_stack **stack_a, t_stack **stack_b, int *array, int piv)
{
    int count;
    int i;

    count = mark_stack_count((*stack_a)->head, ft_lstsize(stack_a));
    i = 0;
    while(i != count)
    {
        ft_increment((*stack_a)->head, ft_lstsize(stack_a));
        if((*stack_a)->head->mark == true)
        {
            if((*stack_a)->head->data <= array[piv])
            {
                push_to_b(stack_a, stack_b);
                rotate(stack_b, 'b');
            }
            else
                push_to_b(stack_a, stack_b);
            i++;
        }
        else
            rotate(stack_a, 'a');
    }
    return(count);
} 

void    ft_push_max(t_stack **stack_a, t_stack **stack_b)
{
    int pos;
    int middle;
    int size;

    size = ft_lstsize(stack_b);
    while(size)
    {
        middle = ft_lstsize(stack_b) / 2;
        pos = ft_index_max(stack_b);
        if (pos == 1)
        {
            push_to_a(stack_b, stack_a);
            size--;
        }
        else if (pos-- <= middle)
            rotate(stack_b, 'b');
        else
            reverse_rotate_s(stack_b, 'b');    
    }
}

void    flash_bools(t_stack **stack_a, t_stack **stack_b)
{
    int i;
    t_list *tmp;

    i = 0;
    tmp = (*stack_a)->head;
    while(i++ < ft_lstsize(stack_a))
    {
        tmp->mark = false;
        tmp = tmp->next;
    }
    i = 0;
    tmp = (*stack_b)->head;
    while(i++ < ft_lstsize(stack_b))
    {
        tmp->mark = false;
        tmp = tmp->next;
    }

}