/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:23:26 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/26 20:10:34 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_types_data(t_token *token)
{
	t_file	*file;
	t_arg	*to_free;

	if (token->class == BUILT_IN || token->class == CMD)
		free_cmd(token);
	else if (token->class == FILES)
	{
		file = token->type;
		free(file->data);
		free(file->path_to_file);
		free(file->pwd);
		file->data = NULL;
	}
	else if (token->class == REDIR)
		free_redir(token);
	else if (token->class == ARG)
	{
		to_free = token->type;
		if (to_free->data)
			free(to_free->data);
		to_free->data = NULL;
	}
}

void	free_one_token(t_token **curr, bool free_types)
{
	t_token	*previ;

	previ = NULL;
	if ((*curr)->prev)
	{
		(*curr)->prev->next = (*curr)->next;
		previ = (*curr)->prev;
	}
	if ((*curr)->next)
		(*curr)->next->prev = (*curr)->prev;
	(*curr)->prev = NULL;
	(*curr)->next = NULL;
	if (free_types)
		free_types_data(*curr);
	free((*curr)->word->data);
	(*curr)->word->data = NULL;
	free((*curr)->word);
	(*curr)->word = NULL;
	free(*curr);
	*curr = previ;
}

void	free_tokens(t_token *curr)
{
	t_token	*head;

	if (!curr)
		return ;
	while (curr->prev != NULL)
		curr = curr->prev;
	head = curr;
	while (head)
	{
		free_types_data(curr);
		free(curr->type);
		curr->type = NULL;
		free(curr->word);
		curr->word = NULL;
		head = curr->next;
		free(curr);
		curr = head;
	}
	curr = NULL;
}

void	free_utils(t_clean *utils)
{
	if (*utils->head)
		free_tokens(*utils->head);
	free(utils->file_error);
	utils->file_error = NULL;
	utils->env = NULL;
	free(utils->path_history);
	utils->path_history = NULL;
	free(utils);
	utils = NULL;
}
