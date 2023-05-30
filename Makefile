# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 15:22:31 by araqioui          #+#    #+#              #
#    Updated: 2022/12/29 20:55:09 by araqioui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
HEADER = header.h

SRC = ft_moves ft_push ft_reverse_rotate ft_rotate ft_sorting ft_swap ft_update_indices LongestIncreasingList main \
		libft/ft_atoi libft/ft_lstadd_back libft/ft_lstclear libft/ft_lstnew libft/ft_lstsize libft/ft_lstlast \
		ft_small_cases ft_check_sort ft_max_min ft_min_rotate ft_error

B_SRC = ft_error ft_check_sort ft_push ft_reverse_rotate ft_rotate ft_swap \
		Bonus/ft_double_actions Bonus/ft_strcmp Bonus/get_next_line Bonus/get_next_line_utils \
		Bonus/main libft/ft_atoi libft/ft_lstadd_back libft/ft_lstclear libft/ft_lstlast libft/ft_lstnew

OBJ = $(SRC:=.o)
B_OBJ = $(B_SRC:=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(B_OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(B_OBJ) -o $(CHECKER)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ) $(B_OBJ)

fclean: clean
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re
