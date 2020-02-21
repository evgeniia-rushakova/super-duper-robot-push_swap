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

	if (ps->a && ps->a->head)
	{
        if ((tmp = remove_elem(ps->a->head->next)))
            ps->a = push(ps->a->head, tmp);
        if (ps->a)
        {
            ps->a->head = ps->a;
            change_head(ps->a->head, ps->a);
        }
    }
	ft_printf("SA:\n");
}

void		ps_sb(t_pushswap *ps)/*sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
		is only one or no elements).*/
{
	t_stk *tmp;

	if (ps->b && ps->b->head)///dobavit uslovie na 1 element
	{
		if ((tmp = remove_elem(ps->b->head->next)))
			ps->b = push(ps->b->head, tmp);
        if(ps->b)
        {
            ps->b->head = ps->b;
            change_head(ps->b->head, ps->b);
        }
	}
	ft_printf("SB:\n");

}

void		ps_ss(t_pushswap *ps)/*ss : sa and sb at the same time.*/
{
	ps_sa(ps);
	ps_sb(ps);

	ft_printf("SS:\n");
}

void		ps_pa(t_pushswap *ps)/* pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty. */
{
    t_stk *tmp;
    t_stk *head_tmp;

    if (ps->b && ps->b->head)
    {
        head_tmp = ps->b->head->next;
        if ((tmp = remove_elem(ps->b->head)))
        {
            ps->b = head_tmp;
            if (ps->a && ps->a->head)
                ps->a = push(ps->a, tmp);
            else
                ps->a = tmp;
        }
        if (ps->a)
        {
            ps->a->head = ps->a;
            change_head(ps->a->head, ps->a);
        }
        if(ps->b)
        {
            ps->b->head = ps->b;
            change_head(ps->b->head, ps->b);
        }
    }
	ft_printf("PA:\n");
}

void		ps_pb(t_pushswap *ps)/* pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.*/
{
	t_stk *tmp;
	t_stk *head_tmp;

	if (ps->a && ps->a->head)
	{
		head_tmp = ps->a->head->next;
		if ((tmp = remove_elem(ps->a->head)))
		{
            ps->a = head_tmp;
			if (ps->b && ps->b->head)
			    ps->b = push(ps->b, tmp);
			else
                ps->b = tmp;
		}
        if (ps->a)
        {
            ps->a->head = ps->a;
            change_head(ps->a->head, ps->a);
        }
        if(ps->b)
        {
            ps->b->head = ps->b;
            change_head(ps->b->head, ps->b);
        }
	}
	ft_printf("PB:\n");
}

void		ps_ra(t_pushswap *ps)/*ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.  */
{
    t_stk *tmp;
    t_stk *head_tmp;

    if (ps->a && ps->a->head)
    {
        head_tmp = ps->a->head->next;
        if ((tmp = remove_elem(ps->a->head)))
        {
            ps->a = head_tmp;
            if (ps->a)
            {
                ps->a->head = ps->a;
                change_head(ps->a->head, ps->a);
            }
            append_elem(ps->a, tmp);
        }
    }
    ft_printf("RA:\n");
}

void		ps_rb(t_pushswap *ps)/*rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one. */
{
    t_stk *tmp;
    t_stk *head_tmp;

    if (ps->b && ps->b->head)
    {
        head_tmp = ps->b->head->next;
        if ((tmp = remove_elem(ps->b->head)))
        {
            ps->b = head_tmp;
            if (ps->b)
            {
                ps->b->head = ps->b;
                change_head(ps->b->head, ps->b);
            }
            append_elem(ps->b, tmp);
        }
    }
    ft_printf("RB:\n");
}

void		ps_rr(t_pushswap *ps)/* rr : ra and rb at the same time.*/
{
	ps_ra(ps);
	ps_rb(ps);
    ft_printf("RR:\n");
}

void		ps_rra(t_pushswap *ps)/*rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one. */
{
	t_stk *tmp;

	if (ps->a && ps->a->head && ps->a->head->next)
    {
        tmp = ps->a->head;
        while (tmp && tmp->next)
            tmp = tmp->next;
        if ((tmp = remove_elem(tmp)))
        {
            ps->a = push(ps->a, tmp);
            change_head(ps->a->head, ps->a);
        }
    }
    ft_printf("RRA:\n");
}

void		ps_rrb(t_pushswap *ps)/*rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one. */
{
    t_stk *tmp;

    if (ps->b && ps->b->head && ps->b->head->next)
    {
        tmp = ps->b->head;
        while (tmp && tmp->next)
            tmp = tmp->next;
        if ((tmp = remove_elem(tmp)))
        {
            ps->b = push(ps->b, tmp);
            change_head(ps->b->head, ps->b);
        }
    }
    ft_printf("RRB:\n");
}

void		ps_rrr(t_pushswap *ps)/* rrr : rra and rrb at the same time. */
{
	ps_rra(ps);
	ps_rrb(ps);
    ft_printf("RRR:\n");
}

void		execute_instruction(t_pushswap *ps, char *cmd)
{
    write(1, "\x1b[32m", 5);
    ft_printf("before:\n");
    print_stk(ps->a,1);
    print_stk(ps->b, 2);
    write(1, "\x1b[0m", 5);

	if (ft_strequ(cmd, "sa\n") == 1)
		ps_sa(ps);
	else if (ft_strequ(cmd, "sb\n") == 1)
		ps_sb(ps);
	else if (ft_strequ(cmd, "ss\n") == 1)
		ps_ss(ps);
	else if (ft_strequ(cmd, "pa\n") == 1)
		ps_pa(ps);
	else if (ft_strequ(cmd, "pb\n") == 1)
		ps_pb(ps);
	else if (ft_strequ(cmd, "ra\n") == 1)
		ps_ra(ps);
	else if (ft_strequ(cmd, "rb\n") == 1)
		ps_rb(ps);
	else if (ft_strequ(cmd, "rr\n") == 1)
		ps_rr(ps);
	else if (ft_strequ(cmd, "rra\n") == 1)
		ps_rra(ps);
	else if (ft_strequ(cmd, "rrb\n") == 1)
		ps_rrb(ps);
	else if (ft_strequ(cmd, "rrr\n") == 1)
		ps_rrr(ps);
	write(1, "\x1b[31m", 5);

    ft_printf("after:\n");
    print_stk(ps->a,1);
    print_stk(ps->b, 2);
   write(1, "\x1b[0m", 5);
}
