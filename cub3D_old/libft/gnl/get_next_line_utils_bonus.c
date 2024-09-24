/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:37:15 by mremenar          #+#    #+#             */
/*   Updated: 2023/11/13 10:39:35 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	verif(t_line **root, int fd)
{
	int		n_read;
	t_line	*curr;

	curr = *root;
	while (curr)
	{
		if (curr->id_fd == fd)
			break ;
		curr = curr->next;
	}
	n_read = read(fd, 0, 0);
	if (fd < 0 || BUFFER_SIZE <= 0 || n_read < 0)
	{
		if (n_read < 0 && curr)
			free_list(root, fd);
		return (0);
	}
	return (1);
}

t_line	*gnl_add_new(t_line **lst, int fd)
{
	t_line	*curr;
	t_line	*new_node;

	new_node = (t_line *)malloc(sizeof(t_line));
	if (!new_node)
		return (NULL);
	new_node->id_fd = fd;
	new_node->next = NULL;
	new_node->line = malloc(4096 + BUFFER_SIZE);
	if (!(new_node->line))
	{
		free(new_node);
		return (NULL);
	}
	new_node->line[0] = 0;
	if (!(*lst))
	{
		*lst = new_node;
		return (new_node);
	}
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
	return (curr->next);
}

void	gnl_strlcat(char **dst, char *src)
{
	int		i;
	int		j;
	char	*tmp_dst;

	i = gnl_len(*dst, '\0') + gnl_len(src, '\0') + 1;
	j = (gnl_len(*dst, '\0') / 4096);
	if (i > (j * 4096) && j > 0)
	{
		tmp_dst = malloc((((i / 4096) + 1) * 4096) + BUFFER_SIZE);
		if (!tmp_dst)
			return ;
		i = -1;
		while ((*dst)[++i])
			tmp_dst[i] = (*dst)[i];
		tmp_dst[i] = 0;
		free(*dst);
		*dst = tmp_dst;
	}
	i = 0;
	while ((*dst)[i])
		i++;
	j = 0;
	while (src[j])
		(*dst)[i++] = src[j++];
	(*dst)[i] = '\0';
}

int	gnl_len(char *str, char end)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != end && str[i])
		i++;
	if (end == '\n')
	{
		if (str[i] == '\n')
			return (i + 1);
		return (0);
	}
	return (i);
}

void	free_curr(t_line *curr)
{
	t_line	*to_free;

	to_free = curr;
	free (to_free->line);
	to_free->line = NULL;
	curr = to_free->next;
	to_free->next = NULL;
	free (to_free);
	to_free = NULL;
}
