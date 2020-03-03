/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:24:28 by jslave            #+#    #+#             */
/*   Updated: 2020/02/22 16:24:36 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSHSWAP_H
#define PUSHSWAP_H

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

typedef struct          s_analyse
{
    int sa;
    int sb;
    int ss;
    int pa;
    int pb;
    int ra;
    int rb;
    int rr;
    int rra;
    int rrb;
    int rrr;
}                       t_analyse;

typedef struct          s_ps
{
	int                 quant_nums;
	int 				max;
	int					min;
	int					medium;
	t_stk               *a;
	t_stk               *b;
	int 				instructions;//DEL
	t_analyse           *analyse;
	int                 *sorted_arr;
}                       t_pushswap;

/*
 * check_validity.c
 */
int             check_order_args(int ac,char **av);
int             check_validity(int ac, char **av);
int             check_instructions(char *av);
int				check_nums(int ac, char **av);
int				check_duplicates(int ac, char **av);
/*
 * commands.c
 */
void			ps_sa(t_pushswap *ps);
void			ps_sb(t_pushswap *ps);
void			ps_pa(t_pushswap *ps);
void			ps_pb(t_pushswap *ps);
void			ps_ra(t_pushswap *ps);
/*
 * coomands_2.c
 */
void			ps_rr(t_pushswap *ps);
void			ps_rrr(t_pushswap *ps);
void			ps_ss(t_pushswap *ps);
/*
 * execute_instructions.c
 */
void        	execute_instruction(t_pushswap *ps, char *cmd);
void			ps_rrb(t_pushswap *ps);
void			ps_rra(t_pushswap *ps);
void			ps_rb(t_pushswap *ps);
/*
 * utils_1.c
 */
t_stk           *create_data(t_stk *first, int ac, char **av, char stack);
int             check_order(t_pushswap *ps);
void            error_out(t_pushswap *ps);
t_pushswap      *create_stacks(t_pushswap *ps, int ac, char **av);
void			free_ps(t_pushswap *ps);
/*
 * utils_2.c
 */
void			print_stk(t_stk *head, int stack);//del
void			find_max_min_medium_nums(t_pushswap *ps);
int				check_order_simple(t_pushswap *ps, char stack);
int				check_order_simple_rev(t_pushswap *ps, char stack);
int				find_steps_before_num(t_stk *stk, char start_end, int quant, int num);
void			get_minimum_on_top(t_pushswap *ps);
void			repeat_function(int times,t_pushswap *ps, void (*f)(t_pushswap *));
/*
 * lst_tools.c
 */
t_stk           *push(t_stk *head, t_stk *new_head);
//t_stk           *pop(t_stk *head, t_pushswap *ps);
t_stk           *remove_elem(t_stk *elem);
void            change_head(t_stk *stack, t_stk *new_head);
t_stk           *append_elem(t_stk *stack, t_stk *elem);
int             find_lst_size(t_stk *head);
/*
 * three_five_args.c
 */
void			sort_three_args(t_pushswap *ps, char stack);
void			sort_five_max_args(t_pushswap *ps);

void            print_analyse(t_pushswap *ps);

/*
 * solution.c
 */
int             is_num_smaller_than_others(t_stk *stk, int num);
int             is_num_bigger_than_others(t_stk *stk, int num);
int             find_holding_numbers2(int min, int max, int param, int counter);
int             is_nums_in_chunk_is_empty(t_pushswap *ps, int counter);
int             find_place_for_num(t_pushswap *ps, int num);
int             find_quant_nums_in_chunk(t_pushswap *ps, int counter);
int             check_the_nearest_num_in_chunk(t_pushswap *ps, int counter, char opt);

void            sort_hundred_max_args_4(t_pushswap *ps);
void            sort_hundred_max_args_3(t_pushswap *ps);
void            sort_hundred_max_args_2(t_pushswap *ps);
void            sort_hundred_max_args_1(t_pushswap *ps);
void			push_swap(t_pushswap *ps);
/*
 * sorted_array.c
 */
int         create_sorted_array(t_pushswap *ps);


#endif
