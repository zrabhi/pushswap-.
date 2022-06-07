#include "pushswap.h"

t_list *ft_creatnewnode(int num)
{
    t_list *lst;

    lst = malloc(sizeof(t_list));
    if (!lst)
        return (NULL);
    lst->data = num;
    lst->next = NULL;
    lst->previous = NULL;
    return (lst);
}