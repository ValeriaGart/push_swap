/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:13:54 by vharkush          #+#    #+#             */
/*   Updated: 2023/05/13 11:15:24 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	main(int ac, char **av)
{
	t_num_arr	num_arr;

	if (ac == 1)
		return (1);
	num_arr.stack = malloc(sizeof(t_stack));
	if (!num_arr.stack)
		ft_error_exit("Malloc failed:-(\n", 17);
	ft_check_str(ac, av, &num_arr);
	ft_sort_all(num_arr.num_arr, num_arr.n);
	for (int i = 0; i < num_arr.n; i++)
		printf("%d\t", num_arr.num_arr[i]);
	free(num_arr.stack);
	free(num_arr.num_arr);
	return (0);
}
/*for (int i = 0; i < num_arr.n; i++)
		printf("%d\t", num_arr.num_arr[i]);*/