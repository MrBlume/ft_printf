/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advasseu <advasseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 10:32:59 by blume             #+#    #+#             */
/*   Updated: 2026/11/10 09:45:12 by advasseu         ###   ########.fr       */
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
