/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:51:14 by jslave            #+#    #+#             */
/*   Updated: 2020/02/22 14:51:17 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pushswap.h"

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
	ps->instructions++;//del
    ft_printf("rb\n");
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
	ps->instructions++;//del
    ft_printf("rra\n");
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
    ps->instructions++;//del
    ft_printf("rrb\n");
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
