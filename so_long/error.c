/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:43:12 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/07 11:46:56 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	error_mngmt(int i)
{
	if (i == 0)
		printf("No valid map. Try again !");
	if (i == 1)
		printf("No valid map while parsing. Try again !");
	exit(1);
}
