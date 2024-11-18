#include "push_swap.h"

void	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*from_first;
	t_list	*from_second;
	t_list	*to_first;

	if (!(*stack_from))
		return ;
	from_first = *stack_from;
	from_second = from_first->next;
	to_first = *stack_to;
	from_first->next = to_first;
	*stack_from = from_second;
	*stack_to = from_first;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}
