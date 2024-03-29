/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:41:23 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/26 09:58:19 by hgandar          ###   ########.fr       */
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

int	is_alpha(char c)
{
	int	i;

	i = 0;
	if ((c < 'A' || c >= 'Z') && \
	(c < 'a' || c >= 'z'))
		return (0);
	i++;
	return (1);
}
char	**control(char **new)
{
	int	i;
	int	j;

	i = 0;
	while (new[i])
	{
		j = 0;
		while (new[i][j])
		{
			if ((new[i][j] == ' ') || new[i][j] == '	')
			{
				free(new[i]);
				new[i] = new[i + 1];
			}
			j++;
		}
		i++;
	}
	return (new);
}

char	**rostring(char *str)
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
		if ((str[i] == ' ' && is_alpha(str[i + 1]) == 1) || \
		(str[i] == '	' && is_alpha(str[i + 1]) == 1))
		{
			new[j] = split(str, k, i);
			printf("l %s\n", new[j]);
			k = i + 1;
			if (j == get_strs(str))
				j = 0;
			else 
				j++;
		}
		i++;
	}
	new = control(new);
	return (new);
}

int	print_line(char *str)
{
	char	*first;
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '	' || str[i] == 0)
			break ;
		i++;
	}
	first = malloc(i * sizeof(char));
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '	' || str[i] == 0)
			break ;
		first[i] = str[i];
		i++;
	}
	first[i] = 0;
	if (str[i] == 0)
	{
		while (first[j])
		{
			write(1, &first[j], 1);
			j++;
		}
		return (0);
	}
	i++;
	while (str[i])
	{
		if ((str[i - 1] == ' ' && str[i] == ' ') || (str[i - 1] == '	' && str[i] == '	') \
		|| (str[i - 1] == ' ' && str[i] == '	') || (str[i - 1] == '	' && str[i] == ' ') )
			i++ ;
		else
		{
			write(1, &str[i], 1);
			i++;
			flag = 1;
		}
	}
	if (flag == 1)
		write(1, " ", 1);
	j = 0;
	while (first[j])
	{
		write(1, &first[j], 1);
		j++;
	}
	free(first);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
		print_line(argv[1]);
	write(1, "\n", 1);
	return (0);
	/* 	char	**str;
	int		i;
	int		j;

	i = 0;
	str = NULL;
	if (argc > 1)
		str = rostring(argv[1]);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			write(1, &str[i][j], 1);
			j++;
		}
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	return (0); */
}
