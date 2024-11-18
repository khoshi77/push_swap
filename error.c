#include "push_swap.h"

size_t	ft_strstrlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_number(char *number_char)
{
	int	i;

	i = 0;
	if (number_char[0] == '-')
		i++;
	while (number_char[i])
	{
		if (!ft_isdigit(number_char[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_samenum(int *numbers, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (numbers[i] == numbers[j])
			return (0);
		j++;
	}
	return (1);
}

int	*check_error(char **numbers_char, int *size)
{
	int		i;
	int		*numbers;
	long	long_check;

	i = 0;
	*size = ft_strstrlen(numbers_char);
	numbers = malloc(sizeof(int) * (*size));
	if (!numbers)
		return (NULL);
	while (numbers_char[i])
	{
		numbers[i] = ft_atoi(numbers_char[i]);
		long_check = ft_atoi(numbers_char[i]);
		if (!check_number(numbers_char[i]))
			return (free (numbers), NULL);
		if (long_check < -2147483648 || long_check > 2147483647)
			return (free (numbers), NULL);
		if (!check_samenum(numbers, i))
			return (free (numbers), NULL);
		i++;
	}
	ft_free(numbers_char, *size);
	return (numbers);
}
