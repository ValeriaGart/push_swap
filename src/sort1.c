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
	cur_opp->rots = 0;
	ft_cur_change(cur, mid);
}

int	*ft_sorted_arr(int *arr, int n, int tmp)
{
	int	*ret;
	int	i;
	int	j;

	i = -1;
	ret = malloc(n * sizeof(int));
	if (!ret)
		return (NULL);
	while (++i < n)
		ret[i] = arr[i];
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n - 1)
		{
			if (ret[j] > ret[j + 1])
			{
				tmp = ret[j];
				ret[j] = ret[j + 1];
				ret[j + 1] = tmp;
			}
		}
	}
	return (ret);
}

int	ft_corr_place(int *sorted, int cur, int follow, int n)
{
	int	i;

	i = 0;
	while(sorted[i] != cur)
		i++;
	if (i == n - 1)
		return (0);
	if (sorted[i + 1] == follow)
		return (1);
	return (0);
}

void	ft_pa(t_list_num *a, t_list_num *b)
{
	t_list_num *tmp;

	tmp = b;
	while (tmp->next)
		tmp = tmp->next;
	a->n += 1;
	ft_rrotate(a->arr, a->n, 'c');
	a->arr[0] = tmp->arr[0];
	ft_rotate(tmp->arr, tmp->n, 'c');
	tmp->n -= 1;
	if (tmp->n == 0)
	{
		tmp = b;
		if (tmp->next)
		{
			while (tmp->next->next)
				tmp = tmp->next;
			free(tmp->next->arr);
			free(tmp->next);
			tmp->next = NULL;
		}
		else
		{
			free(tmp->arr);
			free(tmp);
		}
	}
	write(1, "pa\n", 3);
}

int ft_last_b_arr(t_list_num *b)
{
	t_list_num *tmp;

	tmp = b;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->arr[0]);
}

void	ft_rotb(t_list_num *b)
{
	int	tmp;
	int	i;
	int *stack;
	int	n;
	t_list_num *tmpar;

	tmpar = b;
	while (tmpar->next)
		tmpar = tmpar->next;
	n = tmpar->n;
	stack = tmpar->arr;
	i = 0;
	tmp = stack[0];
	while (++i < n)
	{
		stack[i - 1] = stack[i];
	}
	stack[n - 1] = tmp;
	write(1, "rb\n", 3);
}

int	ft_last_b(t_list_num *b)
{
	t_list_num *tmp;

	tmp = b;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->n);
}

void	ft_solve(t_list_num *a, t_list_num *b)
{
	int	*sorted;

	if (ft_iff_sorted(a->arr, a->n, a->stack))
		return;
	sorted = ft_sorted_arr(a->arr, a->n, 0);
	if (!sorted)
	{
		free(a);
		exit(1);
	}
	while (a->n > 3)
		ft_split_half(&a, &b, a);
	ft_short_sort(a);
	while (!(a->n == a->n_orig && ft_iff_sorted(a->arr, a->n, a->stack)))
	{
		if (sorted[a->n_orig - 1] == a->arr[a->n - 1])
		{
			ft_pa(a,b);
			if (!ft_corr_place(sorted, a->arr[0], a->arr[1], a->n_orig))
				ft_rotate(a->arr, a->n, 'a');
		}
		else
		{
			if (ft_corr_place(sorted, a->arr[a->n - 1], a->arr[0], a->n_orig))
				ft_rrotate(a->arr, a->n, 'a');
			else if (ft_corr_place(sorted, ft_last_b_arr(b), a->arr[0], a->n_orig))
				ft_pa(a, b);
			else if (ft_last_b_arr(b) > a->arr[a->n - 1])
			{
				ft_pa(a, b);
				ft_rotate(a->arr, a->n, 'a');
			}
			else
			{
				ft_rotb(b);
				b->rots++;
			}
		if (b->rots == ft_last_b(b) && ft_last_b(b) != 0)
				while (b->rots != 0)
				{
					b->rots--;
					write(1, "rrb\n", 4);
				}
		}
	}
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
	ft_solve(&a, b);
	//ft_recurs_solve(&a, &a, b);
}