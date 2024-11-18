#include "push_swap.h"

int	*create_numbers(int argc, char **argv, int *size)
{
	char	**numbers_char;
	int		*numbers;
	int		i;

	if (argc == 2)
		numbers_char = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		numbers_char = malloc(sizeof(char *) * argc);
		if (!numbers_char)
			return (NULL);
		while (argv[i])
		{
			numbers_char[i - 1] = ft_strdup(argv[i]);
			if (!numbers_char[i - 1])
				return (ft_free(numbers_char, i - 1), NULL);
			i++;
		}
		numbers_char[i - 1] = NULL;
	}
	numbers = check_error(numbers_char, size);
	if (!numbers)
		ft_free(numbers_char, *size);
	return (numbers);
}

void	put_index(t_list **stack_a)
{
	t_list		*head;
	t_list		*min;
	static int	index;

	head = *stack_a;
	min = NULL;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && \
			(min == NULL || head->value < min->value))
				min = head;
			head = head->next;
		}
	}
	min->index = index;
	index++;
}

void	zahyo_comp(t_list **stack_a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		put_index(stack_a);
		i++;
	}
}

void	init_stack(t_list **stack_a, int *numbers, int *size)
{
	int		i;
	t_list	*new_list;

	i = 0;
	while (i < *size)
	{
		new_list = ft_lstnew(numbers[i]);
		if (!new_list)
		{
			free(numbers);
			free_list(stack_a);
			exit(1);
		}
		ft_lstadd_back(stack_a, new_list);
		i++;
	}
	zahyo_comp(stack_a, *size);
}

int	check_sorted(t_list **stack_a)
{
	t_list	*head;

	head = *stack_a;
	if (!head)
		return (1);
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}
