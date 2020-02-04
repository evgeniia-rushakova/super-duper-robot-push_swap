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

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <float.h>
#include <fcntl.h>

typedef struct s_lst
{
	 int				num;
	struct s_lst		*head;
	struct s_lst		*next;
}						t_lst;


int 		check_validity(int ac, char **av);
int 		check_duplicates(int ac, char **av);
int 		check_nums(int ac, char **av);
int 		check_instructions(char *av);
t_lst 		*create_data(t_lst *first, int ac, char **av, int stack);
void		execute_instruction(t_lst *first, t_lst *second, char *cmd);

#endif
