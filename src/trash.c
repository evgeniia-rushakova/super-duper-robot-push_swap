//
// Created by janevermilion on 04.03.2020.
//

int            check_the_nearest_num_in_chunk(t_pushswap *ps, int counter, char opt)
{
	t_stk *tmp;
	int numbers_in_chunk;
	int end;
	int i;
	i = 0;
	end = 0;
	numbers_in_chunk = 0;
	if (ps->a && ps->a->head)
	{
		tmp = ps->a->head;
		while (tmp)
		{
			i++;
			if (tmp->num >= find_holding_numbers3(ps, ps->chunks, 0, counter) &&
				tmp->num <= find_holding_numbers3(ps, ps->chunks, 1, counter))
			{
				numbers_in_chunk++;
				if (opt == 's')
					return (i);
			}
			tmp = tmp->next;
		}
		tmp = ps->a->head;
		while (tmp)
		{
			if (tmp->num >= find_holding_numbers3(ps, ps->chunks, 0, counter) &&
				tmp->num <= find_holding_numbers3(ps, ps->chunks, 1, counter))
				numbers_in_chunk--;
			if (numbers_in_chunk == 0)
				end++;
			tmp = tmp->next;
		}
		return (end);
	}
	return (-1);
}

int 			is_smaller_num_on_top(t_stk *stk)
{
	t_stk *tmp;
	int first_num;

	if (stk && stk->head && stk->head->next)
	{
		tmp = stk->head->next;
		first_num = tmp->num;
		while (tmp)
		{
			if (tmp->num < first_num)
				return (-1);
			tmp = tmp->next;
		}
	}
	return (1);
}

int 			find_minimum_value_in_lst(t_stk *stk, int arg)//arg = 0 min arg = 1 max
{
	t_stk *tmp;
	int min;

	min = 0;
	if (stk && stk->head)
	{
		tmp = stk->head;
		min = stk->head->num;
		tmp = tmp->next;
		while (tmp)
		{
			if (arg == 0)
			{
				if (tmp->num < min)
					min = tmp->num;
			} else
			if (tmp->num > min)
				min = tmp->num;
			tmp = tmp->next;
		}
	}
	return (min);
}
void			get_minimum_on_top_2(t_pushswap *ps)
{
	int minval;
	int start_steps;
	int end_steps;
	minval = find_minimum_value_in_lst(ps->b, 0);
	start_steps = find_steps_before_num(ps->b, 's', find_lst_size(ps->b), minval);
	end_steps = find_steps_before_num(ps->b, 'e', find_lst_size(ps->b), minval);

	if (start_steps == 0 || end_steps == 0)
	{
		if (end_steps == 0)
			ps_rrb(ps, 1);
		return;
	}
	if (start_steps < end_steps)
		while (start_steps-- != 0)
			ps_rb(ps, 1);
	else
		while (end_steps-- != 0)
			ps_rrb(ps, 1);
}

int 			get_num_by_place(t_pushswap *ps, int steps, char opt)
{
	t_stk *tmp;
	int count;

	count = opt == 's' ? steps : (ps->quant_nums - steps);
	if (ps->a && ps->a->head)
	{
		tmp = ps->a->head;
		while(tmp && count--)
			tmp = tmp->next;
		return (tmp->num);
	}
	return (0);
}


