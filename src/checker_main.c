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

#include "../inc/checker.h"


/*сесть написать все команды
инициализировать массив или список листов после валидности
валидность каждой команды иначе ошибка
начать выполнять команды
как завершать программу через кнтрл д?
в конце в зависимости от результата получилось или нет вернуть ОК или КО
начать писать сам пушсвап лол*/

void		print_lst(t_lst *head)
{
	while (head)
	{
		printf("%i ", head->num);
		head = head->next;
	}
}

t_lst 		*create_data(t_lst *first, int ac, char **av, int stack)
{
	int i;
	t_lst *head;

	i = 2;
	if(!(first = malloc(sizeof(t_lst))))
		return (NULL);
	if (stack == 1)
		first->num = ft_atoi(av[1]);
	first->next = NULL;
	head = first;
	while (i < ac)
	{

		first->next = malloc(sizeof(t_lst));
		first->next->head = head;
		if (stack == 1)
			first->next->num = ft_atoi(av[i]);
		first->next->next = NULL;
		first = first->next;
		i++;
	}
	return (head);
}

int 		check_order(t_lst *first, int ac)
{
	int i;
	t_lst *tmp;

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

int 		main(int ac, char **av)
{
	int n;
	char buf[100];
	t_lst *first;
	t_lst *second;
	first = NULL;
	second = NULL;
	if (ac <= 1)
	{
		printf("no arguments.\n");//DELETE
		exit(1);
	}
	if (check_validity(ac, av) == 1)
	{
		first = create_data(first, ac, av, 1);
		second = create_data(second, ac, av, 2);
		if (!first || !second)
		{
			printf("error\n");
			exit(1);
		}
		//print_lst(first);
		while ((n = read (0, buf, sizeof(buf))) > 1)//////////////////////here
		{
			buf[n] = '\0';
			if (check_instructions(buf) != 1)
			{
				printf("error\n");
				exit(1);
			}
			else
				execute_instruction(first, second, buf);
		}
		if (check_order(first, ac) == 1)
			printf("OK\n");
		else
			printf("KO\n");
	}
	else
		printf("error\n");
	return (0);
}
