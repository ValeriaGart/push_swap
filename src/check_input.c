/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:04:10 by vharkush          #+#    #+#             */
/*   Updated: 2023/05/25 16:39:41 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	my_long;

	i = 0;
	my_long = 0;
	sign = 0;
	if (!str)
		return (0);
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		my_long = my_long * 10 + str[i] - '0';
		i++;
	}
	if (sign)
		my_long *= -1;
	return (my_long);
}

void	ft_if_num(int *i, int *j, char **av, t_num_arr *num_arr)
{
	int	ind1;
	int	num_len;
	long	tmp;

	ind1 = *j;
	num_len = 1;
	if (av[*i][*j] == ' ')
	{
		while (av[*i][*j] && av[*i][*j] == ' ')
			*j += 1;
		return ;
	}
	while (av[*i][*j] && ft_strchr("+-0123456789", av[*i][(*j)++]))
		num_len++;
	num_arr->tmp = malloc(num_len * sizeof(char));
	if (!num_arr->tmp)
		ft_free_exit(num_arr, "Malloc failed\n", 14);
	ft_strlcpy(num_arr->tmp, (char *)(av[*i] + ind1), num_len);
	tmp = ft_atol(num_arr->tmp);
	if (tmp > 2147483648 || tmp < -2147483649)
		ft_free_exit(num_arr, "Not int range\n", 15);
	num_arr->num_arr[num_arr->i] = (int)tmp;
	num_arr->i += 1;
	free(num_arr->tmp);
	num_arr->tmp = NULL;
}

int	ft_check_errors(char **av, int *i, int *j, t_num_arr *num_arr)
{
	int	n;

	n = 0;
	while (av[*i][*j] == ' ')
		(*j)++;
	if (ft_strchr("+-", av[*i][*j]))
	{
		if (av[*i][*j - 1] && !ft_strchr(" ", av[*i][*j - 1]))
			ft_free_exit(num_arr, "Wrong digits or not digits", 26);
		if (!av[*i][*j + 1] || !ft_strchr("0123456789", av[*i][*j + 1]))
			ft_free_exit(num_arr, "Wrong digits or not digits", 26);
		(*j)++;
	}
	if (ft_strchr("0123456789", av[*i][*j]))
		n++;
	while (av[*i][*j] != 0 && ft_strchr("0123456789", av[*i][*j]))
		(*j)++;
	if (!(ft_strchr("0123456789+- ", av[*i][*j])) && av[*i][*j])
		ft_free_exit(num_arr, "Wrong digits or not digits", 26);
	return (n);
}

int	ft_count_nums(char **av, int ac, t_num_arr *num_arr)
{
	int	i;
	int	j;
	int	n;

	i = 1;
	j = 0;
	n = 0;
	while (i < ac)
	{
		if (!av[i][j])
			ft_increase_i_reset_j(&i, &j);
		else
			n += ft_check_errors(av, &i, &j, num_arr);
	}
	return (n);
}

void	ft_check_str(int ac, char **av, t_num_arr *num_arr)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	num_arr->ac = ac;
	num_arr->i = 0;
	num_arr->n = ft_count_nums(av, ac, num_arr);
	num_arr->num_arr = malloc(num_arr->n * sizeof(int));
	if (!num_arr->num_arr || num_arr->n == 1)
		ft_free_exit(num_arr, "Malloc failed:-(\n", 17);
	while (i < ac)
	{
		if (av[i][j] == '\0')
			ft_increase_i_reset_j(&i, &j);
		else
			ft_if_num(&i, &j, av, num_arr);
	}
	if (ft_check_doubles(num_arr->num_arr, num_arr->n))
		ft_free_exit(num_arr, "More than 2 same nums\n", 22);
}
