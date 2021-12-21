# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 00:17:39 by jeounpar          #+#    #+#              #
#    Updated: 2021/11/17 00:17:41 by jeounpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a
INCS = .

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	ft_printf_format.c \
	ft_printf_utils.c \
	ft_printf_pointer.c

OBJS	= $(SRCS:.c=.o)

.c.o :
	gcc $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
	ar rcs $(NAME) $(OBJS)

bonus :

all : $(NAME)

clean :
	make -C $(LIBFTDIR) clean
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re : clean all

.PHONY : all clean fclean re bonus
