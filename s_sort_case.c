#include "push_swap.h"

void	sort_3_case3(t_list **stack, t_list *second_list, int min_index)
{
	if (second_list->index == min_index)
		ra(stack);
	else
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_5_comand(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
