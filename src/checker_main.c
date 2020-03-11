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
	char **str_av;
	char *line;
	line = NULL;


	t_pushswap *ps;

	ps = NULL;
	if (ac <= 1)
		exit(1);

	if (ac == 2)
	{
		str_av = parse_string_arg(av[1]);
		if (!str_av || check_validity(find_2d_arr_size(str_av), str_av, 0) != 1 || !(ps = create_stacks(find_2d_arr_size(str_av), str_av, "str")))
			error_out(ps);
		memfree(str_av, find_2d_arr_size(str_av));
	}
	else
		if (check_validity(ac, av, 1) != 1 ||  !(ps = create_stacks(ac, av, NULL)))
			error_out(ps);
	while (get_next_line(0, &line))
	{
		//ft_printf("LINE: %s\n", line);
		/*if (check_instructions(line) != 1)
		{

			error_out(ps);
		}
		else*/
		execute_instruction(ps, line, 1);
		free(line);
	}

	if (check_order(ps) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_ps(ps);
	return (0);
}