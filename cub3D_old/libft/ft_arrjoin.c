/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:42:08 by mremenar          #+#    #+#             */
/*   Updated: 2023/12/11 13:47:35 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: libft
** SYNOPSIS: joint two arrays of strings into one
**
** DESCRIPTION:
** 		The ft_arrjoin() function copies two arrays of strings
**	into one arr of strings. The original arrays can be freed after.
*/

#include "libft.h"

char	**ft_arrjoin(char **arr1, char **arr2)
{
	int		i;
	int		j;
	char	**ret_arr;

	ret_arr = malloc(sizeof(char **) * (ft_nbstr(arr1) + ft_nbstr(arr2) + 1));
	if (!ret_arr)
		return (NULL);
	i = 0;
	if (arr1)
	{
		while (arr1[i])
		{
			ret_arr[i] = ft_strdup(arr1[i]);
			i++;
		}
	}
	j = -1;
	if (arr2)
	{
		while (arr2[++j])
			ret_arr[i++] = ft_strdup(arr2[j]);
	}
	ret_arr[i] = NULL;
	return (ret_arr);
}
