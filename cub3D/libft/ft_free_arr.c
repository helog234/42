/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:46:11 by mremenar          #+#    #+#             */
/*   Updated: 2023/12/11 11:48:38 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: libft
** SYNOPSIS: free an array of strings and it's substrings
**
** DESCRIPTION:
** 		The ft_free_arr() function frees the allocates substrings
**	of a given array of strings, and the array itself, which is set to NULL.
*/

#include "libft.h"

void	ft_free_arr(char	**arr_strs)
{
	int	i;

	i = -1;
	while (arr_strs[++i])
		free(arr_strs[i]);
	free (arr_strs);
	arr_strs = NULL;
}
