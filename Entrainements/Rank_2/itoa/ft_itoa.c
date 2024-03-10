/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:30:44 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/05 15:58:12 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	size_char(int i)
{
	int	j;
	
	j = 0;
	while (i > 0)
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
	int		flag;
	
	i = 0;
	flag = 0;
	if (nbr < 0)
	{
		flag = 1;
		nbr = -nbr;
		i++;
	}
	i += size_char(nbr);
	str = malloc(i * sizeof(int));
	str[i] = 0;
	if (flag == 1)
		str[0] = '-';
	while (nbr)
	{
		str[i - 1] = nbr % 10 + '0';
		i--;
		nbr = nbr / 10;
	}
	return (str);
 }

 int	main(void)
 {
	int	nbr;

	nbr = 124;
	printf("%s\n", ft_itoa(nbr));
	return (0);
 }
 