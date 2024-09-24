/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:30:19 by mremenar          #+#    #+#             */
/*   Updated: 2023/11/07 15:25:38 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description 
** Allocates (with malloc(3)) and returns a new node.
** The member variable ’content’ is initialized with
** the value of the parameter ’content’. The variable
** ’next’ is initialized to NULL.
** Return value: The new node
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
