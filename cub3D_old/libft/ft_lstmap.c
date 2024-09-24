/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:50:33 by mremenar          #+#    #+#             */
/*   Updated: 2023/11/10 10:33:02 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description 
** Iterates the list ’lst’ and applies the function
** ’f’ on the content of each node. Creates a new
** list resulting of the successive applications of
** the function ’f’. The ’del’ function is used to
** delete the content of a node if needed.
** Parameters: lst: The address of a pointer to a node.
** f: The address of the function used to iterate on
** the list.
** del: The address of the function used to delete
** the content of a node if needed.
** Return value: The new list. NULL if the allocation fails.
*/

#include "libft.h"
/*
void *change_cont(void *content);

void del_cont(void *content);*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*add_new;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		add_new = ft_lstnew(f(lst->content));
		if (!add_new)
		{
			ft_lstclear(&new_list, del);
			new_list = NULL;
			return (NULL);
		}
		ft_lstadd_back(&new_list, add_new);
		lst = lst->next;
	}
	return (new_list);
}
/*
int main(void)
{
	t_list *Node = NULL;
	t_list *new;
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

	new = ft_lstmap(Node, change_cont, del_cont);

	curr = new;
	while (curr)
	{
		c = (int *)(curr->content);
		printf("Value: %d\n", *c);
		curr = curr->next;
	}
	printf("a: %d, b: %d\n", a, b);
}

void *change_cont(void *content)
{
	*(int *)content += 3;
	return ((void *)content);
}

void del_cont(void *content)
{
	if (content)
		*(int *)content = 0;
}*/