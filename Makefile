# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jslave <jslave@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 21:32:49 by jslave            #+#    #+#              #
#    Updated: 2019/11/19 17:38:22 by jslave           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME1 = checker

NAME2 = push_swap

LIBFT = libft

LIBFT_INCLUDES = libft/includes

INCLUDES = inc/

FLAGS =  -Wall -Wextra -Werror

SRC1 = src/check_validity.c src/checker_main.c src/commands.c src/commands_2.c src/lst_tools.c src/utils_1.c src/utils_2.c src/execute_instructions.c src/sorted_array.c

SRC2 = src/check_validity.c src/pushswap_main.c src/commands.c src/commands_2.c src/lst_tools.c src/utils_1.c src/utils_2.c src/solution.c src/execute_instructions.c src/three_five_args.c src/sorted_array.c

OUT1 = $(SRC1:%.c=%.o)

OUT2 = $(SRC2:%.c=%.o)

all: $(NAME1) $(NAME2)

$(NAME1): $(OUT1)
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME1) $(OUT1) -L $(LIBFT) -lft
%.o: %.c
	gcc $(FLAGS) -I $(LIBFT_INCLUDES) -I $(INCLUDES) -o $@ -c $<

$(NAME2): $(OUT2)
	gcc $(FLAGS) -o $(NAME2) $(OUT2) -L $(LIBFT) -lft
%.o: %.c
	gcc $(FLAGS) -I $(LIBFT_INCLUDES) -I $(INCLUDES) -o $@ -c $<

clean:
	/bin/rm -f $(OUT1)
	/bin/rm -f $(OUT2)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME1)
	/bin/rm -f $(NAME2)
	make -C $(LIBFT) fclean

re: fclean all
