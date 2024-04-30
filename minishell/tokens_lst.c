/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:03:12 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/26 20:03:22 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	next_word(char *line, int i)
{
	if (i >= ft_strlen(line))
		return (i);
	while (line[i] && is_separator(line[i]) == 1)
		i++;
	return (i);
}

t_token	*add_token(t_token *previ, int w_start, int w_end)
{
	t_token	*token;
	t_word	*word;

	token = malloc(sizeof(t_token));
	word = malloc (sizeof(t_word));
	if (!token || !word)
		errors(previ, 15);
	if (previ != NULL)
		previ->next = token;
	word->data = NULL;
	token->type = NULL;
	token->class = 0;
	token->prev = previ;
	token->next = NULL;
	word->start = w_start;
	word->end = w_end;
	token->word = word;
	token->dollar = false;
	return (token);
}

void	clean_empty_token(t_token *to_clean, t_token **head)
{
	t_token	*curr;

	curr = *head;
	while (1)
	{
		if (curr == to_clean)
		{
			if (curr->prev)
				curr->prev->next = curr->next;
			if (curr->next)
				curr->next->prev = curr->prev;
			if (curr == *head)
				*head = curr->next;
			free_one_token(&curr, 1);
		}
		if (!curr || !curr->next)
			break ;
		curr = curr->next;
	}
}

t_token	*set_head(t_token **head, int start, int end)
{
	*head = add_token(NULL, start, end);
	if (*head == NULL)
		errors(*head, 15);
	return (*head);
}

t_token	*create_lst(int start, int end, t_token	*token, t_token **head)
{
	if (!*head)
		return (set_head(head, start, end));
	else
	{
		if (!token || !token->class)
		{
			clean_empty_token(token, head);
			if (!*head)
				return (set_head(head, start, end));
			token = get_last(*head);
		}
		token->next = add_token(token, start, end);
		if (token->next == NULL)
			errors(*head, 15);
		return (token->next);
	}
}
