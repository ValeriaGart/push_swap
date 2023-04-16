#include "../incl/push_swap.h"

void    ft_to_a_to_b(t_stack *stack, t_num_arr *num_arr)
{
    int i;
    int a;
    int b;

    i = 0;
    b = num_arr->b + 2;
    a = num_arr->a + 1;
    while (i < num_arr->n)
    {
        if (num_arr->num_arr[i] <= stack->mid)
        {
            stack->b[--b] = num_arr->num_arr[i];
            if (num_arr->num_arr[i] == stack->min && b != 0)
            {
                num_arr->ac = b + 1;
                while ()
                write(1, "rb\n", 3);
            }
            write(1, "pb\n", 3);
        }
        else if (num_arr->num_arr[i] > stack->mid)
        {
            stack->a[--a] = num_arr->num_arr[i];
            write(1, "ra\n", 3);
        }
        i++;
    }
  printf("stack a: ");
    for(int i = 0; i < num_arr->a; i++)
        printf("%d\t", stack->a[i]);
    printf("\nstack b: ");
    for(int i = 0; i < num_arr->b + 1; i++)
        printf("%d\t", stack->b[i]);
    printf("\n");
}

void    ft_put_to_stacks(t_num_arr *num_arr, t_stack *stack)
{
    int j;

    j = -1;
    while (++j < num_arr->n)
    {
        if(num_arr->num_arr[j] > num_arr->stack->mid)
            num_arr->a += 1;
        else if(num_arr->num_arr[j] < num_arr->stack->mid)
            num_arr->b += 1;
    }
    stack->a = malloc(num_arr->a * sizeof(int));
    stack->b = malloc((num_arr->b + 1) * sizeof(int));
    if (!stack->a || !stack->b)
        ft_free_exit(num_arr, "Malloc failed:(((\n", 18);
    ft_to_a_to_b(stack, num_arr);
}

void    ft_mid_ax(t_num_arr *num_arr, int i)
{
    int j;

    num_arr->stack->mid = num_arr->num_arr[i + 1];
    num_arr->stack->max = num_arr->num_arr[i + 1];
    num_arr->stack->min = num_arr->num_arr[i + 1];
    while (++i < num_arr->n)
    {
        j = -1;
        num_arr->a = 0;
        num_arr->b = 0;
        while (++j < num_arr->n)
        {
            if(num_arr->num_arr[j] > num_arr->num_arr[i])
                num_arr->b += 1;
            else if(num_arr->num_arr[j] < num_arr->num_arr[i])
                num_arr->a += 1;
        }
        if ((num_arr->a - num_arr->b) <= 1 && (num_arr->a - num_arr->b) >= -1)
            num_arr->stack->mid = num_arr->num_arr[i];
        if (num_arr->stack->max < num_arr->num_arr[i])
            num_arr->stack->max = num_arr->num_arr[i];
        if (num_arr->stack->min > num_arr->num_arr[i])
            num_arr->stack->min = num_arr->num_arr[i];
    }
}

void    ft_sort_all(t_num_arr *num_arr, t_stack *stack)
{
    ft_mid_ax(num_arr, -1);
    num_arr->a = 0;
    num_arr->b = 0;
    if (ft_if_sorted(num_arr->num_arr, num_arr->n, '<'))
    {
        free (num_arr->num_arr);
        exit(0);
    }
    ft_put_to_stacks(num_arr, stack);
    stack->point_b = num_arr->stack->min;
    stack->point_a = num_arr->stack->max;
    stack->rem_b = 0;
    stack->rem_a = 0;
    ft_recursive_sort(stack, num_arr);
    ft_write_the_rest(num_arr->a + 1);
    printf("\nsorted:\n");
    for (int i = num_arr->b; i >= 0; i--)
        printf("%d ", stack->b[i]);
    for (int i = 0; i < num_arr->a; i++)
        printf("%d ", stack->a[i]);
    printf("\n");
}