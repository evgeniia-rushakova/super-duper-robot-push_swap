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

void		ps_rrr(t_pushswap *ps)/* rrr : rra and rrb at the same time. */
{
    ps_rra(ps);
    ps_rrb(ps);
	ps->instructions++;//del
    ps->analyse->rrr++;
    ft_printf("rrr\n");
}

void		ps_rr(t_pushswap *ps)/* rr : ra and rb at the same time.*/
{
    ps_ra(ps);
    ps_rb(ps);
	ps->instructions++;//del
    ps->analyse->rb++;
    ft_printf("rb\n");
}

void		ps_ss(t_pushswap *ps)/*ss : sa and sb at the same time.*/
{
    ps_sa(ps);
    ps_sb(ps);
	ps->instructions++;//del
    ps->analyse->ss++;
    ft_printf("ss\n");
}
