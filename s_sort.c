#include "push_swap.h"

int	search_minindex(t_list **stack, int except_index)
{
	t_list	*head;
	int		min_index;

	head = *stack;
	min_index = INT_MAX;
	while (head)
	{
		if (head->index < min_index && head->index != except_index)
			min_index = head->index;
		head = head->next;
	}
	return (min_index);
}

void	sort_3(t_list **stack)
{
	t_list	*first_list;
	int		min_index;
	int		minnext_index;

	if (check_sorted(stack))
		return ;
	first_list = *stack;
	min_index = search_minindex(stack, -1);
	minnext_index = search_minindex(stack, min_index);
	if (first_list->index == min_index)
	{
		ra(stack);
		sa(stack);
		rra(stack);
	}
	else if (first_list->index == minnext_index)
	{
		if (first_list->next->index == min_index)
			sa(stack);
		else
			rra(stack);
	}
	else if (first_list->index != min_index && \
	first_list->index != minnext_index)
		sort_3_case3(stack, first_list->next, min_index);
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_list;
	t_list	*third_list;
	int		min_index;

	if (check_sorted(stack_a))
		return ;
	first_list = *stack_a;
	third_list = first_list->next->next;
	min_index = search_minindex(stack_a, -1);
	if (first_list->next->index == min_index)
		sa(stack_a);
	else if (third_list->index == min_index)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (third_list->next->index == min_index)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	t_list	*second_list;
	t_list	*forth_list;
	int		min_index;

	if (check_sorted(stack_a))
		return ;
	second_list = (*stack_a)->next;
	forth_list = second_list->next->next;
	min_index = search_minindex(stack_a, -1);
	if (second_list->index == min_index)
		sa(stack_a);
	else if (second_list->next->index == min_index)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (forth_list->index == min_index)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (forth_list->next->index == min_index)
		rra(stack_a);
	sort_5_comand(stack_a, stack_b);
}

void	s_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
