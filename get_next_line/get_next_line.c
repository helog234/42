/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:42:10 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/08 17:27:57 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

int	ft_strchr_line(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			return (i);
		else
			i++;
	}
	return (0);
}

char	*fill_line_buffer(int fd, char *stash, char *str)
{
	size_t	count;
	int		i;

	count = 5;
	while (read(fd, str, count))
	{
		stash = ft_strlcat(stash, str, count);
		i = ft_strchr_line(stash, '\n');
		if (i != 0)
		{
			str = ft_substr(stash, 0, i + 1);
			stash[0] = stash[i + 1];
			return (ft_strdup(str));
		}
		else
			continue ;
	}
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	stash[BUFFER_SIZE];

	str = fill_line_buffer(fd, stash, str);
}

int	main(void)
{
	
}