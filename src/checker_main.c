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

#include "checker.h"


/*сесть написать все команды
инициализировать массив или список листов после валидности
валидность каждой команды иначе ошибка
начать выполнять команды
как завершать программу через кнтрл д?
в конце в зависимости от результата получилось или нет вернуть ОК или КО
начать писать сам пушсвап лол*/
/*
void		print_lst(t_lst *head)
{
	while (head)
	{
		ft_printf("%i ", head->num);
		head = head->next;
	}
}
*/
t_stk 		*create_data(t_stk *first, int ac, char **av, int stack)
{
	int i;
	t_stk *head;

	i = 2;
	if(!(first = malloc(sizeof(t_stk))))
		return (NULL);
	if (stack == 1)
		first->num = ft_atoi(av[1]);
	else
		first->num = 0;
	first->next = NULL;
	head = first;
	while (i < ac)
	{

		first->next = malloc(sizeof(t_stk));
		first->next->head = head;
		if (stack == 1)
			first->next->num = ft_atoi(av[i]);
		else
			first->next->num = 0;
		first->next->next = NULL;
		first = first->next;
		i++;
	}
	return (head);
}


int 		check_order(t_stk *first, int ac)
{
	int i;
	t_stk *tmp;

	tmp = first;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (i != ac)
		return (-1);
	else
		while (first && first->next)
		{
			if (first->num > first->next->num)
				return (-1);
			first = first->next;
		}
	return (-1);
}

 void       error_out(void)
{
	ft_printf("error\n");
	exit(1);
}

t_pushswap        *create_stacks(t_pushswap *ps, int ac, char **av)
{
 	if(!(ps = malloc(sizeof(t_pushswap))))
 	    error_out();
 	ps->a = create_data(ps->a, ac, av, 1);
 	ps->b = create_data(ps->b, ac, av, 0);
 	if (!ps->a || !ps->b)
 		error_out();
	ps->quant_nums = ac;
 	ps->a->head = ps->a;
 	ps->b->head = ps->b;
	return (ps);
}

int 		main(int ac, char **av)
{
	int n;
	char buf[50];
	t_pushswap *ps;
	if (ac <= 1)
	{
		ft_printf("no arguments.\n");//DELETE
		exit(1);
	}
	if (check_validity(ac, av) == 1)
	{
		if (!(ps = create_stacks(ps, ac, av)))
			error_out();
		while ((n = read (0, buf, sizeof(buf))) > 1)
		{
			buf[n] = '\0';
			if (check_instructions(buf) != 1)
				error_out();
			else
				execute_instruction(ps, buf);
		}
		if (check_order(ps, ac) == 1)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
		error_out();
	return (0);
}
