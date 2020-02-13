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
	tmp = ps->a->head;
	while (tmp && tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (-1);
		tmp = tmp->next;
	}
	if (ps->b->head)
		return (-1);
	return (1);
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
 	ps->a = create_data(ps->a, ac, av, 'a');
 	ps->b = create_data(ps->b, ac, av, 'b');
 	if (!ps->a)
 		error_out();
	ps->quant_nums = ac;
 	ps->a->head = ps->a;
	return (ps);
}

int 		main(int ac, char **av)
{
	int n;
	char buf[50];
	t_pushswap *ps;

	ps = NULL;
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
		if (check_order(ps) == 1)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
		error_out();
	return (0);
}
//////////ошибки через врайт 2