#include "../incl/push_swap.h"

int    ft_check_special(t_stack *stack, int *b, char ind)
{
    int j;
    int min;

    j = -1;
    min = b[0];
    if (ind == 'b')
    {
        while (b[++j] != stack->point_b)
        {
            if (min > b[j])
                min = b[j];
        }
        if (b[j - 1] == min)
        {
            stack->point_b = b[j - 1];
            ft_check_special(stack, b, 'b');
        }
        j = 0;
        while (b[j] != stack->min)
            j++;
    }
    else
    {
        j = 0;
        while (b[j] != stack->max)
            j++;
    }
    return (j);
}

char    ft_r_rr_sa(t_stack *stack, int *a, int  i)
{
    if (ft_if_sorted(stack->a, i, '<'))
        return ('n');
    if (a[1] == stack->point_a || stack->rem_a)
    {
     /*   if(stack->rem_a == 0 && ft_check_special(stack, a, 'a') < i / 2)
            stack->rem_a = 1;
        else if (stack->rem_a == 0)
            stack->rem_a = 2;
        if (a[i - 1] != stack->max && stack->rem_a == 1)
            return ('r');
        else if (a[i - 1] != stack->max && stack->rem_a == 2)
            return ('R');
        else
            stack->rem_a = 0;*/
        if(ft_check_special(stack, a, 'a') < i / 2)
            while (a[i - 1] != stack->max)
                ft_rotate(stack, i, 0, 'a');
        else
            while (a[i - 1] != stack->max)
                ft_rrotate(stack, i, 0, 'a');
    }
    if (ft_if_sorted(stack->a, i, '<'))
        return ('n');
    if (a[0] > a[1])
        return ('s');
    else   
        return ('r');
}

char    ft_r_rr_sb(t_stack *stack, int *b, int  i)
{
    if (ft_if_sorted(stack->b, i, '>'))
        return ('n');
   /* if (b[1] == stack->point_b || stack->rem_b != 0)
    {
        if(stack->rem_b == 0 && ft_check_special(stack, b, 'b') < i / 2)
            stack->rem_b = 1;
        else if (stack->rem_b == 0)
            stack->rem_b = 2;
        if (b[i - 1] != stack->min && stack->rem_b == 1)
            return ('r');
        else if (b[i - 1] != stack->min && stack->rem_b == 2)
            return ('R');
        else
            stack->rem_b = 0;
    }*/
    if (b[1] == stack->point_b)
    {
        if(ft_check_special(stack, b, 'b') < i / 2)
            while (b[i - 1] != stack->min)
                ft_rotate(stack, 0, i, 'b');
        else
            while (b[i - 1] != stack->min)
                ft_rrotate(stack, 0, i, 'b');
    }
    if (ft_if_sorted(stack->b, i, '>'))
        return ('n');
    if (b[0] > b[1])
        return ('r');
    else   
        return ('s');
}

void    ft_recursive_sort(t_stack *stack, t_num_arr *num_arr)
{
    char    a;
    char    b;

    if (ft_if_sorted(stack->a, num_arr->a, '<')
        && ft_if_sorted(stack->b, num_arr->b + 1, '>'))
        return;
    a = ft_r_rr_sa(stack, stack->a, num_arr->a);
    b = ft_r_rr_sb(stack, stack->b,num_arr->b + 1);
    if (a == b && a == 'r')
        ft_rotate(stack, num_arr->b, num_arr->b + 1, 'r');
    else
    {
        if (a == 'r')
            ft_rotate(stack, num_arr->a, 0, 'a');
        if (b == 'r')
            ft_rotate(stack, 0, num_arr->b + 1, 'b');
    }
    if (a == b && a == 's')
        ft_swap1(stack, 's');
    else
    {
        if (a == 's')
            ft_swap1(stack, 'a');
        if (b == 's')
            ft_swap1(stack, 'b');
    }
    if (a == b && a == 'R')
        ft_rrotate(stack, num_arr->b, num_arr->b + 1, 'r');
    else
    {
        if (a == 'R')
            ft_rrotate(stack, num_arr->a, 0, 'a');
        if (b == 'R')
            ft_rrotate(stack, 0, num_arr->b + 1, 'b');
    }
    ft_recursive_sort(stack, num_arr);
}
