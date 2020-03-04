//
// Created by janevermilion on 04.03.2020.
//

int           find_place_for_num(t_pushswap *ps, int num)
{
    t_stk *head;
    t_stk *prev;
    int i = 0;

    head = ps->b->head;

    while (head && head->next)
    {
        prev = head;
        i++;
        if (num < prev->num && num > head->next->num)
            break;

        head = head->next;
    }
    return (i);

}

int             is_nums_in_chunk_is_empty(t_pushswap *ps, int counter)
{

    t_stk *tmp;
    int i;

    i = 0;

    if (ps->a && ps->a->head)
    {
        tmp = ps->a->head;
        while (tmp)
        {
            if (tmp->num >= find_holding_numbers3(ps, 15, 0, counter) &&
                tmp->num <= find_holding_numbers3(ps, 15, 1, counter))
            {
                return (-1);
            }

            tmp = tmp->next;
        }
    }
    return (1);
}

int             find_holding_numbers2(int min, int max, int param, int counter)
{

    int step;

    step = (max - min) / 5;
    if (counter == 1)
        return (param == 0 ? min : step);
    if (counter == 2)
        return (param == 0 ? step + 1 : (step * 2));
    if (counter == 3)
        return (param == 0 ? (step * 2 + 1) : (step * 3));
    if (counter == 4)
        return (param == 0 ? (step * 3 + 1) : (step * 4));
    if (counter == 5)
        return (param == 0 ? (step * 4 + 1) : (max));
    return (0);
}

