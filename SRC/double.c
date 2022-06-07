#include "pushswap.h"

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