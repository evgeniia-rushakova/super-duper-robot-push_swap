/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:43:32 by jslave            #+#    #+#             */
/*   Updated: 2020/02/03 15:43:40 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

# include "libft.h"
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <float.h>
#include <fcntl.h>

typedef struct          s_stk
{
	int                 num;
	struct s_stk        *head;
	struct s_stk        *next;
}                       t_stk;

typedef struct          s_ps
{
	int                 quant_nums;
	t_stk               *a;
	t_stk               *b;
}                       t_pushswap;

int             check_order_args(int ac,char **av);
t_stk           *create_data(t_stk *first, int ac, char **av, char stack);
int             check_order(t_pushswap *ps);
void            error_out(void);
t_pushswap      *create_stacks(t_pushswap *ps, int ac, char **av);
int             main(int ac, char **av);
int             check_validity(int ac, char **av);
int             check_instructions(char *av);
void            execute_instruction(t_pushswap *ps, char *cmd);
void            print_stk(t_stk *head, int stack);

/*
 * tools.c
 */
t_stk           *push(t_stk *head, t_stk *new_head);
t_stk           *pop(t_stk *head, t_pushswap *ps);
t_stk           *remove_elem(t_stk *elem);
void            change_head(t_stk *stack, t_stk *new_head);
t_stk           *append_elem(t_stk *stack, t_stk *elem);
int             find_lst_size(t_stk *head);
#endif
