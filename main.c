#include "push_swap.h"

void	sort_stack(t_list **stack_a, t_list **stack_b, int *size)
{
	if (*size <= 5)
		s_sort(stack_a, stack_b, *size);
	else
		radix_sort(stack_a, stack_b, *size);
}

void	free_list(t_list **stack)
{
	t_list	*head;
	t_list	*next_node;

	head = *stack;
	while (head)
	{
		next_node = head->next;
		free(head);
		head = next_node;
	}
	free(stack);
}

int	main(int argc, char **argv)
{
	t_list		**stack_a;
	t_list		**stack_b;
	int			*numbers;
	int			size;

	if (argc < 2)
		return (0);
	numbers = create_numbers(argc, argv, &size);
	if (!numbers)
		return (ft_putendl_fd("Error", 2), 1);
	stack_a = malloc(sizeof(t_list *));
	if (!stack_a)
		return (free(numbers), 1);
	*stack_a = NULL;
	init_stack(stack_a, numbers, &size);
	free(numbers);
	stack_b = malloc(sizeof(t_list *));
	if (!stack_b)
		return (free_list(stack_a), 1);
	*stack_b = NULL;
	if (!check_sorted(stack_a))
		sort_stack(stack_a, stack_b, &size);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
