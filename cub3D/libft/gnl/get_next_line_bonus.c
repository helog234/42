/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:36:25 by mremenar          #+#    #+#             */
/*   Updated: 2024/05/20 18:03:42 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*	- find the file descriptor in linked lists, if not found 
	create a new one
	- call the function (extract_line) which will read the file,
	return a complete line and save what has been read beyond 
	for the next call
	- if no line has been returned, free the linked list */
char	*get_next_line(int fd)
{
	static t_line	*root = NULL;
	t_line			*curr;
	char			*ret_line;

	if (!verif(&root, fd))
		return (NULL);
	curr = root;
	while (curr)
	{
		if (curr->id_fd == fd)
			break ;
		curr = curr->next;
	}
	if (!root || !curr)
		curr = gnl_add_new(&root, fd);
	ret_line = extract_line(curr, fd);
	if (!ret_line)
	{
		if (root)
			free_list(&root, curr->id_fd);
		return (NULL);
	}
	return (ret_line);
}

/*	- Read file and concatenate what's read in the line variable of the 
	list corresponding to the current fd
	- check the extracted line if there is a \n, if there is, stop reading
	- extract the complete line, including \n if there is one at the end of line
	- store the rest of the content in the static line variable
	- return the complete line
*/
char	*extract_line(t_line *curr_file, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		n_read;
	int		len_end;
	char	*ret_line;

	n_read = 0;
	len_end = gnl_len(curr_file->line, '\n');
	while (!len_end)
	{
		n_read = read(fd, &buff, BUFFER_SIZE);
		if (n_read < 0)
			return (NULL);
		if (!n_read)
			break ;
		buff[n_read] = 0;
		gnl_strlcat(&curr_file->line, buff);
		len_end = gnl_len(curr_file->line, '\n');
	}
	if (!n_read && !len_end)
		len_end = gnl_len(curr_file->line, '\0');
	ret_line = cpy_lines(curr_file, len_end);
	return (ret_line);
}

/*	Save in static variable what has already been read after the 
	complete line which will be returned */
char	*cpy_lines(t_line *curr_file, int len)
{
	char	*new_line;
	int		i;

	if (!len || !curr_file->line[0])
		return (NULL);
	new_line = malloc(len + BUFFER_SIZE);
	if (!new_line)
		return (NULL);
	i = -1;
	while (++i < len)
		new_line[i] = curr_file->line[i];
	new_line[i] = 0;
	if (!curr_file->line[i])
	{
		curr_file->line[0] = 0;
		return (new_line);
	}
	i = -1;
	while (curr_file->line[++i + len])
		curr_file->line[i] = curr_file->line[i + len];
	while (curr_file->line[i])
		curr_file->line[i++] = 0;
	return (new_line);
}

void	free_list(t_line **root, int fd)
{
	t_line	*curr;

	if (*root == NULL)
		return ;
	curr = *root;
	if (fd == -1)
	{
		while (curr)
		{
			curr = curr->next;
			free_curr(curr);
		}
		*root = NULL;
		return ;
	}
	curr = find_to_free(*root, fd);
	if (*root == curr)
		*root = curr->next;
	free_curr(curr);
	return ;
}

t_line	*find_to_free(t_line *root, int fd)
{
	t_line	*curr;
	t_line	*to_free;

	curr = root;
	to_free = NULL;
	if (curr->id_fd == fd)
		return (curr);
	while (curr->next)
	{
		if (curr->next->id_fd == fd)
		{
			to_free = curr->next;
			curr->next = curr->next->next;
			return (to_free);
		}
		curr = curr->next;
	}
	return (NULL);
}
