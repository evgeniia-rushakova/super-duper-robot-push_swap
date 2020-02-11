/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:38:55 by jslave            #+#    #+#             */
/*   Updated: 2020/02/04 19:39:01 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ps_sa(t_pushswap *ps)/*sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
		is only one or no elements).*/
{
	t_stk *tmp;

	if (ps->a->next)
	{
		tmp = remove_elem(ps->a->next);
		ps->a = push(ps->a, tmp);
	}
	ft_printf("After SA:\n");
	print_stk(ps->a,1);
	print_stk(ps->b, 2);
}

void		ps_sb(t_pushswap *ps)/*sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
		is only one or no elements).*/
{
	t_stk *tmp;

	if (ps->b->next)
	{
		tmp = remove_elem(ps->b->next);
		ps->a = push(ps->b, tmp);
	}
	ft_printf("After SB:\n");
	print_stk(ps->a,1);
	print_stk(ps->b, 2);

}

void		ps_ss(t_pushswap *ps)/*ss : sa and sb at the same time.*/
{
	ps_sa(ps);
	ps_sb(ps);
	ft_printf("After SS:\n");
	print_stk(ps->a,1);
	print_stk(ps->b, 2);
}

void		ps_pa(t_pushswap *ps)/* pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty. */
{
	t_stk *tmp;
}

void		ps_pb(t_pushswap *ps)/* pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.*/
{
	(void)ps;
}

void		ps_ra(t_pushswap *ps)/*ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.  */
{
	(void)ps;
}

void		ps_rb(t_pushswap *ps)/*rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one. */
{
	(void)ps;
}

void		ps_rr(t_pushswap *ps)/* rr : ra and rb at the same time.*/
{
	(void)ps;
}

void		ps_rra(t_pushswap *ps)/*rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one. */
{
	(void)ps;
}

void		ps_rrb(t_pushswap *ps)/*rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one. */
{
	(void)ps;
}

void		ps_rrr(t_pushswap *ps)/* rrr : rra and rrb at the same time. */
{
	(void)ps;
}

void		execute_instruction(t_pushswap *ps, char *cmd)
{
	ft_printf("before:\n");
	print_stk(ps->a,1);
	print_stk(ps->b, 2);

	if (ft_strequ(cmd, "sa\n") == 1)
		ps_sa(ps);
	if (ft_strequ(cmd, "sb\n") == 1)
		ps_sb(ps);
	if (ft_strequ(cmd, "ss\n") == 1)
		ps_ss(ps);
	if (ft_strequ(cmd, "pa\n") == 1)
		ps_pa(ps);
	if (ft_strequ(cmd, "pb\n") == 1)
		ps_pb(ps);
	if (ft_strequ(cmd, "ra\n") == 1)
		ps_ra(ps);
	if (ft_strequ(cmd, "rb\n") == 1)
		ps_rb(ps);
	if (ft_strequ(cmd, "rr\n") == 1)
		ps_rr(ps);
	if (ft_strequ(cmd, "rra\n") == 1)
		ps_rra(ps);
	if (ft_strequ(cmd, "rrb\n") == 1)
		ps_rrb(ps);
	if (ft_strequ(cmd, "rrr\n") == 1)
		ps_rrr(ps);
}
