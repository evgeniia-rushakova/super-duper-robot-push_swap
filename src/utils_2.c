/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:08:41 by jslave            #+#    #+#             */
/*   Updated: 2020/02/22 16:08:43 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		print_stk(t_stk *head, int stack)
{
	if (!head || !head->head)
		ft_printf("Stack %c is empty.\n", stack == 1 ? 'A' : 'B');
	else
	{
		if (stack == 1)
			ft_printf("stack A is: ");
		else if (stack == 2)
			ft_printf("stack B is: ");
		while (head)
		{
			ft_printf("%i ", head->num);
			head = head->next;
		}
		ft_printf("\n");
	}
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
}

int			check_order_simple(t_pushswap *ps, char stack)
{
	t_stk *stk;

	stk = stack == 'a' ? ps->a->head : ps->b->head;
	while (stk)
	{
		if (stk->next)
			if (stk->num > stk->next->num)
				return (-1);
		stk = stk->next;
	}
	return (1);
}

int 			find_steps_before_num(t_stk *stk, char start_end, int quant, int num)
{
	int st;
	t_stk *tmp;

	tmp = stk->head;

	st = 0;
	while (tmp)
	{
		if (tmp->num == num)
			break;
		st++;
		tmp = tmp->next;
	}
	return (start_end == 's' ? st : (quant - st));
}

void			get_minimum_on_top(t_pushswap *ps)
{
	int start_steps;
	int end_steps;

	find_max_min_medium_nums(ps);
	start_steps = find_steps_before_num(ps->a, 's', find_lst_size(ps->a), ps->min);
	end_steps = find_steps_before_num(ps->a, 'e', find_lst_size(ps->a), ps->min);

	if (start_steps == 0 || end_steps == 0)
	{
		if (end_steps == 0)
			ps_rra(ps);
		return;
	}
	if (start_steps < end_steps)
		while (start_steps-- != 0)
			ps_ra(ps);
	else
		while (end_steps-- != 0)
			ps_rra(ps);
}

void			repeat_function(int times,t_pushswap *ps, void (*f)(t_pushswap *))
{
	while (times--)
		(*f)(ps);
}