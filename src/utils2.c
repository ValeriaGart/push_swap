/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:04:00 by vharkush          #+#    #+#             */
/*   Updated: 2023/05/24 15:04:09 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

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

int	ft_special_ifs(t_list_num *cur)
{
	if (cur->n == 2)
	{
		ft_swap1(cur->arr, cur->stack);
		return (1);
	}
	if (cur->n == 3 && cur->ind == 0)
	{
		ft_short_sort(cur);
		return (1);
	}
	return (0);
}
