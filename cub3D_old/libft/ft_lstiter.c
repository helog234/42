/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:40:29 by mremenar          #+#    #+#             */
/*   Updated: 2023/11/06 09:55:37 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description
** Iterates the list ’lst’ and applies the function
** ’f’ on the content of each node.
** Parameters: lst: The address of a pointer to a node.
** f: The address of the function used to iterate on the list.
*/

#include "libft.h"

/*void change_cont(void *content);
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curr;

	curr = lst;
	while (curr)
	{
		f(curr->content);
		curr = curr->next;
	}
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

	ft_lstiter(Node, change_cont);

	if (!Node)
		printf("Node is NULL!\n");
	printf("a: %d, b: %d\n", a, b);
}

void change_cont(void *content)
{
	*(int *)content += 3;
}*/