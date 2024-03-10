/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:22:10 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/26 14:49:06 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(char c)
{
	if (c == ' ' || c == 0 || c == '\n' || \
	c == '\t' || c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

void	rstr_capitalizer(char * str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			if (ft_isspace(str[i + 1]) && (str[i] >= 'a' && str[i] <= 'z'))
			{
				str[i] = str[i] - 32;
				write(1, &str[i], 1);
			}
			else if (ft_isspace(str[i + 1]) && (str[i] >= 'A' && str[i] <= 'Z'))
				write(1, &str[i], 1);
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] = str[i] + 32;
				write(1, &str[i], 1);
			}
			else
				write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int i;

	i = 1;
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argc > 1)
	{
		rstr_capitalizer(argv[i]);
		write(1, "\n", 1);
		i++;
		argc--;
	}
	return (0);
}