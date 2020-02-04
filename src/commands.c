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

void		ps_sa(t_lst *first, t_lst *second)
{
	(void)first;
	(void)second;
}

void		ps_sb(t_lst *first, t_lst *second)
{
	(void)first;
	(void)second;
}

void		ps_ss(t_lst *first, t_lst *second)
{
	(void)first;
	(void)second;
}

void		ps_pa(t_lst *first, t_lst *second)
{
	(void)first;
	(void)second;
}

void		ps_pb(t_lst *first, t_lst *second)
{
	(void)first;
	(void)second;
}

void		ps_ra(t_lst *first, t_lst *second)
{
	(void)first;
	(void)second;
}

void		ps_rb(t_lst *first, t_lst *second)
{
	(void)first;
	(void)second;
}

void		ps_rr(t_lst *first, t_lst *second)
{
	(void)first;
	(void)second;
}

void		ps_rra(t_lst *first, t_lst *second)
{
	(void)first;
	(void)second;
}

void		ps_rrb(t_lst *first, t_lst *second)
{
	(void)first;
	(void)second;
}

void		ps_rrr(t_lst *first, t_lst *second)
{
	(void)first;
	(void)second;
}

void		execute_instruction(t_lst *first, t_lst *second, char *cmd)
{
	if (ft_strequ(cmd, "sa\n") == 1)
		ps_sa(first, second);
	if (ft_strequ(cmd, "sb\n") == 1)
		ps_sb(first, second);
	if (ft_strequ(cmd, "ss\n") == 1)
		ps_ss(first, second);
	if (ft_strequ(cmd, "pa\n") == 1)
		ps_pa(first, second);
	if (ft_strequ(cmd, "pb\n") == 1)
		ps_pb(first, second);
	if (ft_strequ(cmd, "ra\n") == 1)
		ps_ra(first, second);
	if (ft_strequ(cmd, "rb\n") == 1)
		ps_rb(first, second);
	if (ft_strequ(cmd, "rr\n") == 1)
		ps_rr(first, second);
	if (ft_strequ(cmd, "rra\n") == 1)
		ps_rra(first, second);
	if (ft_strequ(cmd, "rrb\n") == 1)
		ps_rrb(first, second);
	if (ft_strequ(cmd, "rrr\n") == 1)
		ps_rrr(first, second);
}
