#include "pushswap.h"


void max_min(t_stack **stack)
{
    t_list *tmp;

    tmp = (*stack)->head;
    (*stack)->max = tmp;
    (*stack)->min = tmp;

    while(tmp)
    {
        if(tmp->data < (*stack)->min->data)
        {   
                (*stack)->min = tmp;
        }   
        if(tmp->data > (*stack)->max->data)
        {
            (*stack)->max = tmp;
        }
        tmp = tmp->next;
    }
}
int    ft_index_max(t_stack **stack)
{
    t_list *head;
    int count;
    int max;
    int pos;
     
    head = (*stack)->head;
    count = 1;
    max_min(stack);
    max = (*stack)->max->data;
    while (head)
    {
        if (head->data == max)
            pos = count;
        count++;
        head = head->next;
    }  
   return (pos);
}

void ft_get_index(t_stack **stack)
{
    t_list *head;
    int count;

    head = (*stack)->head;
    count = 0;
    while(head)
    {
        head->index = count;
        count++;
        head = head->next;
    }
}

void	five_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	// t_list	*tmp;

	i = 0;
	max_min(stack_a);
	ft_get_index(stack_a);
	while (i++ < 2)
	{
		while ((*stack_a)->min != (*stack_a)->head)
		{
			ft_get_index(stack_a);
			if ((*stack_a)->min->index <= (*stack_a)->size / 2)
				rotate(stack_a, 'a');
			else
				reverse_rotate_s(stack_a, 'a');
		}
		push_to_b(stack_a, stack_b);
		(*stack_a)->min = (*stack_a)->max;
		// tmp = (*stack_a)->head;
		// while (tmp)
		// {
		// 	max_min(stack_a);
		// 	tmp = (*stack_a)->head->next;
		// }
	}
	three_sort(stack_a);
	push_to_a(stack_b, stack_a);
	push_to_a(stack_b, stack_a);
}


void	three_sort(t_stack **stack_a)
{
	if ((*stack_a)->head->data > (*stack_a)->tail->data)
	{
		rotate(stack_a, 'a');
		three_sort(stack_a);
	}
	if (((*stack_a)->head->next->data > (*stack_a)->head->data)
		&& ((*stack_a)->head->next->data > (*stack_a)->tail->data))
	{
		reverse_rotate_s(stack_a, 'a');
		three_sort(stack_a);
	}
	if ((*stack_a)->head->data > (*stack_a)->head->next->data)
	{
		swap(stack_a, 'a');
		three_sort(stack_a);
	}
}