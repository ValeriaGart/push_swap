//#include "./incl/push_swap.h"

void    ft_error_exit(char *msg, int len)
{
    write(1, msg, len);
    exit (1);
}

int ft_strsinstr(char **first, char *second, int ac)
{
    int n;
    int j;
    int i;
    int i1;

    i = 1;
    j = 0;
    n = 0;
    if (!(*first) || !second)
        return (-1);
    while (i < ac)
    {
        if (first[i][j] == second[0] && (((j - 1 > -1) && !(ft_strchr("1234567890+-", first[i][j - 1])) || j - 1 == -1)))
        {
            i1 = 0;
            while (second[i1] && first[i][j] == second[i1])
            {
                i1++;
                j++;
            }
            if (second[i1] == '\0' && (first[i][j] == ' ' || !first[i][j]))
                n++;
        }
        if (first[i][j] && first[i][j + 1])
            j++;
        else if (!first[i][j] || first[i][j + 1] == '\0')
        {
            i++;
            j = 0;
        }      
    }
    return (n);
}

void    ft_if_num(int *i, int *j, char **av, t_num_arr *num_arr)
{
    int     ind1;
    int     num_len;
    char    *tmp;

    ind1 = *j;
    num_len = 1;
    if(av[*i][*j] == ' ')
    {
        while (av[*i][*j] && av[*i][*j] == ' ')
            *j += 1;
        return;
    }
    while(av[*i][*j] && ft_strchr("+-0123456789", av[*i][(*j)++]))
        num_len++;
    tmp = malloc(num_len * sizeof(char));
    if (!tmp)
    {
        free(num_arr->num_arr);
        ft_error_exit("Malloc failed\n", 15);
    }
    ft_strlcpy(tmp, (char*)(av[*i] + ind1), num_len);
    if (ft_strsinstr(av, tmp, num_arr->ac) > 1)
    {
        free(tmp);
        free(num_arr->num_arr);
        ft_error_exit("More than 2 same nums\n", 22);
    }
    num_arr->num_arr[num_arr->i] = atoi(tmp);
    num_arr->i += 1;
    free(tmp);
}

int ft_str_check(char **av, int ac)
{
    int i;
    int j;
    int n;

    i = 1;
    j = 0;
    n = 0;
    while(i < ac)
    {
        if (!av[i][j])
        {
            i++;
            j = 0;
        }
        else
        {
            while (av[i][j] == ' ')
                j++;
            if (ft_strchr("+-", av[i][j]))
            {
                if (av[i][j - 1] && !ft_strchr(" ", av[i][j - 1]))
                    ft_error_exit("Wrong digits", 12);
                if (!av[i][j + 1] || !ft_strchr("0123456789", av[i][j + 1]))
                    ft_error_exit("Wrong digits", 12);
                j++;
            }
            if (ft_strchr("0123456789", av[i][j]))
              n++;
            while (av[i][j] != 0 && ft_strchr("0123456789", av[i][j]))
                j++;
            if (!(ft_strchr("0123456789+- ", av[i][j])) && av[i][j])
            {
                ft_error_exit("Wrong digits", 12);
            }
        }
    }
    return (n);
}

int    ft_check_str(int ac, char **av, t_num_arr *num_arr)
{
    char    *tmp;
    int     i;
    int     j;

    i = 1;
    j = 0;
    num_arr->n = ft_str_check(av, ac);
    num_arr->num_arr = malloc(num_arr->n * sizeof(int));
    if(!num_arr->num_arr)
        ft_error_exit("Malloc failed:-(\n", 17);
    num_arr->ac = ac;
    num_arr->i = 0;
    while(i < ac)
    {
        if (av[i][j] == '\0')
        {
            i++;
            j = 0;
        }
        else
            ft_if_num(&i, &j, av, num_arr);
    }
    return (num_arr->n);
}

void    ft_mid_ax(t_num_arr *num_arr)
{
    int i;
    int j;

    i = 0;
    num_arr->mid = num_arr->num_arr[i];
    num_arr->max = num_arr->num_arr[i];
    num_arr->min = num_arr->num_arr[i];
    while (i < num_arr->n)
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
            num_arr->mid = num_arr->num_arr[i];
        if (num_arr->max < num_arr->num_arr[i])
            num_arr->max = num_arr->num_arr[i];
        if (num_arr->min > num_arr->num_arr[i])
            num_arr->min = num_arr->num_arr[i];
        i++;
    }
}

