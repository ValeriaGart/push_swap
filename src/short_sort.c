/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:43:36 by vharkush          #+#    #+#             */
/*   Updated: 2023/05/21 19:59:22 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_short_sort_b(t_list_num *cur)
{
	while (!ft_iff_sorted(cur->arr, cur->n, cur->stack))
	{
		if ((cur->arr[0] > cur->arr[2] && cur->arr[0] < cur->arr[1])
			|| (cur->arr[1] > cur->arr[0] && cur->arr[1] < cur->arr[2]))
			ft_swap1(cur->arr, 'b');
		else if (cur->arr[2] > cur->arr[0] && cur->arr[2] < cur->arr[1])
			ft_rotate(cur->arr, cur->n, cur->stack);
		else if ((cur->arr[0] > cur->arr[1] && cur->arr[0] < cur->arr[2])
			|| (cur->arr[2] > cur->arr[1] && cur->arr[2] < cur->arr[0]))
		{
			ft_rrotate(cur->arr, cur->n, 'c');
			write(1, "rrb\n", 4);
		}
	}
}

void	ft_short_sort(t_list_num *cur)
{
	if (cur->n == 2 && !ft_iff_sorted(cur->arr, cur->n, cur->stack))
		ft_swap1(cur->arr, cur->stack);
	else if (cur->stack == 'a')
	{
		while (!ft_iff_sorted(cur->arr, cur->n, cur->stack))
		{
			if ((cur->arr[0] > cur->arr[1] && cur->arr[0] < cur->arr[2])
				|| (cur->arr[2] > cur->arr[0] && cur->arr[2] < cur->arr[1]))
				ft_swap1(cur->arr, 'a');
			else if ((cur->arr[2] > cur->arr[1] && cur->arr[2] < cur->arr[0])
				|| (cur->arr[1] > cur->arr[2] && cur->arr[1] < cur->arr[0]))
				ft_rotate(cur->arr, cur->n, cur->stack);
			else if (cur->arr[0] > cur->arr[2] && cur->arr[0] < cur->arr[1])
			{
				ft_rrotate(cur->arr, cur->n, 'c');
				write(1, "rra\n", 4);
			}
		}
	}
	else if (cur->stack == 'b')
		ft_short_sort_b(cur);
}
