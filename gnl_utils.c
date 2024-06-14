/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:32:59 by yiken             #+#    #+#             */
/*   Updated: 2024/06/14 17:38:25 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void	free_lst(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str);
		free(*list);
		*list = tmp;
	}
	*list = 0;
}

void	fill_line(t_list *list, char *line)
{
	int	i;
	int	j;

	j = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				line[j++] = list->str[i];
				line[j] = '\0';
				return ;
			}
			line[j++] = list->str[i++];
		}
		list = list->next;
	}
	line[j] = '\0';
}

t_list	*get_last_node(t_list *list)
{
	if (!list)
		return (0);
	while (list->next)
		list = list->next;
	return (list);
}

int	get_len_of_line(t_list *list)
{
	int	i;
	int	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				len++;
				return (len);
			}
			len++;
			i++;
		}
		list = list->next;
	}
	return (len);
}
