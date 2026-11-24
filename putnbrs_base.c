/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbrs_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blume <blume@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 10:32:59 by blume             #+#    #+#             */
/*   Updated: 2026/11/24 17:33:00 by blume            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_base(long nbr, char *base)
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
		ret = putnbr_unsigned_base(nbr / ft_strlen((char *)base), base);
		if (ret < 0)
			return (-1);
		count += ret;
	}
	if (handler_c((nbr % 10) + '0') < 0)
		return (-1);
	count++;
	return (count);
}

int	putnbr_unsigned_base(unsigned long nbr, const char *base)
{
	unsigned long	lenbase;
	int				count;
	int				ret;

	lenbase = (unsigned long)ft_strlen((char *)base);
	if (lenbase < 2)
		return (-1);
	count = 0;
	if (nbr >= lenbase)
	{
		ret = putnbr_unsigned_base(nbr / lenbase, base);
		if (ret < 0)
			return (-1);
		count += ret;
	}
	if (handler_c(base[nbr % lenbase]) < 0)
		return (-1);
	count++;
	return (count);
}
