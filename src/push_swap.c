#include "../incl/push_swap.h"

int main(int ac, char **av)
{
    t_num_arr   num_arr;

    if (ac == 1 || ac == 2)
        return (1);
    num_arr.stack = malloc(sizeof(t_stack));
    if (!num_arr.stack)
        ft_error_exit("Malloc failed:-(\n", 17);
    ft_check_str(ac, av, &num_arr);
    ft_sort_all(&num_arr, num_arr.stack);
    free(num_arr.stack);
    free(num_arr.num_arr);
    return (0);
}