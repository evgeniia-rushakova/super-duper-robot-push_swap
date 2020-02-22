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

#include "pushswap.h"

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
			{
            	ft_memdel((void **)&ps->a);
				ps->a = tmp;
			}
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
			{
				ft_memdel((void **)&ps->b);
				ps->b = tmp;
			}
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
