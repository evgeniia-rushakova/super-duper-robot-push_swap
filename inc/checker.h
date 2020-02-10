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


int 		check_validity(int ac, char **av);
int 		check_duplicates(int ac, char **av);
int 		check_nums(int ac, char **av);
int 		check_instructions(char *av);
//t_stk 		*create_data(t_stk *first, int ac, char **av, int stack);
void		execute_instruction(t_pushswap *ps, char *cmd);

#endif
