/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_polish.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:33:17 by yiken             #+#    #+#             */
/*   Updated: 2024/06/14 17:51:21 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void	save_rest(t_list **list, char *ln_str, char *buffer, t_list *new_node)
{
	int	i;
	int	j;

	i = 0;
	if (ln_str[i] == '\0' || ln_str[++i] == '\0')
	{
		free(buffer);
		free(new_node);
		free_lst(list);
		return ;
	}
	j = 0;
	while (ln_str[i])
		buffer[j++] = ln_str[i++];
	buffer[j] = '\0';
	new_node->str = buffer;
	new_node->next = 0;
	free_lst(list);
	*list = new_node;
}

int	adjust_list(t_list **list)
{
	int		i;
	char	*buffer;
	t_list	*new_node;
	t_list	*last_node;

	i = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free(buffer);
		return (0);
	}
	last_node = get_last_node(*list);
	while (last_node->str[i] && last_node->str[i] != '\n')
		i++;
	save_rest(list, last_node->str + i, buffer, new_node);
	return (1);
}
