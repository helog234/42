/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:02:02 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/22 15:04:05 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	get_strs(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i] && str)
	{
		if (str[i] == ' ' || str[i] == '	')
			j++;
		i++;
	}
	return (j);
}

char	*to_split(char *str, int i, int j)
{
	char	*new;
	int		x;

	x = j - 1 - i;
	new = malloc((x + 1) * sizeof(char));
	x = 0;
	while (i < j)
	{
		new[x] = str[i];
		x++;
		i++;
	}
	new[x] = 0;
	return (new);
}

char	**reverse_str(char *str)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	j = get_strs(str);
	split = malloc((j + 1) * sizeof(char *));
	split[j] = NULL;
	i = 0;
	k = 0;
	while (str && j >= 0)
	{
		if (str[i] == ' ' || str[i] == '	' || str[i] == 0)
		{
			split[j - 1] = to_split(str, k, i);
			k = i + 1;
			j--;
		}
		i++;
	}
	return (split);
}

int	main(int argc, char *argv[])
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	str = NULL;
	if (argc == 2)
		str = reverse_str(argv[1]);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			write(1, &str[i][j], 1);
			j++;
		}
		write(1, " ", 1);
		// printf("i : %i\n", i);
		i++;
	}
	if (str != NULL)
		free(str);
	write(1, "\n", 1);
	return (0);
}
