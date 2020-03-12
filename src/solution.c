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

int             find_holding_numbers3(t_pushswap *ps,  int chunks, int param, int counter)
{
    int num_in_chunks = ps->quant_nums / chunks;
    // 0 min 1 max
    if (counter == 1)
        return (param == 0 ? ps->min : ps->analyse->sorted_arr[num_in_chunks]);
    else if (counter == chunks)
        return (param == 0 ? ps->analyse->sorted_arr[num_in_chunks * (counter - 1) + 1] : ps->max);
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
    int f;
    i = 0;
    while (i < ps->quant_nums)
    {
        if (ps->analyse->sorted_arr[i] == num)
            break;
        i++;
    }
    return (i);
}

void            push_back_elements_on_a(t_pushswap *ps)
{
    int start;
    int end;
    int max_num_in_stk;
    int test = 0;
    int flag = 0;

    while (ps->b && ps->b->head)
    {
        max_num_in_stk = find_the_biggest_num(ps->b);
        start = find_steps_before_num(ps->b, 's', find_lst_size(ps->b), max_num_in_stk);
        end = find_steps_before_num(ps->b, 'e', find_lst_size(ps->b), max_num_in_stk);


          if (start <= end) {
              while (ps->b->head->num != max_num_in_stk)///6521
              {
                  if ((find_index_of_num(ps, ps->b->head->num) + 1) == find_index_of_num(ps, max_num_in_stk))
                  {
                      ft_printf("MAX_NUM : %i\n", max_num_in_stk);
                      ps_pa(ps, 1);
                  }
                  else
                      ps_rb(ps, 1);
              }
          } else
          {
              //test = 1;
              while (ps->b->head->num != max_num_in_stk)
              {
                 if ((find_index_of_num(ps, ps->b->head->num) + 1) == find_index_of_num(ps, max_num_in_stk))
                      ps_pa(ps, 1);
                 else
                      ps_rrb(ps, 1);
              }
          }
          ps_pa(ps, 1);
          print_stk(ps->a, 1);
          if (ps->a->head->next && ps->a->head->num > ps->a->head->next->num)
              ps_sa(ps, 1);
          print_stk(ps->a, 1);



    }
    ft_printf("TEST: %i\n", test);//7087
}

void			create_order_of_chunks(t_pushswap *ps)
{
	int i;
	int devide;
	int chunks;

	i = 0;
	chunks = ps->chunks;
	devide = ps->chunks / 2;
	int diff = 1;
	if (!(ps->order = malloc(sizeof(int) * chunks)))
		error_out(ps);
	while (i < ps->chunks)
	{
		ps->order[i] = devide;
		ps->order[i + 1] = devide + diff;
		diff += 2;
		i += 2;
		devide--;
	}
	i = 0;
	int max = ps->chunks;
	while (i < ps->chunks)
	{
		ps->order[i] = max;
		i++;
		max--;
	}
}

int 			is_num_in_chunk(int num,t_pushswap *ps, int curr_chunk)
{
	if (num >= find_holding_numbers3(ps, ps->chunks, 0, curr_chunk) &&
		num <= find_holding_numbers3(ps, ps->chunks, 1, curr_chunk))
		return (1);
	return (-1);
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


void			sort_hundred_max_args_4(t_pushswap *ps)
{
	t_stk *tmp;
	int i;
	int counter = -1;
	create_order_of_chunks(ps);
	i = 0;

	while (counter++ < ps->chunks)
	{
		while (find_quant_nums_in_chunk(ps, ps->order[counter]) != 0)
		{
			if(!ps->a || !ps->a->head)
				break;
			else
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
				//	print_stk(ps->a, 1);
				//	print_stk(ps->b, 2);
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
	find_max_min_medium_nums(ps);
	if (ps->quant_nums == 2)
		ps_sa(ps, 1);
	else if (ps->quant_nums == 3)
		sort_three_args(ps, 'a');//3 operations max
	else if (ps->quant_nums > 3 && ps->quant_nums <= 5)
		sort_five_max_args(ps);// 12 operations max
	else if (ps->quant_nums > 5)
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
		sort_hundred_max_args_4(ps);
		ft_memdel((void **)&ps->order);
	}
	print_analyse(ps);

}

void            print_analyse(t_pushswap *ps)
{
	//print_stk(ps->a, 1);
	//print_stk(ps->b, 2);
	/*int i;

	i = 0;
	ft_printf("NUM IN CHUNKS: %i\n", ps->quant_nums/ps->chunks);
	ft_printf("ORDER: ");
	while (i < ps->chunks)
	{
		ft_printf("%i ", ps->order[i]);
		i++;
	}
	ft_printf("\n");*/
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
//166 65 105 125 190 172 10 69 200 16 136 162 118 14 104 27 53 193 5 198 151 197 102 138 23 64 45 122 20 135 60 174 22 84 35 42 49 58 38 149 120 109 11 139 181 112 31 43 21 113 97 158 81 33 39 61 171 83 88 93 115 153 59 91 114 48 173 36 54 159 89 182 155 156 78 55 96 123 47 199 194 56 63 17 52 148 157 188 107 29 67 184 103 66 51 68 8 24 164 95