/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:41:23 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/22 14:38:06 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*split(char *str, int k, int i)
{
	int		j;
	char	*new;

	j = 0;
	new = malloc((i - k + 1) * sizeof(char));
	while (k < i)
	{
		new[j] = str[k];
		j++;
		k++;
	}
	new[j] = 0;
	return (new);
}

int	get_strs(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '	')
			j++;
		i++;
	}
	return (j);
}

int	is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] > 'A' || str[i] <= 'Z') && \
		(str[i] > 'a' || str[i] <= 'z'))
			return (0);
		i++;
	}
	return (1);
}

char	*rostring(char *str)
{
	char	*tmp;
	char	**new;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = get_strs(str);
	new = (char **)malloc((j + 1) * sizeof(char *));
	new[j + 1] = NULL;
	k = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '	')
		{
			new[j] = split(str, k, i);
			k = i + 1;
			if (j == get_strs(str))
				j = 0;
			else 
				j++;
		}
		i++;
	}
	return (str);
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	if (argc > 1)
		str = rostring(argv[1]);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