void    ft_to_a_to_b(t_stack *stack, t_num_arr *num_arr)
{
    int i;
    int a;
    int b;

    i = 0;
    b = -1;
    a = -1;
    stack->b[num_arr->a] = num_arr->min;
    while (i < num_arr->n)
    {
        if ((num_arr->num_arr[i] != num_arr->min) && num_arr->num_arr[i] <= num_arr->mid)
        {
            stack->b[++b] = num_arr->num_arr[i];
            write(1, "pb\n", 3);
        }
        else if (num_arr->num_arr[i] > num_arr->mid )
        {
            stack->a[++a] = num_arr->num_arr[i];
            write(1, "ra\n", 3);
        }
        else
            write(1, "pb\nrb\n", 6);
        i++;
    }
    printf("stack a: ");
    for(int i = 0; i < num_arr->b; i++)
        printf("%d\t", stack->a[i]);
    printf("\nstack b: ");
    for(int i = 0; i < num_arr->a + 1; i++)
        printf("%d\t", stack->b[i]);
    printf("\n");
}

void    ft_put_to_stacks(t_num_arr *num_arr, t_stack *stack)
{
    int j;

    j = -1;
    while (++j < num_arr->n)
    {
        if(num_arr->num_arr[j] > num_arr->mid)
            num_arr->b += 1;
        else if(num_arr->num_arr[j] < num_arr->mid)
            num_arr->a += 1;
    }
    stack->a = malloc(num_arr->b * sizeof(int));
    stack->b = malloc((num_arr->a + 1) * sizeof(int));
    if (!stack->a || !stack->b)
    {
        free(num_arr->num_arr);
        ft_error_exit("Malloc failed:(((\n", 18);
    }
    ft_to_a_to_b(stack, num_arr);
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

char    ft_r_rr_sa(t_stack *stack, int *a, t_num_arr *num_arr, int  i)
{
    if (ft_if_sorted(stack->a, i, '<'))
        return ('n');
    if (a[1] == stack->point_a)
    {
        stack->point_a = a[0];
        while (a[i - 1] != num_arr->max)
            ft_rotate(stack, i, 0, 'a');
    }
    if (ft_if_sorted(stack->a, i, '<'))
        return ('n');
    if (a[0] > a[1])
        return ('s');
    else   
        return ('r');
}

char    ft_r_rr_sb(t_stack *stack, int *b, t_num_arr *num_arr, int  i)
{
    if (ft_if_sorted(stack->b, i, '>'))
        return ('n');
    if (b[1] == stack->point_b)
    {
        stack->point_b = b[0];
        while (b[i - 1] != num_arr->min)
        {
            ft_rotate(stack, 0, i, 'b');
            for (int i = num_arr->a; i >= 0; i--)
                printf("%d ", stack->b[i]);
            printf("%d\n", num_arr->min);
        }
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

    if (ft_if_sorted(stack->a, num_arr->b, '<')
        && ft_if_sorted(stack->b, num_arr->a + 1, '>'))
        return;
    a = ft_r_rr_sa(stack, stack->a, num_arr, num_arr->b);
    b = ft_r_rr_sb(stack, stack->b, num_arr, num_arr->a + 1);
    if (a == b && a == 'r')
        ft_rotate(stack, num_arr->b, num_arr->a + 1, 'r');
    else
    {
        if (a == 'r')
            ft_rotate(stack, num_arr->b, 0, 'a');
        if (b == 'r')
            ft_rotate(stack, 0, num_arr->a + 1, 'b');
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
    ft_recursive_sort(stack, num_arr);
}

void    ft_write_the_rest(int i)
{
    i++;
    while (--i)
        write(1, "pa\n", 3);
}

void    ft_sort_all(t_num_arr *num_arr)
{
    t_stack stack;

    ft_mid_ax(num_arr);
    num_arr->a = 0;
    num_arr->b = 0;
    if (ft_if_sorted(num_arr->num_arr, num_arr->n, '<'))
    {
        free (num_arr->num_arr);
            exit(0);
    }
    ft_put_to_stacks(num_arr, &stack);
    stack.point_b = num_arr->min;
    stack.point_a = num_arr->max;
   // ft_recursive_sort(&stack, num_arr);
    ft_write_the_rest(num_arr->a + 1);
    /*printf("\nsorted:\n");
    for (int i = num_arr->a; i >= 0; i--)
        printf("%d ", stack.b[i]);
    for (int i = 0; i < num_arr->b; i++)
        printf("%d ", stack.a[i]);
    printf("\n");*/
}

int main(int ac, char **av)
{
    t_num_arr   num_arr;

    if (ac == 1 || ac == 2)
        return (0);
    ft_check_str(ac, av, &num_arr);
    ft_sort_all(&num_arr);
    free(num_arr.num_arr);
    printf("\nCorrect\n");
    return (0);
}