/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:07:08 by jslave            #+#    #+#             */
/*   Updated: 2020/02/22 16:07:11 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pushswap.h"

t_stk 		*create_data(t_stk *first, int ac, char **av, char stack)
{
	int i;
	t_stk *head;

	i = 2;
	if(!(first = malloc(sizeof(t_stk))))
		return (NULL);
	if (stack == 'b')
	{
		first->head = NULL;
		first->next = NULL;
		return (first);
	}
	first->head = first;
	first->next = NULL;
	head = first;
	first->num = ft_atoi(av[1]);
	while (i < ac)
	{
		first->next = malloc(sizeof(t_stk));
		first->next->head = head;
		first->next->num = ft_atoi(av[i]);
		first->next->next = NULL;
		first = first->next;
		i++;
	}
	return (head);
}

int 		check_order(t_pushswap *ps)
{
	t_stk *tmp;

	if (!ps->a)
		return (-1);
	tmp = ps->a->head;
	while (tmp && tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (-1);
		tmp = tmp->next;
	}
	if (find_lst_size(ps->a->head) != ps->quant_nums)
		return (-1);
	if (ps->b && (ps->b->head != NULL || ps->b->next != NULL))
		return (-1);
	return (1);
}

t_pushswap        *create_stacks(t_pushswap *ps, int ac, char **av)
{
	if(!(ps = malloc(sizeof(t_pushswap))))
		error_out(ps);
	ps->a = create_data(ps->a, ac, av, 'a');
	ps->b = create_data(ps->b, ac, av, 'b');
	if (!ps->a || !ps->b)
		error_out(ps);
	ps->quant_nums = ac - 1;
	ps->a->head = ps->a;
	ps->max = 0;
	ps->min = 0;
	ps->medium = 0;
	ps->instructions = 0;
	return (ps);
}

void        free_ps(t_pushswap *ps)
{
	t_stk *tmp;

	if (ps)
	{
		while (ps->a)
		{
			tmp = ps->a->next;
			ft_memdel((void **)&ps->a);
			ps->a = tmp;
		}
		ft_memdel((void **)&ps->a);
		while (ps->b)
		{
			tmp = ps->b->next;
			ft_memdel((void **)&ps->b);
			ps->b = tmp;
		}
		ft_memdel((void **)&ps->b);
		ft_memdel((void **)&ps);
	}
}

void       error_out(t_pushswap *ps)
{
	free_ps(ps);
	write(2, "error\n", 7);
	exit(1);
}