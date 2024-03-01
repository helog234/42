/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:43:55 by hgandar           #+#    #+#             */
/*   Updated: 2024/03/01 18:04:10 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_separator(char c)
{
	if (c != ' ' || c != '	' || c != 0 || c != '&' || c != ';' || c != '\n')
		return (1);
	return (0);
}

int	is_str(char c)
{
	if (c == 34 || c == 39)
		return (1);
	return (0);
}

int	is_word_str(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = -1;
	while (str[i])
	{
		if (is_separator(str[i]) && flag == -1)
			return (i - 1);
		if (is_str(str[i]) && flag == -1)
			flag = i + 1;
		else if (is_str(str[i]) && flag >= 0)
			return (i - 1);
		i++;
	}
	return (0);
}

int	is_redir(char *token)
{
	if (token[0] == '|' && token[1] == 0)
		return (1);
	else if (token[0] == '<' && token[1] == 0)
		return (1);
	else if (token[0] == '>' && token[1] == 0)
		return (1);
	else if (token[0] == '>' && token[1] == '>' && token[2] == 0)
		return (1);
	else if (token[0] == '<' && token[1] == '<' && token[2] == 0)
		return (1);
	return (0);
}

int	is_cmd(char *token)
{
	if (ft_strncmp("echo", token, 4) == 0)
		return (1);
	else if (ft_strncmp("cd", token, 2) == 0)
		return (1);
	else if (ft_strncmp("pwd", token, 3) == 0)
		return (1);
	else if (ft_strncmp("export", token, 6) == 0)
		return (1);
	else if (ft_strncmp("unset", token, 5) == 0)
		return (1);
	else if (ft_strncmp("env", token, 3) == 0)
		return (1);
	else if (ft_strncmp("exit", token, 4) == 0)
		return (1);
	else
		return (0);
}

t_cmd	*init_cmd(char *str)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	cmd->fd = 0;
	cmd->data = str;
	cmd->first_arg = NULL;
	return (cmd);
}

t_redir	*init_redir(void)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	redir->fd_in = 0;
	redir->fd_out = 0;
	return (redir);
}

t_file	*init_file(char *str)
{
	t_file	*file;

	file = malloc(sizeof(t_file));
	file->fd = 0;
	file->name = str;
	return (file);
}

t_arg	*init_arg(char *str)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	arg->data = str;
	arg->index = 0;
	arg->prev = NULL;
	arg->next = NULL;
}

t_token	*init_token(char *str, int flag)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (flag == 1)
		token->type = init_cmd(str);
	else if (flag == 2)
		token->type = init_redir();
	else if (flag == 3)
		token->type = init_arg(str);
	else if (flag == 4)
		token->type = init_file(str);
	else
		token->type =
	token->index = 0;
	token->prev = NULL;
	token->next = NULL;
	return (token);
}


t_token *define_token(char *arg, int start, int end, t_token *previ)
{
	char	*str;
	int		i;
	t_token	*token;

	str = malloc((start - end + 1) * sizeof(char));
	i = start;
	while (i <= end)
	{
		str[i] = arg[i];
		i++;
	}
	str[i] = 0;
	if (is_cmd(str))
		token = init_token(str, 1);
	else if (is_redir(str))
		token = init_token(str, 2);
	else if (previ != NULL && is_cmd(previ->type))
		token = init_token(str, 3);
	else if (previ != NULL && is_redir(previ->type))
		token = init_token(str, 4);
	token->prev = previ;
	return (token);
}

int	check_args(int argc, char *argv[], char *env[])
{
	int		i;
	int		j;
	int		k;
	t_token	*token;

	i = 1;
	token = NULL;
	j = -1;
	while (i <= argc)
	{
		j = is_word_str(argv[i]);
		if (j >= 0)
			token = define_token(argv[i], i , j, token);
		token = token->next;
		j = -1;
		i++;
	}
	
}

int	main(int argc, char *argv[], char *env[])
{
	if (argc > 1)
		check_args(argc, argv, env);
}