void			get_maximum_on_top_2(t_pushswap *ps)
{
	int minval;
	int start_steps;
	int end_steps;

	minval = find_minimum_value_in_lst(ps->b, 1);
	start_steps = find_steps_before_num(ps->b, 's', find_lst_size(ps->b), minval);
	end_steps = find_steps_before_num(ps->b, 'e', find_lst_size(ps->b), minval);

	if (start_steps == 0 || end_steps == 0)
	{
		if (end_steps == 0)
			ps_rrb(ps, 1);
		return;
	}
	if (start_steps < end_steps && ps->b->head && ps->b)
		while (start_steps-- != 0)
			ps_rb(ps, 1);
	else if (ps->b->head && ps->b)
		while (end_steps-- != 0)
			ps_rrb(ps, 1);
}
int				find_steps_before_min_num_in_chunk(t_pushswap *ps, int counter, char opt)
{
	int num_in_chunk;
	t_stk *tmp;
	int min;

	min = 0;
	num_in_chunk = ps->quant_nums/ps->chunks;
	if (ps->a && ps->a->head)
	{
		tmp = ps->a->head;
		while (tmp)
		{
			if (tmp->num >= find_holding_numbers3(ps, ps->chunks, 0, counter) &&
				tmp->num <= find_holding_numbers3(ps, ps->chunks, 1, counter))
			{
				min = tmp->num;
				tmp = tmp->next;
				num_in_chunk--;
				break;
			}
			tmp = tmp->next;
		}
		while (tmp && num_in_chunk)
		{
			if (tmp->num >= find_holding_numbers3(ps, ps->chunks, 0, counter) &&
				tmp->num <= find_holding_numbers3(ps, ps->chunks, 1, counter))
			{
				if (min > tmp->num)
					min = tmp->num;
				num_in_chunk--;
			}
			tmp = tmp->next;
		}
	}
	int start_steps = find_steps_before_num(ps->a, 's', find_lst_size(ps->a), min);
	int end_steps = find_steps_before_num(ps->a, 'e', find_lst_size(ps->a), min);
	//ft_printf("MIN NUM IN CHUNK: %i", min);
	return (opt == 's' ? start_steps : end_steps);
}


void            sort_hundred_max_args_1(t_pushswap *ps)
{
	t_stk *tmp;
	int counter = 0;

	while (counter++ <= ps->chunks)
	{
		while (find_quant_nums_in_chunk(ps, counter) != 0)
		{
			if(!ps->a || !ps->a->head)
				break;
			int end = check_the_nearest_num_in_chunk(ps, counter, 'e');
			int start = check_the_nearest_num_in_chunk(ps, counter, 's');
			if (start <= end && (start != 1 && end != 1)) {
				while (start--)
					ps_ra(ps, 1);
			} else
			{
				while (end--)
					ps_rra(ps, 1);
			}
			tmp = ps->a->head;
			if (tmp->num >= find_holding_numbers3(ps, ps->chunks, 0, counter) &&
				tmp->num <= find_holding_numbers3(ps, ps->chunks, 1, counter))
				ps_pb(ps, 1);
		}
	}
	push_back_elements_on_a(ps);
}

void			sort_hundred_max_args_3(t_pushswap *ps)
{
	t_stk *tmp;


	create_order_of_chunks(ps);
	int i;
	i = 0;
	int counter = 0;
	while (counter < ps->chunks)
	{

		while (find_quant_nums_in_chunk(ps, ps->order[counter]) != 0)
		{
			if(!ps->a || !ps->a->head)
				break;
			int end = check_the_nearest_num_in_chunk(ps, ps->order[counter], 'e');
			int start = check_the_nearest_num_in_chunk(ps, ps->order[counter], 's');
			if (start <= end && (start != 1 && end != 1)) {
				while (start--)
					ps_ra(ps, 1);
			} else
			{
				while (end--)
					ps_rra(ps, 1);
			}
			tmp = ps->a->head;
			if (tmp->num >= find_holding_numbers3(ps, ps->chunks, 0, ps->order[counter]) &&
				tmp->num <= find_holding_numbers3(ps, ps->chunks, 1, ps->order[counter]))
			{
				ps_pb(ps, 1);
				if (is_num_smaller_than_others(ps->b, ps->b->head->num) == 1)
					ps_rb(ps, 1);
			}

		}
		//print_stk(ps->a, 1);
		//print_stk(ps->b, 2);
		counter++;
	}
	push_back_elements_on_a(ps);
	ft_memdel((void **)&ps->order);
}

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

int             is_num_bigger_than_others(t_stk *stk, int num)
{
	t_stk *head;

	if (!stk || !(head = stk->head))
		return (1);
	while (head)
	{
		if (num < head->num)
			return (-1);
		head = head->next;
	}
	return (1);
}

int            is_this_nums_in_stk(t_stk *stk, int min, int middle, int max)
{
	t_stk *tmp;
	int i;

	i = 0;
	tmp = stk->head;
	while (tmp)
	{
		if (tmp->num == min || tmp->num == max || tmp->num == middle)
			i++;
		tmp = tmp->next;
	}
	return (i == 2 ? 1 : 0);
}

