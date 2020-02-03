/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:53:11 by jslave            #+#    #+#             */
/*   Updated: 2020/02/03 16:53:13 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int 		check_duplicates(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int 		check_nums(int ac, char **av)
{
	int i;
	int j;
	long long int num;

	i = 1;
	while (i < ac)
	{
		num = ft_atoi_long_long_uns(av[i]);
		if (num > INT_MAX || num < INT8_MIN)
			return (0);
		j = 0;
		while (av[i][j] != '\0')
		{
			if (ft_isdigit(av[i][j]) != 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int 		check_instructions(int ac, char **av)
{
	int i;
	char **commands;
	int j;

	commands = (char *[11]){"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrb"};
	j = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (j < 11)
		{
			if (ft_strequ(commands[j], av[i]) != 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int 		check_validity(int ac, char **av)
{
	if (check_nums(ac, av) == 0)
		return (0);
	if (check_duplicates(ac, av) == 0)
		return (0);
/*	if (check_instructions(ac, av) == 0)
		return (0);*/
	return (1);
}
