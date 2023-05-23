/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:20:43 by vharkush          #+#    #+#             */
/*   Updated: 2023/05/23 20:39:14 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_split_half(t_list_num **a, t_list_num **b, t_list_num *cur)
{
	int			mid;
	t_list_num	*cur_opp;

	cur_opp = NULL;
	mid = ft_mid_ax(cur->arr, cur->n, cur->stack);
	cur_opp = ft_cur_opp(cur, cur_opp, mid);
	if (cur->stack == 'a')
	{
		ft_add_back(&b, cur_opp);
		cur_opp->stack = 'b';
		cur_opp->n_orig = cur_opp->n;
	}
	else
	{
		ft_add_back(&a, cur_opp);
		cur_opp->stack = 'a';
		cur_opp->n_orig = cur_opp->n;
	}
	ft_cur_change(cur, mid);
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
	//if (to->n_orig < to->n)
	//	to->n = to->n_orig;
	while (from->n != 0)
	{
		to->arr[from->n - 1] = from->arr[from->n - 1];
		from->n -= 1;
	}
	free(from->arr);
	free(from);
	to->next = NULL;
}

void	ft_push_back(t_list_num *cur, t_list_num *a, t_list_num *b)
{
	t_list_num	*last_opp;
	t_list_num	*one_bef_last;

	if (cur->stack == 'a')
		one_bef_last = a;
	else
		one_bef_last = b;
	last_opp = ft_last_opp(cur, a, b);
	if (one_bef_last->next != NULL)
		while (one_bef_last->next->next != NULL)
			one_bef_last = one_bef_last->next;
	if (!ft_iff_sorted(one_bef_last->arr, one_bef_last->n, cur->stack)
		|| cur->ind == 0 || cur->ind != 1)
		ft_push_opp_to_cur(last_opp, cur, one_bef_last);
	else
		ft_leave_it_here(one_bef_last, cur, last_opp);
}

void	ft_recurs_solve(t_list_num *cur, t_list_num *a, t_list_num *b)
{
	t_list_num	*last_opp;

	while (!ft_iff_sorted(cur->arr, cur->n, cur->stack))
	{
		if (cur->n == 2)
		{
			ft_swap1(cur->arr, cur->stack);
			break ;
		}
		if (cur->n == 3 && cur->ind == 0)
		{
			ft_short_sort(cur);
			break ;
		}
		if (cur->stack == 'b' && a->next)
		{
			if (!a->next->next && cur->ind < 1)
				ft_recurs_solve(a->next, a, b);
		}
		ft_split_half(&a, &b, cur);
	}
	while (cur->n != cur->n_orig)
	{
		last_opp = ft_last_opp(cur, a, b);
		ft_recurs_solve(last_opp, a, b);
	}
	if (!(cur->stack == 'a' && cur->ind == 0))
		ft_push_back(cur, a, b);
}

void	ft_store_first_node(int *arr, t_list_num *a, int n)
{
	a->n = n;
	a->n_orig = n;
	a->arr = arr;
	a->stack = 'a';
	a->ind = 0;
	a->next = NULL;
}

void	ft_sort_all(int *arr, int n)
{
	t_list_num	a;
	t_list_num	*b;

	b = NULL;
	ft_store_first_node(arr, &a, n);
	ft_recurs_solve(&a, &a, b);
}
