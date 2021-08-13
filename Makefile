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

NAME	=	push_swap

DIR_L	=	./libft/
DIR_S	=	./

SCOMMON	=	fill_pusw move_a move_b move_both split_pusw \
			location free move check_error

SPUSW	=	$(SCOMMON) push_swap verbose algo algo_below_five \
			algo_below_hundred algo_above_hundred can_insert \
			ra_or_rra ra_or_rra_pa ra_or_rra_chunk rb_or_rrb_restack \
			check_b simple_call_a simple_call_b optimize_move

INC_L	=	$(DIR_L)include/
H_INC	=	libft ft_printf get_next_line
INCLUDE	=	$(addprefix $(INC_L), $(addsuffix .h, $(H_INC))) ft_$(NAME).h

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LIB		=	-L $(DIR_S) -lft

SRCS_PS	=	main.c $(addprefix $(DIR_S)ft_, $(addsuffix .c, $(SPUSW)))
OBJS_PS	=	main.o $(addprefix $(DIR_S)ft_, $(addsuffix .o, $(SPUSW)))

## commande

all		:	$(NAME)

%.o		:	%.c $(INCLUDE)
			$(CC) $(CFLAGS) -I$(INC_L) -c -o $@ $<

lib		:
			make -C $(DIR_L) all
			cp $(DIR_L)libft.a ${DIR_S}

$(NAME)	:	$(OBJS_PS) $(INCLUDE)
			make lib
			$(CC) $(CFLAGS) -I$(INC_L) $(OBJS_PS) $(LIB) -o $@

clean	:
			rm -rf $(OBJS_PS)

fclean	:	clean
			rm -rf $(NAME)
			make -C $(DIR_L) fclean
			rm -rf libft.a

re		:	fclean all			

.PHONY	:	all clean fclean re
