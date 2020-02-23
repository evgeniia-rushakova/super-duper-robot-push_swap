/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:41:40 by jslave            #+#    #+#             */
/*   Updated: 2020/02/22 13:41:46 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
/*
 * 3  числа от 2 до 3 инструкций
 * 5 чисел не больше 12
 * 100 чисел :
 * -меньше 700 оценка 5
 * -меньше 900 оценка 4
 * меньше 1100 оценка 3
 * меньше 1300 оценка 2
 * меньше 1500 оценка 1
 *
 * 500 чисел :
 * -меньше 5500 оценка 5
 * -меньше 7000 оценка 4
 * меньше 8500 оценка 3
 * меньше 10000 оценка 2
 * меньше 11500 оценка 1
 */


int 		main(int ac, char **av)
{
//	int n;
//	char buf[50];
	t_pushswap *ps;

	ps = NULL;
	if (ac <= 1)
		exit(1);
	if (check_validity(ac, av) == 1)
	{
		if (!(ps = create_stacks(ps, ac, av)))
			error_out(ps);
		/*while ((n = read (0, buf, sizeof(buf))) > 1)
		{
			buf[n] = '\0';
			if (check_instructions(buf) != 1)
				error_out(ps);
			else
				execute_instruction(ps, buf);
		}
		if (check_order(ps) == 1)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");*/
		push_swap(ps);
		free_ps(ps);
	}
	else
		error_out(ps);
	return (0);
}