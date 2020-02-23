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

void			sort_hundred_max_args(t_pushswap *ps)
{
	int i;
	t_stk *tmp;

	i = ps->quant_nums;
	ft_printf("quant nums is: %i\n", ps->quant_nums);
	while (ps->a && i)
	{
		if (ps->a->num < ps->medium)
		{

			ps_pb(ps);

		}
		else
			ps_ra(ps);
		ps->a= ps->a->next;
		i--;
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
		sort_hundred_max_args(ps);
	ft_printf("\n-----------\nafter:\n");
	print_stk(ps->a,1);
	print_stk(ps->b, 2);
	ft_printf("INSTRUCTIONS: %i\n", ps->instructions);
	if (check_order(ps) == 1)
		ft_printf("****OK****\n");
	else
		ft_printf("****KO****\n");
}

