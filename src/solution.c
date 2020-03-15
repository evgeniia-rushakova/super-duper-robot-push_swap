/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:57:02 by jslave            #+#    #+#             */
/*   Updated: 2020/02/22 19:57:07 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int             is_num_smaller_than_others(t_stk *stk, int num)
{
    t_stk *head;

    if (!stk || !(head = stk->head))
        return (1);
    while (head)
    {
        if (num > head->num)
            return (-1);
        head = head->next;
    }
    return (1);
}



int             find_holding_numbers3(t_pushswap *ps,  int chunks, int param, int counter)
{
    int num_in_chunks = ps->quant_nums / chunks;
    // 0 min 1 max
    if (counter == 1)
        return (param == 0 ? ps->analyse->sorted_arr[0] : ps->analyse->sorted_arr[num_in_chunks]);
    else if (counter == chunks)
        return (param == 0 ? ps->analyse->sorted_arr[num_in_chunks * (counter - 1) + 1] : ps->analyse->sorted_arr[ps->quant_nums - 1]);
    else
        return (param == 0 ? ps->analyse->sorted_arr[num_in_chunks * (counter - 1) + 1] : ps->analyse->sorted_arr[num_in_chunks *counter]);
}

int             find_quant_nums_in_chunk(t_pushswap *ps, int counter)
{
	t_stk *tmp;
	int numbers_in_chunk;

	numbers_in_chunk = 0;
	if (ps->a && ps->a->head) {
		tmp = ps->a->head;
		while (tmp) {
			if (tmp->num >=
			    find_holding_numbers3(ps, ps->chunks, 0, counter) &&
			    tmp->num <=
			    find_holding_numbers3(ps, ps->chunks, 1, counter)) {
				numbers_in_chunk++;
			}
			tmp = tmp->next;
		}
	}
	return (numbers_in_chunk);
}

int             find_the_biggest_num(t_stk *stk)
{
    t_stk *tmp;
    int max;

    max = 0;

    if (stk && stk->head)
    {
        tmp = stk->head;
        max = tmp->num;
        while (tmp && tmp->next)
        {
            if (max < tmp->next->num)
                max = tmp->next->num;
            tmp = tmp->next;
        }
    }
    return (max);
}

int             find_index_of_num(t_pushswap *ps, int num)
{
    int i;
 //   int f;
    i = 0;
    while (i < ps->quant_nums)
    {
        if (ps->analyse->sorted_arr[i] == num)
            break;
        i++;
    }
    return (i);
}

int         show_last_num_in_stk(t_stk *stk)
{
	t_stk *tmp;

	if(stk && stk->head)
	{
		tmp = stk->head;
		while (tmp)
		{
			if (tmp->next == NULL)
				return (tmp->num);
			tmp = tmp->next;
		}
	}
	return (0);
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

void            push_back_elements_on_a(t_pushswap *ps)
{
	int start;
	int end;
	int max_num_in_stk;

	while (ps->b && ps->b->head)
	{
		max_num_in_stk = find_the_biggest_num(ps->b);
		start = find_steps_before_num(ps->b, 's', find_lst_size(ps->b), max_num_in_stk);
		end = find_steps_before_num(ps->b, 'e', find_lst_size(ps->b), max_num_in_stk);

		if (start <= end) {
			while (ps->b->head->num != max_num_in_stk)///6521
			{
				if ((find_index_of_num(ps, ps->b->head->num) + 1) == find_index_of_num(ps, max_num_in_stk))
					ps_pa(ps, 1);
				else
					ps_rb(ps, 1);
			}
		} else
		{
			while (ps->b->head->num != max_num_in_stk)
			{
				if ((find_index_of_num(ps, ps->b->head->num) + 1) == find_index_of_num(ps, max_num_in_stk))
					ps_pa(ps, 1);
				else
					ps_rrb(ps, 1);
			}
		}
		ps_pa(ps, 1);
		if (ps->a->head->next && ps->a->head->num > ps->a->head->next->num)
			ps_sa(ps, 1);
	}
}

void			create_order_of_chunks(t_pushswap *ps)
{
	int i;
	int chunks;

	if (!(ps->order = malloc(sizeof(int) * ps->chunks)))
		error_out(ps);
	i = 0;
	chunks = ps->chunks;
	while (i < ps->chunks)
	{
		ps->order[i] = chunks;
		i++;
		chunks--;
	}

}

int 			is_num_in_chunk(int num,t_pushswap *ps, int curr_chunk)
{
	if (num >= find_holding_numbers3(ps, ps->chunks, 0, curr_chunk) &&
		num <= find_holding_numbers3(ps, ps->chunks, 1, curr_chunk))
		return (1);
	return (-1);
}

void			sort_args(t_pushswap *ps)
{
	t_stk *tmp;
	int counter = -1;
	create_order_of_chunks(ps);

	while (counter++ < ps->chunks)//check invalid read
	{
	    ft_printf("chunks: %i current_counter: %i current_chunk: :%i \n",ps->chunks, counter, ps->order[counter]);
		while (find_quant_nums_in_chunk(ps, ps->order[counter]) != 0)
		{
			if(ps->a && ps->a->head)
				tmp = ps->a->head;
			while (tmp)
			{
				if (is_num_in_chunk(tmp->num,ps,ps->order[counter]) == 1)
				{
					while (ps->a && ps->a->head->num != tmp->num)
					{
					    if (ps->b && ps->b->head && (find_index_of_num(ps, show_last_num_in_stk(ps->b)) +1) == find_index_of_num(ps, ps->b->head->num))
					        ps_rr(ps, 1);
					    else
						    ps_ra(ps, 1);
					}
					if (ps->a && ps->a->head && ps->a->head->num == tmp->num)
					{
						ps_pb(ps, 1);
						if (is_num_smaller_than_others(ps->b, ps->b->head->num) == 1)
						{
							if (ps->a && ps->a->head && is_num_in_chunk(ps->a->head->num, ps, ps->order[counter]) == 1)
								ps_rb(ps, 1);
							else if (ps->a && ps->a->head)
								ps_rr(ps, 1);
						}
						if (ps->a && ps->a->head)
							tmp = ps->a->head;
						else
							break;
					}
				}
				else
					tmp = tmp->next;
			}
		}
	}
	push_back_elements_on_a(ps);
}

void			push_swap(t_pushswap *ps)
{
	if (ps->quant_nums == 2)
		ps_sa(ps, 1);
	else if (ps->quant_nums > 2 && ps->quant_nums <= 12)
		sort_twelve_max_args(ps);// 12 operations max
	else if (ps->quant_nums > 12)
	{
		if (ps->quant_nums <= 100)
			ps->chunks = 6;
		else if (ps->quant_nums <= 500)
			ps->chunks = 13;
		else
		{
			ps->chunks = 6 + (ps->quant_nums - 100)/50;
			if (ps->chunks % 2 == 0 && ps->quant_nums > 100)
				ps->chunks--;
		}
		sort_args(ps);
		ft_memdel((void **)&ps->order);
	}
	print_analyse(ps);
}

void            print_analyse(t_pushswap *ps)
{
	print_stk(ps->a, 1);
	print_stk(ps->b, 2);
	ft_printf("LST_A_SIZE: %i\n", find_lst_size(ps->a));
	ft_printf("INSTRUCTIONS: %i\n", ps->analyse->instructions);//463 old
    ft_printf("COMMANDS_USED:\nsa: %i  ", ps->analyse->sa);
    ft_printf("sb: %i  ", ps->analyse->sb);
    ft_printf("ss: %i  ", ps->analyse->ss);
    ft_printf("pa: %i  ", ps->analyse->pa);
    ft_printf("pb: %i  ", ps->analyse->pb);
    ft_printf("ra: %i  ", ps->analyse->ra);
    ft_printf("rb: %i  ", ps->analyse->rb);
    ft_printf("rr: %i  ", ps->analyse->rr);
    ft_printf("rra: %i  ", ps->analyse->rra);
    ft_printf("rrb: %i  ", ps->analyse->rrb);
    ft_printf("rrr: %i\n", ps->analyse->rrr);
	if (check_order(ps) == 1)
		ft_printf("****OK****\n");
	else
		ft_printf("****KO****\n");
}
