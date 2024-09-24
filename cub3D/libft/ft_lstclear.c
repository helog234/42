/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:12:21 by mremenar          #+#    #+#             */
/*   Updated: 2023/11/06 09:55:37 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description 
** Deletes and frees the given node and every
** successor of that node, using the function ’del’ and free(3).
** Finally, the pointer to the list must be set to NULL.
** Parameters: lst: The address of a pointer to a node.
** del: The address of the function used to delete 
** the content of the node.
*/

#include "libft.h"

//void del_cont(void *content);

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = 0;
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

	ft_lstclear(&Node, del_cont);

	if (!Node)
		printf("Node is NULL!\n");
	printf("a: %d, b: %d\n", a, b);
}

void del_cont(void *content)
{
	if (content)
		*(int *)content = 0;
}*/