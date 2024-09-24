/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:28:38 by mremenar          #+#    #+#             */
/*   Updated: 2023/11/06 09:55:37 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description 
** Adds the node ’new’ at the end of the list.
** Parameters 
** lst: The address of a pointer to the first link of a list.
** new: The address of a pointer to the node to be added to the list.
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	curr = ft_lstlast(*lst);
	curr->next = new;
}
/*
int main(void)
{
	t_list *Node = NULL;
	int a = 5;
	int b = 4;
	int *c;

	ft_lstadd_back(&Node, ft_lstnew(&a));
	ft_lstadd_back(&Node, ft_lstnew(&b));

	t_list *curr = Node;
	while (curr)
	{
		c = (int *)(curr->content);
		printf("Value: %d\n", *c);
		curr = curr->next;
	}
}*/