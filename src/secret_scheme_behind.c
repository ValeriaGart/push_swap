#include "../incl/push_swap.h"

void    ft_rrotate(t_stack *stack, int n, int n1, char cond)
{
    int tmp;
    int i;

    i = n + 1;
    if (cond != 'b')
    {
        tmp = stack->a[n - 1];
        while (--i > 1)
            stack->a[i - 1] = stack->a[i - 2];
        stack->a[0] = tmp;
    }
    i = n1 + 1;
    if (cond != 'a')
    {
        tmp = stack->b[n1 - 1];
        while (--i > 1)
            stack->b[i - 1] = stack->b[i - 2];
        stack->b[0] = tmp;
    }
    if (cond == 'a')
        write(1, "rra\n", 4);
    if (cond == 'b')
        write(1, "rrb\n", 4);
    if (cond == 'r')
        write(1, "rrr\n", 4);
}

void    ft_rotate(t_stack *stack, int n, int n1, char cond)
{
    int tmp;
    int i;

    i = 0;
    if (cond != 'b')
    {
        tmp = stack->a[0];
        while (++i < n)
            stack->a[i - 1] = stack->a[i];
        stack->a[n - 1] = tmp;
    }
    i = 0;
    if (cond != 'a')
    {
        tmp = stack->b[0];
        while (++i < n1)
            stack->b[i - 1] = stack->b[i];
        stack->b[n1 - 1] = tmp;
    }
    if (cond == 'a')
        write(1, "ra\n", 3);
    if (cond == 'b')
        write(1, "rb\n", 3);
    if (cond == 'r')
        write(1, "rr\n", 3);
}

void    ft_swap1(t_stack *stack, char cond)
{
    int tmp;

    if (cond != 'b')
    {
        tmp = stack->a[0];
        stack->a[0] = stack->a[1];
        stack->a[1] = tmp;
    }
    if (cond != 'a')
    {
        tmp = stack->b[0];
        stack->b[0] = stack->b[1];
        stack->b[1] = tmp;
    }
    if (cond == 'a')
        write(1, "sa\n", 3);
    if (cond == 'b')
        write(1, "sb\n", 3);
    if (cond == 's')
        write(1, "ss\n", 3);
}
