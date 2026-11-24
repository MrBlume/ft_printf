/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blume <blume@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 09:20:49 by advasseu          #+#    #+#             */
/*   Updated: 2026/11/24 15:16:00 by blume            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_len(long nbr)
{
	int	count;
	int	ret;

	count = 0;
	if (nbr < 0)
	{
		if (handler_c('-') < 0)
			return (-1);
		count++;
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ret = putnbr_len(nbr / 10);
		if (ret < 0)
			return (-1);
		count += ret;
	}
	if (handler_c((nbr % 10) + '0') < 0)
		return (-1);
	count++;
	return (count);
}

int	handler_d(int n)
{
	return (putnbr_len((long)n));
}