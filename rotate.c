#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*first_list;
	t_list	*second_list;
	t_list	*last_list;

	first_list = *stack;
	if (!first_list)
		return ;
	second_list = first_list->next;
	if (!second_list)
		return ;
	last_list = ft_lstlast(*stack);
	last_list->next = first_list;
	first_list->next = NULL;
	*stack = second_list;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}
