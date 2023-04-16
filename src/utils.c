#include "../incl/push_swap.h"

void    ft_increase_i_reset_j(int *i, int *j)
{
    (*i)++;
    *j = 0;
}

void    ft_write_the_rest(int i)
{
    //i++;
    while (--i)
        write(1, "pa\n", 3);
}

int ft_if_sorted(int *num_arr, int n, char dir)
{
    int i;
    int count;

    i = -1;
    count = 0;
    while (++i < n - 1)
    {
        if (num_arr[i + 1] > num_arr[i] && dir == '<')
            count++;
        if (num_arr[i + 1] < num_arr[i] && dir == '>')
            count++;
    }
    if (count == n - 1)
        return (1);
    return (0);
}