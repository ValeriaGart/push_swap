/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:04:00 by vharkush          #+#    #+#             */
/*   Updated: 2023/05/28 10:51:10 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	ft_check_doubles(int *arr, int n)
{
	int	tmp;
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (i < n)
	{
		tmp = arr[i];
		j = 0;
		while (j < n)
		{
			if (tmp == arr[j])
				res++;
			j++;
		}
		i++;
	}
	if (res == n)
		return (0);
	return (res);
}

void	ft_leave_it_here(t_list_num	*to, t_list_num	*from,
						t_list_num	*last_opp)
{
	int	i;

	i = 0;
	last_opp->n_orig = last_opp->n;
	while (++i <= from->n)
		ft_rrotate(to->arr, to->n + i, 'c');
	i = -1;
	to->n += from->n;
	while (from->n != 0)
	{
		to->arr[from->n - 1] = from->arr[from->n - 1];
		from->n -= 1;
	}
	free(from->arr);
	free(from);
	to->next = NULL;
}

int	ft_special_ifs(t_list_num *cur, t_list_num *a, t_list_num *b, int n)
{
	if (!n)
	{
		if (cur->n == 2)
		{
			ft_swap1(cur->arr, cur->stack);
			return (0);
		}
		if (cur->n == 3 && cur->ind == 0)
		{
			ft_short_sort(cur);
			return (0);
		}
	}
	if (n)
	{
		if (!(cur->stack == 'a' && cur->ind == 0))
			ft_push_back(cur, a, b);
	}
	return (1);
}

void	ft_set_to_null(t_list_num *arr)
{
	arr->ind = 0;
	arr->n = 0;
	arr->n_orig = 0;
	arr->rots = 0;
	arr->stack = 0;
	arr->next = NULL;
	arr->arr = NULL;
}

void	ft_if_all_args_empty(int ac, char **av, t_num_arr *num_arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++j < ac)
		if (av[j][0] == '\0')
			i++;
	if (i == ac - 1)
		ft_free_exit(num_arr, "give some nums heyo\n", 20);
}
