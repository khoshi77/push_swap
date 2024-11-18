#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*first_list;
	t_list	*last_list;
	t_list	*prelast_list;

	first_list = *stack;
	if (!first_list || !first_list->next)
		return ;
	last_list = ft_lstlast(*stack);
	prelast_list = ft_lstprelast(*stack);
	last_list->next = first_list;
	prelast_list->next = NULL;
	*stack = last_list;
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
