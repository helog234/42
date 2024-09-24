/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:36:29 by mremenar          #+#    #+#             */
/*   Updated: 2023/12/11 11:40:41 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: libft
** SYNOPSIS: count the number of strings in an array of strings
**
** DESCRIPTION:
** 		The nbstr() function returns the number of strings
**	in a given array of strings.
*/

#include "libft.h"

int	ft_nbstr(char **arr_strs)
{
	int	i;

	i = 0;
	if (arr_strs)
	{
		while (arr_strs[i])
			i++;
	}
	return (i);
}
