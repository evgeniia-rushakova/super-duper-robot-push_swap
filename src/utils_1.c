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

char        **parse_string_arg(char *str)
{
	char **res;

	res = ft_strsplit(str, ' ');
	return (res);
}

int         find_2d_arr_size(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

t_stk 		*create_data(int ac, char **av, char stack, char *param)
{
	int i;
	t_stk *head;
	t_stk *first;

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
	i = param == NULL ? 2 : 1;
	first->num = ft_atoi(av[i - 1]);
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
	/*if (ps->b && (ps->b->head != NULL || ps->b->next != NULL))
		return (-1);*/
	return (1);
}

t_pushswap        *create_stacks(int ac, char **av, char *param)
{
	t_pushswap *ps;

	if(!(ps = malloc(sizeof(t_pushswap))))
		error_out(ps);
	ps->b = create_data(ac, av, 'b', param);
	ps->max = 0;
	ps->min = 0;
////////////////////////////////////////////
	if (!(ps->analyse = malloc(sizeof(t_analyse))))
		error_out(ps);//add free for analyse
	ps->analyse->sa = 0;
	ps->analyse->sb = 0;
	ps->analyse->ss = 0;
	ps->analyse->pa = 0;
	ps->analyse->pb = 0;
	ps->analyse->ra = 0;
	ps->analyse->rb = 0;
	ps->analyse->rr = 0;
	ps->analyse->rra = 0;
	ps->analyse->rrb = 0;
	ps->analyse->rrr = 0;
	ps->analyse->instructions = 0;
	////////////////////////////////////
	ps->a = create_data(ac, av, 'a', param);
	if (!ps->a || !ps->b)
		error_out(ps);
	ps->quant_nums = param == NULL ? ac - 1 : ac;
	ps->a->head = ps->a;
    if (create_sorted_array(ps) != 1)
    	error_out(ps);

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
        if (ps->analyse->sorted_arr)
            ft_memdel((void **)&ps->analyse->sorted_arr);
		if (ps->analyse)
			ft_memdel((void **)&ps->analyse);
		ft_memdel((void **)&ps->b);
		ft_memdel((void **)&ps);
	}

}

void       error_out(t_pushswap *ps)
{
	free_ps(ps);
	write(2, "Error\n", 7);
	exit(1);
}