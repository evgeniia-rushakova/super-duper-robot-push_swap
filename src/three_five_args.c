/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_five_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:11:19 by jslave            #+#    #+#             */
/*   Updated: 2020/02/23 17:11:29 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pushswap.h"

void			sort_three_args(t_pushswap *ps, char stack)
{
	t_stk *sec_num;
	t_stk *third_num;

	sec_num = stack == 'a' ? ps->a->head->next : ps->b->head->next;
	third_num = sec_num->next;
	if (check_order_simple(ps, 'a') == 1)
		return;
	if (ps->a->head->num == ps->min)
	{
		ps_rra(ps);
		ps_sa(ps);
	}
	else if ((third_num->num == ps->min && ps->a->head->num > sec_num->num) || sec_num->num == ps->min)
	{
		ps_sa(ps);
		sort_three_args(ps, 'a');
	}
	else if (third_num->num == ps->min && ps->a->head->num < sec_num->num)//892
		ps_rra(ps);
}

void			sort_five_max_args(t_pushswap *ps)
{
	get_minimum_on_top(ps);
	ps_pb(ps);
	if (ps->quant_nums == 4)
	{
		find_max_min_medium_nums(ps);
		sort_three_args(ps, 'a');
		ps_pa(ps);
	}
	if (ps->quant_nums == 5)
	{
		get_minimum_on_top(ps);
		ps_pb(ps);
		find_max_min_medium_nums(ps);
		sort_three_args(ps, 'a');
		if (ps->b->head->num < ps->b->head->next->num)
			ps_sb(ps);
		repeat_function(2, ps, ps_pa);
	}
}

