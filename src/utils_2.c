/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:08:41 by jslave            #+#    #+#             */
/*   Updated: 2020/02/22 16:08:43 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		print_stk(t_stk *head, int stack)
{
	if (!head || !head->head)
		ft_printf("Stack %c is empty.\n", stack == 1 ? 'A' : 'B');
	else
	{
		if (stack == 1)
			ft_printf("stack A is: ");
		else if (stack == 2)
			ft_printf("stack B is: ");
		while (head)
		{
			ft_printf("%i ", head->num);
			head = head->next;
		}
		ft_printf("\n");
	}
}