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

int             find_holding_numbers2(int min, int max, int param, int counter)
{
    // 0 min 1 max
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
/*
  * короче выяснить как тащить самое перове малое число из стека поправить проверку
  * на больше или меньше остальных. в стек б его надо пихать только при условии что оно
  * самое большое в стеке б но при этом самое меньшее в стеке а типа того аааа
  надо чтобы число принадлежало к чанку но при этом было самым наименьшеим чтобы быть запушенным ну или весь чанкк напушить и отсортировать но это такое себе
  */

int             is_nums_in_chunk_is_empty(t_pushswap *ps, int counter)
{

    t_stk *tmp;

    if (ps->a && ps->a->head)
    {
        tmp = ps->a->head;
        while (tmp)
        {
            if (tmp->num >= find_holding_numbers2(ps->min,ps->max, 0, counter) &&
                tmp->num <= find_holding_numbers2(ps->min, ps->max, 1, counter))
            {
                return (-1);
            }

            tmp = tmp->next;
        }
    }
    return (1);
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
            if (tmp->num >= find_holding_numbers2(ps->min,ps->max, 0, counter) &&
                tmp->num <= find_holding_numbers2(ps->min, ps->max, 1, counter))
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
            if (tmp->num >= find_holding_numbers2(ps->min,ps->max, 0, counter) &&
                tmp->num <= find_holding_numbers2(ps->min, ps->max, 1, counter))
                numbers_in_chunk--;
            if (numbers_in_chunk == 0)
                end++;
            tmp = tmp->next;
        }
        return (end);
    }
    return (-1);
}

void            sort_hundred_max_args_4(t_pushswap *ps)
{
    t_stk *tmp;
    int counter = 0;
    int nearest_num_start;
    int nearest_num_end;

    while (counter++ <= 1)
    {
        while (is_nums_in_chunk_is_empty(ps, counter) == -1 && ps->a->head)
        {

            if(!ps->a->head)
                break;
            nearest_num_start = check_the_nearest_num_in_chunk(ps, counter, 's');
            nearest_num_end = check_the_nearest_num_in_chunk(ps, counter, 'e');
            if (nearest_num_start >= nearest_num_end)
                repeat_function(nearest_num_end, ps, ps_rra);//rra
            else
                repeat_function(nearest_num_start, ps, ps_ra);//ra 1976
            tmp = ps->a->head;
            if (is_num_bigger_than_others(ps->b, tmp->num) == 1)
            {
                if (ps->a->num == tmp->num)
                    ps_pb(ps);
            }
            else if (is_num_smaller_than_others(ps->b, tmp->num) == 1)
            {
                if (ps->a->num == tmp->num) {
                    ps_pb(ps);
                    ps_rb(ps);
                }
            } else
            {
                /*
                if (ps->a->num == tmp->num)
                {
                    int j = find_place_for_num(ps, tmp->num);
                    int j_cpy = j;
                    while (j--)
                        ps_rb(ps);
                    ps_pb(ps);
                    while (j_cpy--)
                        ps_rrb(ps);
                }*/
                ps_pb(ps);
                if (ps->b->head->next && ps->b->head->next->num > ps->b->head->num)
                    ps_sb(ps);
            }
            ft_printf("test ");
            print_stk(ps->a, 1);
            print_stk(ps->b, 2);
        }
    }

}//1976

void            sort_hundred_max_args_3(t_pushswap *ps)//1217 instr for this
{
    t_stk *tmp;
    int param = 1;
    int counter = 0;

    while (counter++ <= 5)
    {
       ft_printf("Nearest num in chunk start: %i\n", check_the_nearest_num_in_chunk(ps, counter, 's'));
      ft_printf("Nearest num in chunk end: %i\n", check_the_nearest_num_in_chunk(ps, counter, 'e'));
        while (is_nums_in_chunk_is_empty(ps, counter) == -1 && ps->a->head)
        {
            if(!ps->a->head)
                break;
            tmp = ps->a->head;
            while (tmp)
            {
                if (tmp->num >= find_holding_numbers2(ps->min,ps->max, 0, counter) &&
                    tmp->num <= find_holding_numbers2(ps->min, ps->max, 1, counter))
                {
                    ft_printf("NUM: %i\n", tmp->num);
                    int end = find_steps_before_num(ps->a, 'e', ps->quant_nums, tmp->num);
                    int start = find_steps_before_num(ps->a, 's', ps->quant_nums, tmp->num);

                    if (start <= end) {
                        while (ps->a->num != tmp->num)
                            ps_ra(ps);
                    } else {
                        while (ps->a->num != tmp->num)
                            ps_rra(ps);
                    }
                    if (is_num_bigger_than_others(ps->b, tmp->num) == 1)
                    {

                        if (ps->a->num == tmp->num)
                        {
                            ps_pb(ps);
                        }
                    }
                    else if (is_num_smaller_than_others(ps->b, tmp->num) == 1)
                    {
                        if (ps->a->num == tmp->num) {
                            ps_pb(ps);
                            ps_rb(ps);
                        }
                    } else
                    {
                        if (ps->a->num == tmp->num)
                        {
                            int j = find_place_for_num(ps, tmp->num);
                            int j_cpy = j;
                            while (j--)
                                ps_rb(ps);
                            ps_pb(ps);
                            while (j_cpy--)
                                ps_rrb(ps);
                        }

                    }
                    ft_printf("test ");
                    print_stk(ps->a, 1);
                    print_stk(ps->b, 2);
                    break;
                }
                else
                    tmp = tmp->next;
            }
        }
    }

}

void			push_swap(t_pushswap *ps)
{
	ft_printf("before:\n");
	print_stk(ps->a,1);
	print_stk(ps->b, 2);
	ft_printf("-----------\n");

	find_max_min_medium_nums(ps);
	if (ps->quant_nums == 2)
		ps_sa(ps);
	if (ps->quant_nums == 3)
		sort_three_args(ps, 'a');//3 operations max
	if (ps->quant_nums > 3 && ps->quant_nums <= 5)
		sort_five_max_args(ps);// 12 operations max
	if (ps->quant_nums > 5 && ps->quant_nums <= 100)
    {
	    int i = 1;

        int counter = 1;
        while (counter <=5)
        {
            ft_printf("chunk_start: %i chunk_end: %i\n",find_holding_numbers2
                    (ps->min, ps->max, 0, counter), find_holding_numbers2(ps->min, ps->max, 1, counter) );
            counter++;
        }
      //  while (ps->a && ps->a->head)
            {
                sort_hundred_max_args_4(ps);
               // sort_hundred_max_args_3(ps);
               // find_max_min_medium_nums(ps);
            }
      /*  while (ps->b && ps->b->head)
            ps_pa(ps);*/

    }



	ft_printf("\n-----------\nafter:\n");
	print_stk(ps->a,1);
	print_stk(ps->b, 2);
	ft_printf("INSTRUCTIONS: %i\n", ps->instructions);
	print_analyse(ps);
	if (check_order(ps) == 1)
		ft_printf("****OK****\n");
	else
		ft_printf("****KO****\n");
}

void            print_analyse(t_pushswap *ps)
{
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
}
//166 65 105 125 190 172 10 69 200 16 136 162 118 14 104 27 53 193 5 198 151 197 102 138 23 64 45 122 20 135 60 174 22 84 35 42 49 58 38 149 120 109 11 139 181 112 31 43 21 113 97 158 81 33 39 61 171 83 88 93 115 153 59 91 114 48 173 36 54 159 89 182 155 156 78 55 96 123 47 199 194 56 63 17 52 148 157 188 107 29 67 184 103 66 51 68 8 24 164 95