/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:11:33 by vharkush          #+#    #+#             */
/*   Updated: 2023/05/28 10:53:26 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_num_arr
{
	char	*tmp;
	int		*num_arr;
	int		n;
	int		ac;
	int		i;
	int		a;
	int		b;
}		t_num_arr;

typedef struct s_list_num
{
	int					*arr;
	int					ind;
	int					n;
	int					n_orig;
	int					rots;
	int					stack;
	struct s_list_num	*next;
}			t_list_num;

int			ft_iff_sorted(int *num_arr, int n, char dir);
int			ft_mid_ax(int *num_arr, int n, int stack);
int			ft_check_doubles(int *arr, int n);
int			ft_special_ifs(t_list_num *cur, t_list_num *a,
				t_list_num *b, int n);
void		ft_add_back(t_list_num ***ab, t_list_num *cur_opp);
void		ft_cpy_to_cur(int *from, int *to, int n);
void		ft_cur_change(t_list_num *cur, int mid);
void		ft_check_str(int ac, char **av, t_num_arr *num_arr);
void		ft_short_sort(t_list_num *cur);
void		ft_swap1(int *stack, char cond);
void		ft_rotate(int *stack, int n, char cond);
void		ft_rrotate(int *stack, int n, char ab);
void		ft_error_exit(char *msg, int len);
void		ft_free_exit(t_num_arr *num_arr, char *msg, int len);
void		ft_increase_i_reset_j(int *i, int *j);
void		write_a(t_list_num *cur, t_list_num *cur_opp, int mid);
void		write_b(t_list_num *cur, t_list_num *cur_opp, int mid);
void		ft_write_the_rest(int i);
void		ft_if_all_args_empty(int ac, char **av, t_num_arr *num_arr);
void		ft_push_opp_to_cur(t_list_num *cur, t_list_num *cur_opp,
				t_list_num *one_bef_last);
void		ft_leave_it_here(t_list_num	*to, t_list_num	*from,
				t_list_num	*last_opp);
void		ft_sort_all(t_num_arr	*num_arr, int *arr, int n);
void		ft_set_to_null(t_list_num *arr);
void		ft_free_all_u_can_reee(t_list_num	*a, t_list_num	*b);
void		ft_push_back(t_list_num *cur, t_list_num *a, t_list_num *b);
t_list_num	*ft_cur_opp(t_list_num *cur, t_list_num *cur_opp, int mid);
t_list_num	*ft_last_opp(t_list_num *cur, t_list_num *a, t_list_num *b);

#endif
