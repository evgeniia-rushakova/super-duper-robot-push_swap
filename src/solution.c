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

void			sort_three_args(t_pushswap *ps)
{
	(void)ps;
}

void			find_max_min_medium_nums(t_pushswap *ps)
{
	int min;
	int max;
	t_stk *tmp;

	tmp = ps->a->head;
	min = tmp->num;
	while (tmp && tmp->next)
	{
		if (min > tmp->next->num)
			min = tmp->next->num;
		tmp = tmp->next;
	}
	tmp = ps->a->head;
	max = tmp->num;
	while (tmp && tmp->next)
	{
		if (max < tmp->next->num)
			max = tmp->next->num;
		tmp = tmp->next;
	}
	ps->max = max;
	ps->min = min;
	ps->medium = (int)(ps->min + (ps->max - ps->min)/2);

	ft_printf("min num in row is %i\n", ps->min);
	ft_printf("max num in row is %i\n", ps->max);
	ft_printf("medium num in row is %i\n", ps->medium);
}

void			push_swap(t_pushswap *ps)
{
	find_max_min_medium_nums(ps);
	if (ps->quant_nums <= 3)
		sort_three_args(ps);
}

