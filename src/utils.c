/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:06:01 by vharkush          #+#    #+#             */
/*   Updated: 2023/05/11 14:07:24 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_cpy_to_cur(int *from, int *to, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		to[i] = from[i];
	free(from);
}

int	ft_iff_sorted(int *num_arr, int n, char dir)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (dir == 'a')
		dir = '<';
	if (dir == 'b')
		dir = '>';
	while (++i < n - 1)
	{
		if (num_arr[i + 1] && num_arr[i + 1] > num_arr[i] && dir == '<')
			count++;
		if (num_arr[i + 1] && num_arr[i + 1] < num_arr[i] && dir == '>')
			count++;
	}
	if (count == n - 1)
		return (1);
	return (0);
}

int	ft_mid_ax(int *num_arr, int n, int stack)
{
	int	j;
	int	i;
	int	mid;
	int	a;
	int	b;

	i = -1;
	mid = num_arr[i + 1];
	while (++i < n)
	{
		j = -1;
		a = 0;
		b = 0;
		while (++j < n)
		{
			if (num_arr[j] > num_arr[i])
				b += 1;
			else if (num_arr[j] < num_arr[i])
				a += 1;
		}
		if ((a - b) == 0 || ((a - b) == -1 && (n % 2 == 0) && stack == 'b')
			|| ((a - b) == 1 && (n % 2 == 0) && stack == 'a'))
			mid = num_arr[i];
	}
	return (mid);
}

void	ft_increase_i_reset_j(int *i, int *j)
{
	(*i)++;
	*j = 0;
}

void	ft_write_the_rest(int i)
{
	while (--i)
		write(1, "pa\n", 3);
}
