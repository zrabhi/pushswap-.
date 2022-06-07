#include "pushswap.h"

int	ft_lstsize(t_stack **stack)
{
	t_list *head;
	size_t	i;

	head = (*stack)->head;
	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}