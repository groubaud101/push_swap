# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 12:21:57 by groubaud          #+#    #+#              #
#    Updated: 2021/06/11 23:24:07 by groubaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST	=	test


NAME	=	push_swap

DIR_L	=	./libft/
DIR_S	=	./

SPUSW	=	$(TEST) push_swap free fill_pusw move_a move_b move_both \
			move location verbose algo algo_below_five algo_below_hundred \
			algo_above_hundred check_a check_b r_or_rr \
			simple_call_a simple_call_b optimize_move

INC_L	=	$(DIR_L)include/
H_INC	=	libft ft_printf get_next_line
INCLUDE	=	$(addprefix $(INC_L), $(addsuffix .h, $(H_INC))) ft_$(NAME).h

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LIB		=	-L $(DIR_S) -lft

SRCS	=	main.c $(addprefix $(DIR_S)ft_, $(addsuffix .c, $(SPUSW)))
OBJS	=	main.o $(addprefix $(DIR_S)ft_, $(addsuffix .o, $(SPUSW)))

## commande

all		:	$(NAME)

%.o		:	%.c $(INCLUDE)
			$(CC) $(CFLAGS) -I$(INC_L) -c -o $@ $<

lib		:
			make -C $(DIR_L) all
			cp $(DIR_L)libft.a ${DIR_S}

$(NAME)	:	$(OBJS) $(INCLUDE)
			make lib
			$(CC) $(CFLAGS) -I$(INC_L) $(OBJS) $(LIB) -o $@

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)
			make -C $(DIR_L) fclean
			rm -rf libft.a

re		:	fclean all			

.PHONY	:	all clean fclean re
