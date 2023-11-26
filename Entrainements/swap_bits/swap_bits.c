/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:26:19 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/25 16:21:02 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* void	print_bits(unsigned char octet)
{
	int div;

	div = 0b10000000;
	while (div)
	{
		if (div & octet)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		div >>= 1;
	}
} */

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

/* int		main(void)
{
	print_bits(15);
	write(1, "\n", 1);
	print_bits(swap_bits(15));
} */