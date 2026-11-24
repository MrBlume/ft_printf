/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbrs_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blume <blume@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 10:32:59 by blume             #+#    #+#             */
/*   Updated: 2026/11/24 15:23:30 by blume            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	putnbr_base(int nbr, char *base)
{
	int		lenbase;
	long	nb;
	int		count;

	lenbase = ft_strlen(base);
	if (lenbase < 2)
		return (0);
	count = 0;
	nb = nbr;
	if (nb < 0)
	{
		handler_c('-');
		count++;
		nb = -nb;
	}
	if (nb >= lenbase)
		count += putnbr_base(nb / lenbase, base);
	handler_c(base[nb % lenbase]);
	return (count++);
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
