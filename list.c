#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

int cmp(void *a, void *b)
{
    if (a == b)
        return (0);
    return (1);
}

void    ft_del_if(t_list **ma_list, void *data, int (*cmp)())
{
    t_list  *cur;

    cur = *ma_list;
    if (cur)
    {
        *ma_list = cur->next;
        free(cur);
    }
}
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)
		return;

	t_list *cur = *begin_list;

	if (cmp(cur->content, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	cur = *begin_list;
	ft_list_remove_if(&cur->next, data_ref, cmp);
}

int main()
{
    t_list  ma_list;
    t_list  *cur;
    t_list  *start;
    
    ma_list.content = (int *)4;
    cur = &ma_list;
    start = cur;
    cur->next = malloc(sizeof(t_list));
    cur = cur->next;
    cur->content = (int *)8;
    cur->next = malloc(sizeof(t_list));
    cur = cur->next;
    cur->content = (int *)4;
    cur->next = NULL;
    ft_list_remove_if(&start, (int *)4, (*cmp));
    return (0);
}