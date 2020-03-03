//
// Created by janevermilion on 03.03.2020.
//

#include "pushswap.h"

void            sort_hundred_max_args_4(t_pushswap *ps)
{
    t_stk *tmp;
    int counter = 0;
    int nearest_num_start;
    int nearest_num_end;

    while (counter++ <= 5)
    {
        while (is_nums_in_chunk_is_empty(ps, counter) == -1 && ps->a->head)
        {
            if(!ps->a || !ps->a->head)
                break;
            nearest_num_start = check_the_nearest_num_in_chunk(ps, counter, 's');
            nearest_num_end = check_the_nearest_num_in_chunk(ps, counter, 'e');

            if (nearest_num_start >= nearest_num_end)
                repeat_function(nearest_num_end, ps, ps_rra);//rra
            else
                repeat_function(nearest_num_start, ps, ps_ra);//ra 1976
            tmp = ps->a->head;
            if (tmp->num >= find_holding_numbers2(ps->min,ps->max, 0, counter) &&
                tmp->num <= find_holding_numbers2(ps->min, ps->max, 1, counter))
            {
                ft_printf("NUM: %i\n", tmp->num);
                if (tmp->num == 198 && find_lst_size(ps->a) == 1)
                    ft_printf("WTF");
                if (is_num_bigger_than_others(ps->b, tmp->num) == 1 && find_lst_size(ps->a) > 1)
                {

                    if (ps->a->num == tmp->num)
                        ps_pb(ps);
                }
                else if (is_num_smaller_than_others(ps->b, tmp->num) == 1 && find_lst_size(ps->a) > 1)
                {
                    if (ps->a->num == tmp->num) {
                        ps_pb(ps);
                        ps_rb(ps);
                    }
                }
                else
                {
                    int tmp2 = tmp->num;
                    ps_ra(ps);
                    while (is_num_smaller_than_others(ps->b, tmp2) == -1 && is_num_bigger_than_others(ps->b, tmp2) == -1)
                    {
                        ps_pa(ps);
                    }
                    ps_rra(ps);
                    tmp = ps->a->head;
                    if (is_num_bigger_than_others(ps->b, tmp->num) == 1)
                    {
                        if (ps->a->num == tmp->num)
                            ps_pb(ps);
                    }
                    else if (is_num_smaller_than_others(ps->b, tmp->num) == 1) {
                        if (ps->a->num == tmp->num) {
                            ps_pb(ps);
                            ps_rb(ps);
                        }
                    }
                }
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
                    ft_printf("start: %i  ", start);
                    ft_printf("end: %i\n", end);
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
                                ps_rrb(ps);//rrb
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

void            sort_hundred_max_args_2(t_pushswap *ps)//1217 instr for this
{
    t_stk *tmp;
    int param = 1;
    int counter = 0;

    while (counter++ <= 5)
    {

        ft_printf("Nearest num in chunk start: %i\n", check_the_nearest_num_in_chunk(ps, counter, 's'));
        ft_printf("Nearest num in chunk end: %i\n", check_the_nearest_num_in_chunk(ps, counter, 'e'));
        while (is_nums_in_chunk_is_empty(ps, counter) == -1)
        {
            if(!ps->a || !ps->a->head)
                break;

            int end = check_the_nearest_num_in_chunk(ps, counter, 'e');
            int start = check_the_nearest_num_in_chunk(ps, counter, 's');
            ft_printf("start: %i  ", start);
            ft_printf("end: %i\n", end);
            if (start <= end && (start != 1 && end != 1)) {
                while (start--)
                    ps_ra(ps);
            } else
            {
                while (end--)
                    ps_rra(ps);
            }
            tmp = ps->a->head;
            if (tmp->num >= find_holding_numbers2(ps->min,ps->max, 0, counter) &&
                tmp->num <= find_holding_numbers2(ps->min, ps->max, 1, counter))
            {
                ft_printf("NUM: %i\n", tmp->num);

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
                    ft_printf("HERE  ");
                    if (ps->a->num == tmp->num)
                    {
                        int j = find_place_for_num(ps, tmp->num);
                        int j_cpy = j;
                        while (j--)
                            ps_rb(ps);
                        ps_pb(ps);
                        while (j_cpy--)
                            ps_rrb(ps);//rrb
                    }
                }
                ft_printf("test ");
                print_stk(ps->a, 1);
                print_stk(ps->b, 2);
            }
        }
    }
}