/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:13:54 by vharkush          #+#    #+#             */
/*   Updated: 2023/05/28 10:11:31 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

t_num_arr	*ft_init_numarr(void)
{
	t_num_arr	*num_arr;

	num_arr = malloc(sizeof(t_num_arr));
	if (!num_arr)
		ft_error_exit("Malloc failed:-(\n", 17);
	num_arr->tmp = NULL;
	num_arr->num_arr = NULL;
	return (num_arr);
}

int	main(int ac, char **av)
{
	t_num_arr	*num_arr;

	if (ac == 1)
		return (0);
	num_arr = ft_init_numarr();
	ft_check_str(ac, av, num_arr);
	if (num_arr->n != 0)
		ft_sort_all(num_arr, num_arr->num_arr, num_arr->n);
	else
		write(1, "no nums bruv:(\n", 15);
	free(num_arr->num_arr);
	free(num_arr);
	return (0);
}
