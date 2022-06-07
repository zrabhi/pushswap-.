#include "pushswap.h"

int ft_check(int ac, char **av)
{
    int i;
    int j;

    i = 0;
    while(++i < ac)
    {
        j = 0;
        while(av[i][j])
        {
            if(!(av[i][j] >= 48 && av[i][j] <= 57))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int check_double(int nbr, t_stack **stack)
{
    t_list *head;

    head = (*stack)->head;
    while(head)
    {
        if(nbr == head->data)
            return (1);
        head = head->next;
    }
    return(0);
} 