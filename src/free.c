/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:04:35 by vharkush          #+#    #+#             */
/*   Updated: 2023/05/28 10:30:24 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_error_exit(char *msg, int len)
{
	write(1, msg, len);
	exit (1);
}

void	ft_free_exit(t_num_arr *num_arr, char *msg, int len)
{
	if (num_arr)
	{
		if (num_arr->num_arr)
			free(num_arr->num_arr);
		if (num_arr->tmp)
			free(num_arr->tmp);
		free(num_arr);
	}
	ft_error_exit(msg, len);
}

void	ft_free_if_next(t_list_num	*one_bef_last)
{
	while (one_bef_last->next->next != NULL)
		one_bef_last = one_bef_last->next;
	if (one_bef_last->next->arr)
		free(one_bef_last->next->arr);
	free(one_bef_last->next);
	one_bef_last->next = NULL;
}

void	ft_free_all_u_can_reee(t_list_num	*a, t_list_num	*b)
{
	t_list_num	*one_bef_last;

	one_bef_last = b;
	if (!one_bef_last)
		one_bef_last = a;
	if (one_bef_last->next != NULL)
		ft_free_if_next(one_bef_last);
	else
	{
		if (one_bef_last->arr)
			free(one_bef_last->arr);
		if (one_bef_last->stack != 'a')
			free(one_bef_last);
		else
			a = NULL;
		one_bef_last = NULL;
	}
	if (!a && !b)
		return ;
	ft_free_all_u_can_reee(a, b);
}
