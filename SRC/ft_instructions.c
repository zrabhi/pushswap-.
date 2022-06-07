#include "pushswap.h"

void    swap(t_stack **stack, char s)
{
    t_list *tmp;

    if((!(*stack)->head) || (!(*stack)->head->next))
            return ;
    tmp = (*stack)->head;
    (*stack)->head = (*stack)->head->next;
    tmp->next = (*stack)->head->next;
    (*stack)->head->previous = (*stack)->tail;
	(*stack)->head->next = tmp;
	tmp->previous = (*stack)->head;
    printf("s%c\n", s);
}  

void    rotate(t_stack **stack, char s)
{
    t_list *tmp;

    if((!(*stack)->head)|| (!(*stack)->tail))
            return ;
    tmp = (*stack)->head;
    (*stack)->head = (*stack)->head->next;
    tmp->next = NULL;
    (*stack)->tail->next = tmp;
    (*stack)->tail = tmp;
    printf("r%c\n", s);
}

void    reverse_rotate_s(t_stack **stack, char s)
{
    t_list *tmp;

    if((*stack))
        {
            tmp = (*stack)->tail;
            (*stack)->tail = tmp->previous;
            (*stack)->tail->next = NULL;
            tmp->next = (*stack)->head;
            (*stack)->head = tmp;
            printf("rr%c\n", s);
        }
}

void swap_swap(t_stack **stack)
{
    swap(stack, 'a');
    swap(stack, 'b');
    printf("ss\n");
}

void     reverse_rotate(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a, 'a');
    rotate(stack_b, 'b');
    printf("rr\n");
}

void reverse_rotate_r(t_stack **stack_a, t_stack **stack_b)
{
    reverse_rotate_s(stack_a, 'a');
    reverse_rotate_s(stack_b, 'b');
    printf("rrr\n");
}
