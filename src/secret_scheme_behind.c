/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret_scheme_behind.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:15:48 by vharkush          #+#    #+#             */
/*   Updated: 2023/05/28 10:16:46 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_rrotate(int *stack, int n, char ab)
{
	int	tmp;
	int	i;

	i = n;
	tmp = stack[n - 1];
	while (--i)
		stack[i] = stack[i - 1];
	stack[0] = tmp;
	if (ab == 'a')
		write(1, "rra\n", 4);
}

void	ft_rotate(int *stack, int n, char cond)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack[0];
	while (++i < n)
	{
		stack[i - 1] = stack[i];
	}
	stack[n - 1] = tmp;
	if (cond == 'a')
		write(1, "ra\n", 3);
	if (cond == 'b')
		write(1, "rb\n", 3);
}

void	ft_swap1(int *stack, char cond)
{
	int	tmp;

	if (cond != 'b')
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
		write(1, "sa\n", 3);
	}
	if (cond != 'a')
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
		write(1, "sb\n", 3);
	}
}

void	ft_push_opp_to_cur(t_list_num *cur, t_list_num *cur_opp,
							t_list_num *one_bef_last)
{
	int			i;
	int			j;
	int			n;

	j = -1;
	i = cur->n - 1;
	n = i;
	while (++i <= (cur_opp->n + n))
	{
		if (cur_opp->stack == 'a')
			write(1, "pb\n", 3);
		else
			write(1, "pa\n", 3);
		ft_rrotate(cur->arr, cur->n_orig, 'c');
		cur->arr[0] = cur_opp->arr[++j];
	}
	cur->n = i;
	one_bef_last->next = NULL;
	free (cur_opp->arr);
	free (cur_opp);
}

t_list_num	*ft_last_opp(t_list_num *cur, t_list_num *a, t_list_num *b)
{
	t_list_num	*ret;

	if (cur->stack == 'a')
		ret = b;
	else
		ret = a;
	while (ret->next != NULL)
		ret = ret->next;
	return (ret);
}
