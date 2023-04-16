#include <stdio.h>
#include <unistd.h>

void ft_rotate(int *stack, int n, int n1, char cond)
{
    int tmp;
    int i;

    i = 0;
    if (cond != 'b')
    {
        tmp = stack[0];
        while (++i < n)
            stack[i - 1] = stack[i];
        stack[n - 1] = tmp;
    }
    i = 0;
    if (cond != 'a')
    {
        tmp = stack[0];
        while (++i < n1)
            stack[i - 1] = stack[i];
        stack[n1 - 1] = tmp;
    }
    if (cond == 'a')
        write(1, "ra\n", 3);
    if (cond == 'b')
        write(1, "rb\n", 3);
    if (cond == 'r')
        write(1, "rr\n", 3);
}

void ft_swap1(int *stack, char cond)
{
    int tmp;

    if (cond != 'b')
    {
        tmp = stack[0];
        stack[0] = stack[1];
        stack[1] = tmp;
    }
    if (cond != 'a')
    {
        tmp = stack[0];
        stack[0] = stack[1];
        stack[1] = tmp;
    }
    if (cond == 'a')
        write(1, "sa\n", 3);
    if (cond == 'b')
        write(1, "sb\n", 3);
    if (cond == 's')
        write(1, "ss\n", 3);
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

int main()
{
    int arr[] = {74, 92, 16, 6, 65, 20, 45, 47, 40, 98, 57, 60, 90, 59, 14, 51, 24, 52, 96, 56, 26, 43, 37, 9, 95, 29, 85, 10, 97, 69, 76, 44, 78, 11, 7, 19, 3, 17, 71, 8, 46, 41, 62, 79, 61, 38, 49, 12, 88, 63, -1};
    int cur_min;

    cur_min = -1;
    while (!ft_if_sorted(arr, 51, '>'))
    {
        while (cur_min != arr[1])
        {
            if (arr[0] > arr[1])
                ft_rotate(arr, 51, 51, 'b');
            else
                ft_swap1(arr, 'b');
        }
        cur_min = arr[0];
        while (-1 != arr[50])
            ft_rotate(arr, 51, 51, 'b');
    }
    for (int i = 50; i >= 0; i--)
        printf("%d  ", arr[i]);
    return (0);
}