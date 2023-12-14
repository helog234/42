/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:13:26 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/14 19:06:32 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdio.h>
//checker si argument est egal a ' ou a ""
//creer une string composee de la valeur trouve (' ou "")et \0
//creer string qui va spliter en fonction de la valeur puis enlever les espaces avant la string
char	**check_quote(char *cmd)
{
	int		i;
	char	*quote;
	char	**new_cmd;

	i = 0;
	while (cmd[i])
	{	
		if (cmd[i] == 34 || cmd[i] == 39)
		{
			quote = malloc(2);
			if (!quote)
				(error_message(1));
			quote[0] = cmd[i];
			quote[1] = 0;
			new_cmd = ft_split(cmd, quote[0]);
			new_cmd[0] = ft_strtrim(new_cmd[0], " ");
			free(quote);
			return (new_cmd);
		}
		i++;
	}
	return (NULL);
}
