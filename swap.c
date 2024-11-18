#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first_list;
	t_list	*second_list;
	t_list	*third_list;

	first_list = *stack;
	second_list = first_list->next;
	if (!first_list || !second_list)
		return ;
	third_list = second_list->next;
	first_list->next = third_list;
	second_list->next = first_list;
	*stack = second_list;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}
