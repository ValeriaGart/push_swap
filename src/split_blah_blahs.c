/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_blah_blahs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:10:06 by vharkush          #+#    #+#             */
/*   Updated: 2023/05/24 14:52:05 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_cur_change(t_list_num *cur, int mid)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (cur->stack == 'a')
	{
		while ((++i) < cur->n)
		{
			if (cur->arr[i] >= mid)
				cur->arr[++j] = cur->arr[i];
		}
	}
	if (cur->stack == 'b')
	{
		while ((++i) < cur->n)
		{
			if (cur->arr[i] <= mid)
				cur->arr[++j] = cur->arr[i];
		}
	}
	i = cur->n;
	cur->n = j + 1;
	while (++j < i)
		cur->arr[j] = 0;
}

void	write_a(t_list_num *cur, t_list_num *cur_opp, int mid)
{
	int	i;
	int	n;
	int	j;

	i = -1;
	n = 1;
	j = cur->n / 2;
	while (++i < cur->n)
	{
		if (cur->arr[i] < mid)
		{
			write(1, "pb\n", 3);
			cur_opp->arr[--j] = cur->arr[i];
		}
		else
		{
			n++;
			write(1, "ra\n", 3);
		}
	}
	while (--n && cur->ind != 0)
		write(1, "rra\n", 4);
}

void	write_b(t_list_num *cur, t_list_num *cur_opp, int mid)
{
	int	i;
	int	n;
	int	j;

	i = -1;
	n = 1;
	j = cur->n / 2;
	while (++i < cur->n)
	{
		if (cur->arr[i] > mid)
		{
			write(1, "pa\n", 3);
			cur_opp->arr[--j] = cur->arr[i];
		}
		else
		{
			n++;
			write(1, "rb\n", 3);
		}
	}
	while (--n && cur->ind != 0)
		write(1, "rrb\n", 4);
}

t_list_num	*ft_cur_opp(t_list_num *cur, t_list_num *cur_opp, int mid)
{
	int	j;

	j = cur->n / 2;
	cur_opp = malloc(sizeof(t_list_num));
	if (!cur_opp)
		exit (1);
	cur_opp->n = j;
	cur_opp->arr = malloc(sizeof(int) * (j));
	if (cur->stack == 'a')
		write_a(cur, cur_opp, mid);
	if (cur->stack == 'b')
		write_b(cur, cur_opp, mid);
	return (cur_opp);
}

void	ft_add_back(t_list_num ***ab, t_list_num *cur_opp)
{
	t_list_num	*head;

	head = **ab;
	if (!**ab)
	{
		**ab = cur_opp;
		(**ab)->ind = 0;
	}
	else
	{
		while ((**ab)->next)
			(**ab) = (**ab)->next;
		(**ab)->next = cur_opp;
		(**ab)->next->ind = (**ab)->ind + 1;
		(**ab)->next->next = NULL;
		**ab = head;
	}
}
