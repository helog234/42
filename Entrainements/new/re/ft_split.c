/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:35:25 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/26 18:04:17 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*dup(char *str, int beg, int end)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc((end - beg + 1) * sizeof(char));
	while (beg + i < end)
	{
		new[i] = str[beg + i];
		i++;
	}
	new[i] = 0;
	printf("%s\n", new);
	return (new);
}

char    **ft_split(char *str)
{
	char	**new;
	int		i;
	int		start;
	int		j;

	i = 0;
	start = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] != ' ' && str[i] != '\t') && (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
			j++;
		i++;
	}
	
	new = malloc(j * sizeof(char *));
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		start = i;
		while (str[i] != ' ' && str[i] != '\t')
			i++;
		if (i > start)
		{
			new[j] = dup(str, start, i);
			// printf("%s\n", new[j]);
			j++;
		}
		printf("%i", i);
	}
	new[j] = NULL;
	return (new);
}

int	main(int argc, char *argv[])
{
	char	**str;
	int		i;

	if (argc == 2)
		str = ft_split(argv[1]);
	i = 0;
	while (str[i])
	{
		// printf("%s", str[i]);
		i++;
	}
	return (0);
}
