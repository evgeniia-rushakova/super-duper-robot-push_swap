/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:40:44 by jslave            #+#    #+#             */
/*   Updated: 2020/02/03 15:40:46 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int 		main(int ac, char **av)
{
	int n;
	char buf[50];
	t_pushswap *ps;

	ps = NULL;
	if (ac <= 1)
		exit(1);
	if (check_validity(ac, av) == 1)
	{
		if (!(ps = create_stacks(ps, ac, av)))
			error_out(ps);
		while ((n = read (0, buf, sizeof(buf))) > 1)
		{
			buf[n] = '\0';
			if (check_instructions(buf) != 1)
				error_out(ps);
			else
				execute_instruction(ps, buf, 0);
		}
		if (check_order(ps) == 1)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_ps(ps);
	}
	else
		error_out(ps);
	return (0);
}