/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:06:43 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/26 19:57:27 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "signals.h"

bool	line_is_empty(char **line)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] != ' ' && (*line)[i] != '	')
		{
			j = 0;
			tmp = malloc((ft_strlen(*line) - i + 1) * sizeof(char));
			while ((*line)[i])
				tmp[j++] = (*line)[i++];
			tmp[j] = 0;
			free(*line);
			*line = tmp;
			return (false);
		}
		i++;
	}
	free(*line);
	return (true);
}

char	*get_line(t_clean *utils)
{
	struct termios	original_term;
	struct termios	new_term;
	char			*line;

	tcgetattr(STDIN_FILENO, &original_term);
	new_term = original_term;
	new_term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &new_term);
	line = readline("minishell> ");
	if (line == NULL)
		return (NULL);
	history_log(line, utils->path_history);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_term);
	if (g_signal_flag > 0)
		utils->exit_status = g_signal_flag;
	g_signal_flag = 0;
	return (line);
}

t_clean	*init_clean_utils(t_clean *utils, t_token **head, \
							t_env *env, char *path)
{
	utils = malloc(sizeof(t_clean));
	if (!utils)
		error_message(15, NULL);
	utils->exit_status = 0;
	utils->i = 0;
	utils->j = 0;
	utils->target = 0;
	utils->head = head;
	utils->token = NULL;
	utils->file_error = NULL;
	utils->size = 0;
	utils->in_single_quote = false;
	utils->in_double_quote = false;
	utils->line = NULL;
	utils->err_num = 0;
	utils->env = env;
	utils->path_history = path;
	return (utils);
}

int	set_prompt(t_env *ms_env, t_token **head, char *path_history)
{
	char	*line;
	t_clean	*utils;
	int		exec_status;
	int		exit_code;

	line = NULL;
	utils = NULL;
	utils = init_clean_utils(utils, head, ms_env, path_history);
	exec_status = 0;
	while (1)
	{
		exit_code = utils->exit_status;
		line = get_line(utils);
		if (line == NULL)
			break ;
		if (set_prompt2(utils, line, &exec_status, ms_env))
		{
			if (exec_status)
				exit_code = exec_status;
			break ;
		}
		free_tokens(*(utils->head));
		*(utils->head) = NULL;
	}
	return (free_utils(utils), exit_code);
}

int	set_prompt2(t_clean *utils, char *line, int *exec_status, t_env *ms_env)
{
	utils->err_num = 0;
	if (line_is_empty(&line) == false)
	{
		utils->exit_status = init_parsing(line, utils);
		if (!g_signal_flag)
			*exec_status = execution(&ms_env, *(utils->head));
		utils->exit_status = *exec_status;
	}
	if (!ms_env)
		return (1);
	return (0);
}
