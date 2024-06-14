/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:36:41 by yiken             #+#    #+#             */
/*   Updated: 2024/06/14 17:32:00 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;
t_list	*get_last_node(t_list *list);
int		get_len_of_line(t_list *list);
void	fill_line(t_list *list, char *line);
int		adjust_list(t_list **list);
char	*gnl(int fd);
void	free_lst(t_list **list);

#endif
