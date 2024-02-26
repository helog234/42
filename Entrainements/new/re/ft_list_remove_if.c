/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:41:24 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/26 16:28:32 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*curr;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	curr = *begin_list;
	if (cmp(curr->data, data_ref) == 0)
	{
		*begin_list = curr->next;
		free(curr);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
		ft_list_remove_if(&curr->next, data_ref, cmp);
}

void	print_list(t_list **list)
{
	t_list	*curr;

	curr = *list;
	while (curr)
	{
		printf("%s\n", curr->data);
		curr = curr->next;
	}
}

int	main(void)
{
	t_list **beggin;
	
	char	stra[] = "aa";
	t_list	*aa = malloc(sizeof(t_list));
	aa->next = 0;
	aa->data = stra;
	
	char	strb[] = "bb";
	t_list	*bb = malloc(sizeof(t_list));
	bb->next = 0;
	bb->data = strb;

	char	strc[] = "cc";
	t_list	*cc = malloc(sizeof(t_list));
	cc->next = 0;
	cc->data = strc;
	
	char	strd[] = "dd";
	t_list	*dd = malloc(sizeof(t_list));
	dd->next = 0;
	dd->data = strd;

	aa->next = bb;
	bb->next = cc;
	cc->next = dd;
	
	beggin = &aa;
	print_list(beggin);
	printf("-----------\n");
	ft_list_remove_if(beggin, cc->data, strcmp);
	print_list(beggin);
}
