/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:22:30 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/25 16:15:57 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	gnl_argv(t_file *file, t_env *env, t_clean *utils)
{
	char	*line;
	int		control;

	line = NULL;
	control = 1;
	set_signals(*utils->head, HEREDOC_FLAG);
	while (control > 0)
	{
		line = get_next_line(STDIN_FILENO, 1);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, file->limiter, ft_strlen(file->limiter)) == 0)
		{
			control = 0;
			free(line);
			break ;
		}
		clean_heredoc(&line, env, utils);
		ft_putstr_fd(line, file->fd);
		free(line);
	}
	set_signals(*utils->head, PARENT_WO_CHILD);
}

void	clean_heredoc(char **line, t_env *env, t_clean *utils)
{
	char	**words;
	int		i;

	words = ft_split(*line, ' ');
	*line[0] = 0;
	i = -1;
	while (words[++i])
	{
		heredoc_dollar(&words[i], env, utils);
		if (i > 0)
			strjoin_andfree(line, ft_strdup(" "));
		strjoin_andfree(line, words[i]);
	}
	free(words);
}

void	heredoc_dollar(char **word, t_env *env, t_clean *utils)
{
	char	*tmp;
	int		i_dollar;

	utils->j = 0;
	i_dollar = -1;
	tmp = NULL;
	while ((*word)[utils->j])
	{
		if ((is_heredoc_separator((*word)[utils->j]) \
		|| (*word)[utils->j] == '\n') && i_dollar >= 0)
		{
			if (i_dollar > 0)
				tmp = ft_substr(*word, utils->j, ft_strlen(*word));
			handle_dollar(word, env, i_dollar, utils);
			utils->j = ft_strlen(*word);
			if (tmp)
				strjoin_andfree(word, tmp);
			i_dollar = -1;
		}
		if ((*word)[utils->j] == '$' && i_dollar < 0)
			i_dollar = utils->j + 1;
		utils->j++;
	}
}

void	ignore_ctrld(struct termios *original_term)
{
	struct termios	new_term;

	new_term = *original_term;
	new_term.c_cc[VEOF] = _POSIX_VDISABLE;
	new_term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
}

void	restore_ctrld(struct termios *original_term)
{
	tcsetattr(STDIN_FILENO, TCSANOW, original_term);
}
