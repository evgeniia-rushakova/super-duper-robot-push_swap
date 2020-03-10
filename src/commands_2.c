/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:52:04 by jslave            #+#    #+#             */
/*   Updated: 2020/02/22 15:52:06 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pushswap.h"

void		ps_rrr(t_pushswap *ps, int ps_ch)/* rrr : rra and rrb at the same time. */
{
    ps_rra(ps, 0);
    ps_rrb(ps, 0);
    ps->analyse->instructions++;//del
    ps->analyse->rrr++;
    ps->analyse->rra--;
    ps->analyse->rrb--;
	if (ps_ch)
    	ft_printf("rrr\n");
}

void		ps_rr(t_pushswap *ps, int ps_ch)/* rr : ra and rb at the same time.*/
{
    ps_ra(ps, 0);
    ps_rb(ps, 0);
    ps->analyse->instructions++;//del
    ps->analyse->rr++;
    ps->analyse->ra--;
    ps->analyse->rb--;
	if (ps_ch)
    	ft_printf("rr\n");
}

void		ps_ss(t_pushswap *ps, int ps_ch)/*ss : sa and sb at the same time.*/
{
    ps_sa(ps, 0);
    ps_sb(ps, 0);
    ps->analyse->instructions++;//del
    ps->analyse->ss++;
    ps->analyse->sa--;
    ps->analyse->sb--;
	if (ps_ch)
    	ft_printf("ss\n");
}
