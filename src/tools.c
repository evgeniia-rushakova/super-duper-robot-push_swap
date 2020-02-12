/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:28:41 by jslave            #+#    #+#             */
/*   Updated: 2020/02/11 15:28:43 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
/*
 * При проталкивании (push) добавляется новый элемент, указывающий на элемент,
 * бывший до этого головой. Новый элемент теперь становится головным.
При удалении элемента (pop) убирается первый, а головным становится тот,
 на который был указатель у этого объекта (следующий элемент). При этом значение убранного элемента возвращается.
 */
t_stk            *push(t_stk *head, t_stk *new_head)//vstavit element v golovu spiska
{
	//new_head->head = new_head;
	new_head->next = head;
	new_head->head = new_head;
	/*while (head)
	{
		head->head = new_head;
		head = head->next;
	}*/
	change_head(head, new_head);
	return (new_head);
}

t_stk       *pop(t_stk *head, t_pushswap *ps)//leak?
{
	t_stk *new_head;
	//t_stk *tmp;

	new_head = head->next;
/*	tmp = head;
	while (tmp)
	{
		tmp->head = new_head;
		tmp = tmp->next;
	}*/
	ps->a = new_head;
	head->next = NULL;
	return (head);
}

t_stk       *remove_elem(t_stk *elem)///TEST
{
	t_stk *tmp;

	tmp = elem->head;
	//if (tmp->next)
	//	change_head(tmp->next, tmp);
	while(tmp)
	{
		if (tmp->next == elem)
			break;
		tmp = tmp->next;
	}
	if (tmp && tmp->next && tmp->next->next)
		tmp->next = tmp->next->next;
	elem->next = NULL;
	return (elem);
}

void        change_head(t_stk *stack, t_stk *new_head)
{
	t_stk *tmp;

	tmp = stack;
	if (new_head)
	{
		while (tmp)
		{
			tmp->head = new_head;
			tmp = tmp->next;
		}
	}
}
//поменять функцию изменения головы потому что надо перекидывться элементами из А в Б