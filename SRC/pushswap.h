#ifndef  PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_list
{
    int data;
    int lis_l;
    int index;
    bool sorted;
    bool mark;
    struct s_list *next;
    struct s_list *previous;
}          t_list;

typedef struct s_stack
{
    t_list *min;
    t_list *max;
    t_list *len;
    struct s_list *head;
    struct s_list *tail;
    int size;
}   t_stack;

// added functions quick sort---------------------------------
void    ft_pushswap(t_stack **stack_a, t_stack **stack_b, int *array);
int     mark_stack(t_stack **stack, int *array, int total);
int     mark_stack_count(t_list *head, int size);
void    ft_increment(t_list *head, int size);
int     push_to_stack_b(t_stack **stack_a, t_stack **stack_b, int *array, int piv);
void    ft_push_back(t_stack **stack_a, t_stack **stack_b);
void    flash_bools(t_stack **stack_a, t_stack **stack_b);
void    ft_swap(int *a, int *b);
void    quicksort(int *array, int low, int high);
t_stack *ft_get_lst(int ac , char **av, t_stack *stack);
void    ft_get_array(int ac, char **av, int *array);
int     check_args(int num, t_stack *stack);
void    ft_push_max(t_stack **stack_a, t_stack **stack_b);
int      ft_index_max(t_stack **stack);
void     three_sort(t_stack **stack);
void     five_sort(t_stack **stack_a, t_stack **stack_b);
void    ft_get_index(t_stack **stack);
void    pushswap(int ac, t_stack **stack_a, t_stack **stack_b);
int     ft_index_min(t_stack **stack);
int     check_sorting(t_stack **stack);
int     ft_atoi(const char *str);
t_list *ft_creatnewnode(int num);
void    ft_creatlst(t_stack **stack, t_list *lst);
void    swap(t_stack **stack, char s);
void    rotate(t_stack **stack, char s);
void    reverse_rotate(t_stack **stack_a, t_stack **stack_b);
void    reverse_rotate_s(t_stack **stack, char s);
void    push_to_b(t_stack **stack_a, t_stack **stack_b);
void    push_to_a(t_stack **stach_b, t_stack **stack_a);
int	    ft_lstsize(t_stack **stack);
void    max_min(t_stack **stack);
void    ft_free_all(t_stack **stack_a);
int     ft_check(int ac, char **av);
int     check_double(int nbr, t_stack **stack);
void    reverse_rotate_r(t_stack **stack_a, t_stack **stack_b);
#endif