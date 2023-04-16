#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int	*a;
	int *b;
	int point_a;
	int point_b;
    int mid;
	int max;
	int min;
	int	rem_a;
	int	rem_b;
}		t_stack;


typedef struct s_num_arr
{
    char    *tmp;
    t_stack *stack;
	int	    *num_arr;
    int     n;
	int	    ac;
	int	    i;
    int     a;
    int     b;
}		t_num_arr;

int     ft_if_sorted(int *num_arr, int n, char dir);
void    ft_recursive_sort(t_stack *stack, t_num_arr *num_arr);
void    ft_free_exit(t_num_arr *num_arr, char *msg, int len);
void    ft_rrotate(t_stack *stack, int n, int n1, char cond);
void    ft_rotate(t_stack *stack, int n, int n1, char cond);
void    ft_check_str(int ac, char **av, t_num_arr *num_arr);
void    ft_sort_all(t_num_arr *num_arr, t_stack *stack);
void    ft_increase_i_reset_j(int *i, int *j);
void    ft_swap1(t_stack *stack, char cond);
void    ft_error_exit(char *msg, int len);
void    ft_write_the_rest(int i);

#endif