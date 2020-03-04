//
// Created by janevermilion on 03.03.2020.
//

#include "pushswap.h"

void	swap_elements(int *tab, int p1, int p2)
{
    int tmp = tab[p1];
    tab[p1] = tab[p2];
    tab[p2] = tmp;
}

void	bubble_sort(int *tab, int size)
{
    int i = 0;
    int j = 0;

    while (i < size)
    {
        j = 0;
        while (j < size - 1)
        {
            if (tab[j] > tab[j + 1])
                swap_elements(tab, j, j + 1);
            j++;
        }
        i++;
    }
}

void	sort_int_tab(int *tab,  int size)
{
    if (size <= 1)
        return ;
    bubble_sort(tab, size);
}


int         create_sorted_array(t_pushswap *ps)
{
    t_stk *tmp;
    int i;

    i = 0;
    if (!(ps->analyse->sorted_arr = (int *)malloc(sizeof(int) * ps->quant_nums)))
        return (-1);
    tmp = ps->a->head;
    while (tmp && i < ps->quant_nums)
    {
        ps->analyse->sorted_arr[i] = tmp->num;
        i++;
        tmp = tmp->next;
    }
    sort_int_tab(ps->analyse->sorted_arr, ps->quant_nums);
    return (1);
}

