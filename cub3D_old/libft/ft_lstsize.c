/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:36:59 by mremenar          #+#    #+#             */
/*   Updated: 2023/11/06 09:55:37 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description 
** Counts the number of nodes in a list.
** Parameters: lst: The beginning of the list.
** Return value: The length of the list
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		n;
	t_list	*curr;

	n = 0;
	curr = lst;
	while (curr)
	{
		n++;
		curr = curr->next;
	}
	return (n);
}
/*
int main(void)
{
	t_list *Node = NULL;
	int a = 5;
	int b = 4;
	int s;

	ft_lstadd_front(&Node, ft_lstnew(&a));
	ft_lstadd_front(&Node, ft_lstnew(&b));
	ft_lstadd_front(&Node, ft_lstnew(&a));
	s = ft_lstsize(Node);
	printf("List size: %d\n", s);
}*/