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

static void		handle_string_arg(int ac, char **av, t_pushswap **ps)
{
	char **str_av;
	int arr_size;

	str_av = parse_string_arg(av[1]);
	arr_size = find_2d_arr_size(str_av);
	if (!str_av || check_validity(arr_size, str_av, 0) != 1 ||
		!(*ps = create_stacks(arr_size, str_av, "str")))
		error_out(*ps);
	push_swap(*ps);
	memfree(str_av, find_2d_arr_size(str_av));
	free_ps(*ps);
}

int 		main(int ac, char **av)
{
	t_pushswap *ps;

	ps = NULL;
	if (ac <= 1)
		exit(1);
	if (ac == 2)
		handle_string_arg(ac, av, &ps);
	else if (check_validity(ac, av, 1) == 1)
	{
		if (!(ps = create_stacks(ac, av, NULL)))
			error_out(ps);
		push_swap(ps);
		free_ps(ps);
	}
	else
		error_out(ps);
	return (0);
}
