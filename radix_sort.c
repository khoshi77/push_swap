#include "push_swap.h"

int	get_maxbit(int size)
{
	int		max;
	int		max_bit;

	max = size - 1;
	max_bit = 0;
	while ((max >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

void	radix_sort(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*head;
	int		i;
	int		j;
	int		max_bit;

	i = 0;
	head = *stack_a;
	max_bit = get_maxbit(size);
	while (i < max_bit)
	{
		j = 0;
		while (j < size)
		{
			head = *stack_a;
			if (head->index & (1 << i))
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
