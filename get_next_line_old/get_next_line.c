/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:11:55 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/10 18:12:34 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd;
	char	*line;
    fd = open("text.txt", O_RDONLY);
	while (fd)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	return (0);
}