/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:36:40 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/26 19:47:27 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	print_types_data(t_token *token)
// {
// 	t_cmd	*cmd;
// 	t_file	*file;
// 	t_redir	*redir;
// 	t_arg	*arg;
// 	t_word	*wrd;

// 	printf ("token -> ");
// 	if (token->class == BUILT_IN || token->class == CMD)
// 	{
// 		cmd = token->type;
// 		printf("%s\n", cmd->data);
// 	}
// 	else if (token->class == FILES)
// 	{
// 		file = token->type;
// 		printf("%s\n", file->data);
// 	}
// 	else if (token->class == REDIR)
// 	{
// 		redir = token->type;
// 		printf("%s\n", redir->data);
// 		if (redir->heredoc)
// 			file = redir->heredoc;
// 		if (redir->fd_in && token->next)
// 			file = token->next->type;
// 	}
// 	else if (token->class == ARG)
// 	{
// 		arg = token->type;
// 		printf("%s\n", arg->data);
// 	}
// 	else
// 	{
// 		wrd = token->type;
// 		if (wrd)
// 			printf("%s\n", wrd->data);
// 	}
// }

// void	print_list(t_token *token)
// {
// 	t_arg	*arg;
// 	t_cmd	*cmd;

// 	while (token)
// 	{
// 		print_types_data(token);
// 		if (token->class == CMD || token->class == BUILT_IN)
// 		{
// 			cmd = token->type;
// 			arg = cmd->first_arg;
// 			while (arg)
// 			{
// 				printf("	arg %i : %s\n", arg->index, arg->data);
// 				arg = arg->next;
// 			}
// 		}
// 		token = token->next;
// 	}
// }
