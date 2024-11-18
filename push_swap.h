#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int					value;
	int					index;
	struct s_list		*next;
}			t_list;

// main.c
void	sort_stack(t_list **stack_a, t_list **stack_b, int *size);
void	free_list(t_list **stack);
int		main(int argc, char **argv);

// swap.c
void	swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

// push.c
void	push(t_list **stack_from, t_list **stack_to);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

// rotate.c
void	rotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

// reverse_rotate.c
void	reverse_rotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

// list.c
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstprelast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

// error.c
size_t	ft_strstrlen(char **s);
int		check_number(char *number_char);
int		check_samenum(int *numbers, int i);
int		*check_error(char **numbers_char, int *size);

// stack.c
int		*create_numbers(int argc, char **argv, int *size);
void	put_index(t_list **stack_a);
void	zahyo_comp(t_list **stack_a, int size);
void	init_stack(t_list **stack_a, int *numbers, int *size);
int		check_sorted(t_list **stack_a);

// s_sort.c
void	s_sort(t_list **stack_a, t_list **stack_b, int size);
int		search_minindex(t_list **stack, int except_index);
void	sort_3(t_list **stack);
void	sort_4(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);

// radix_sort.c
int		get_maxbit(int size);
void	radix_sort(t_list **stack_a, t_list **stack_b, int size);

// libft_ps.c
int		ft_isdigit(int c);
void	ft_putendl_fd(char *s, int fd);
long	ft_atoi(const char *nptr);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);

// ft_split.c
int		check_same(char s, char c);
int		ft_count(char const *s, char c);
char	*ft_put_split(char const *s, char c);
void	ft_free(char **string, int i);
char	**ft_split(char const *s, char c);

// s_sort_case.c
void	sort_3_case3(t_list **stack, t_list *second_list, int min_index);
void	sort_5_comand(t_list **stack_a, t_list **stack_b);

#endif