#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	ans;
	long	check;

	i = 0;
	sign = 1;
	ans = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' '))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i++] == '-')
			sign = -1;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		check = ans;
		ans = ans * 10 + sign * (nptr[i++] - '0');
		if (ans > check && sign < 0)
			return ((int)LONG_MIN);
		if (ans < check && sign > 0)
			return ((int)LONG_MAX);
	}
	return (ans);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*p;
	int		i;

	len = ft_strlen(s);
	p = malloc(sizeof (char) * (len + 1));
	if (p == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (i < len)
		{
			p[i] = s[i];
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
