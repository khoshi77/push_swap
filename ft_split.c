#include "push_swap.h"

int	check_same(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && check_same(s[i], c))
			i++;
		if (s[i])
			count++;
		while (s[i] && !check_same(s[i], c))
			i++;
	}
	return (count);
}

char	*ft_put_split(char const *s, char c)
{
	int		i;
	int		len;
	char	*a;

	len = 0;
	while (s[len] && !check_same(s[len], c))
		len++;
	i = 0;
	a = malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	while (i < len)
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

void	ft_free(char **string, int i)
{
	i -= 1;
	while (i >= 0)
	{
		free(string[i]);
		i--;
	}
	free(string);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**string;

	i = 0;
	string = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!string)
		exit(1);
	while (*s)
	{
		while (*s && check_same(*s, c))
			s++;
		if (*s)
		{
			string[i] = ft_put_split(s, c);
			if (!string[i])
			{
				ft_free(string, i);
				exit(1);
			}
			i++;
		}
		while (*s && !check_same(*s, c))
			s++;
	}
	return (string[i] = NULL, string);
}
