/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:10:25 by yiken             #+#    #+#             */
/*   Updated: 2024/06/14 17:41:36 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*generate_line(t_list **list)
{
	int		len_of_line;
	char	*line;

	len_of_line = get_len_of_line(*list);
	if (!len_of_line)
		return (NULL);
	line = malloc(len_of_line + 1);
	if (!line)
		return (free_lst(list), NULL);
	fill_line(*list, line);
	return (line);
}

int	join_list(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free(buffer);
		return (0);
	}
	new_node->str = buffer;
	new_node->next = 0;
	last_node = get_last_node(*list);
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	return (1);
}

int	newline_found(t_list *list)
{
	int	i;

	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

int	create_list(t_list **list, int fd)
{
	char	*buffer;
	int		bytes_read;

	while (!newline_found(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buffer);
			break ;
		}
		if (bytes_read == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[bytes_read] = '\0';
		if (!join_list(list, buffer))
			return (0);
	}
	return (1);
}

char	*gnl(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (!create_list(&list, fd))
		return (free_lst(&list), NULL);
	next_line = generate_line(&list);
	if (!next_line || !adjust_list(&list))
		return (free_lst(&list), NULL);
	return (next_line);
}
