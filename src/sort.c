/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:20:43 by vharkush          #+#    #+#             */
/*   Updated: 2023/05/27 10:03:06 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	ft_split_half(t_list_num **a, t_list_num **b, t_list_num *cur)
{
	int			mid;
	t_list_num	*cur_opp;

	cur_opp = NULL;
	mid = ft_mid_ax(cur->arr, cur->n, cur->stack);
	cur_opp = NULL;//ft_cur_opp(cur, cur_opp, mid);
	if (cur_opp == NULL)
		return (0);
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
	return (1);
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

int	ft_recurs_solve(t_list_num *cur, t_list_num *a, t_list_num *b, int 	ret)
{
	t_list_num	*last_opp;

	while (!ft_iff_sorted(cur->arr, cur->n, cur->stack))
	{
		if (ft_special_ifs(cur))
			break ;
		ret = ft_split_half(&a, &b, cur);
		if (!ret)
			return (ret);
		if (cur->stack == 'b' && a->next)
		{
			if (!a->next->next)
				ft_recurs_solve(a->next, a, b, ret);
			if (!ret)
				return (ret);
		}
	}
	while (cur->n != cur->n_orig)
	{
		last_opp = ft_last_opp(cur, a, b);
		ft_recurs_solve(last_opp, a, b, ret);
		if (!ret)
			return (ret);
	}
	if (!(cur->stack == 'a' && cur->ind == 0))
		ft_push_back(cur, a, b);
	return (1);
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
	int			res;

	b = NULL;
	ft_store_first_node(arr, &a, n);
	res = ft_recurs_solve(&a, &a, b, 0);
	if (!res)
		exit (1);
}
