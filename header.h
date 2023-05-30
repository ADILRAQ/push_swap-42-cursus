/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:32:41 by araqioui          #+#    #+#             */
/*   Updated: 2022/12/29 16:45:11 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	struct s_list	*prev;
	int				data;
	struct s_list	*lis;
	int				mov[3];
	int				length;
	int				indice;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str, t_list **top);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_swap(t_list **lst);
void	ft_rotate(t_list **top);
void	ft_reverse_rotate(t_list **top);
void	ft_push(t_list **lst1, t_list **lst2);
void	marking_long_incr_list(t_list **stack_a, t_list **stack_b);
void	ft_moves(t_list **stack_a, t_list **stack_b);
void	ft_update_indices(t_list **lst);
void	ft_sorting(t_list **stack_a, t_list **stack_b);
int		ft_check_sort(t_list *lst);
void	ft_rotate_min_stk_a(t_list **stack_a, t_list *min);
int		ft_check_digit(char **str);
t_list	*ft_split_digit(char **str);

t_list	*ft_minimum(t_list *lst);
t_list	*ft_maximum(t_list *lst);
t_list	*ft_minimum_mov(t_list *lst);

void	ft_case_2_nb(t_list **stack_a);
void	ft_case_3_nb(t_list **stack_a);
void	ft_case_4_nb(t_list **stack_a, t_list **stack_b);
void	ft_case_5_nb(t_list **stack_a, t_list **stack_b);

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *s1);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t len);
int		ft_strcmp(const char *s1, const char *s2);

void	ft_double_swap(t_list **stack_a, t_list **stack_b);
void	ft_double_rotate(t_list **stack_a, t_list **stack_b);
void	ft_double_reverse_rotate(t_list **stack_a, t_list **stack_b);

#endif