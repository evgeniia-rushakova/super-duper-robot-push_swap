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
    ps_rra(ps, ps_ch);
    ps_rrb(ps, ps_ch);
    ps->analyse->instructions++;//del
    ps->analyse->rrr++;
    ps->analyse->rra--;
    ps->analyse->rrb--;
	if (ps_ch)
    	ft_printf("rrr\n");
}

void		ps_rr(t_pushswap *ps, int ps_ch)/* rr : ra and rb at the same time.*/
{
    ps_ra(ps, ps_ch);
    ps_rb(ps, ps_ch);
    ps->analyse->instructions++;//del
    ps->analyse->rb++;
    ps->analyse->ra--;
    ps->analyse->rb--;
	if (ps_ch)
    	ft_printf("rb\n");
}

void		ps_ss(t_pushswap *ps, int ps_ch)/*ss : sa and sb at the same time.*/
{
    ps_sa(ps, ps_ch);
    ps_sb(ps, ps_ch);
    ps->analyse->instructions++;//del
    ps->analyse->ss++;
    ps->analyse->sa--;
    ps->analyse->sb--;
	if (ps_ch)
    	ft_printf("ss\n");
}
