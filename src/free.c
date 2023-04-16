#include "../incl/push_swap.h"

void    ft_error_exit(char *msg, int len)
{
    write(1, msg, len);
    exit (1);
}

void    ft_free_exit(t_num_arr *num_arr, char *msg, int len)
{
    if (num_arr->num_arr)
        free(num_arr->num_arr);
    if (num_arr->tmp)
        free(num_arr->tmp);
    if (num_arr->stack)
        free(num_arr->stack);
    ft_error_exit(msg, len);
}