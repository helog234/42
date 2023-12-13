/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:13:26 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/13 11:17:51 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdio.h>

//a mettre dans execute apres cmd_split

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
			//perror(new_cmd[0]);
			//perror(new_cmd[1]);
			free(quote);
			return (new_cmd);
		}
		i++;
	}
	return (NULL);
}

/* int	*next_quote(char *cmd, int i, int *quote)
{
	i = i + 1;
	while (cmd[i])
	{
		if (cmd[i][j] == quote)
			return (&cmd[i][j - 1]);
		i++;
	}
	return (NULL);
}

char	**join_cmd(char *cmd, char *quote)
{
	char	*to_split;
	char	**str;

	to_split = ft_strtrim(cmd, quote);
	str = ft_split(to_split, ' ');
	free(to_split);
	return (str);
} */
// char	**check_quote(char **cmd, char **tmp, int i)
// {
// 	int		start;
// 	int		end;
// 	int		j;
// 	char	*quote;

// 	j = 0;
// 	if (cmd == NULL)
// 		return (NULL);
// 	while (cmd[i])
// 	{
// 		while (cmd[i][j])
// 		{
// 			if (cmd[i][j] == 34 || cmd[i][j] == 39)
// 			{
// 				start = cmd[i][j];
// 				get_quote(&cmd[i][j], cmd[i][j], &end);
// 				quote = ft_substr(cmd, start, end);
// 				cmd = join_cmds(cmd, ft_split(quote, ' '));
// 				return (cmd);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (NULL);
// }

// int	get_quote(char **cmd, char quote, int *end)
// {
// 	int		i;

// 	i = 1;
// 	while (cmd[i])
// 	{
// 		if (cmd[i] == quote)
// 		{
// 			end = &i;
// 			perror(end);
// 		}	
// 		i++;
// 	}
// 	return (0);
// }

// char	**join_cmds(char **cmd, char **tmp)
// {
// 	int	i;
// 	int	j;
// 	int	k;

// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	while (cmd[i] != NULL)
// 		i++;
// 	while (tmp[j])
// 	{
// 		cmd[i] = ft_strjoin(cmd[i], tmp[j]);
// 		i++;
// 		j++;
// 	}
// 	free(tmp);
// 	return (cmd);
// }
