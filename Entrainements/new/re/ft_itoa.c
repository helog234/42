/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:23:38 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/26 15:35:06 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	get_len(int i)
{
	int	j;

	j = 0;
	if (i < 0)
		j++;
	while (i)
	{
		j++;
		i = i / 10;
	}
	return (j);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		i;

	i = get_len(nbr);
	str = malloc((i + 1) * sizeof(char));
	str[i] = 0;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = - nbr;
	}
	while (nbr)
	{
		str[i - 1] = nbr % 10 + '0';
		i--;
		nbr = nbr / 10;
	}
	return (str);
}

int main(int argc, char *argv[])
{
	char	*str;

	str = NULL;
	if (argc == 2)
		str = ft_itoa(atoi(argv[1]));
	printf("%s\n", str);
}