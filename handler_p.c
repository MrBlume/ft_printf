/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blume <blume@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 09:20:49 by advasseu          #+#    #+#             */
/*   Updated: 2026/11/24 12:40:55 by blume            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	putnbr_base_len(uintptr_t nbr, char *base, int lenbase)
{
	int	count;

	count = 0;
	if (nbr >= (uintptr_t)lenbase)
		count += putnbr_base_len(nbr / lenbase, base, lenbase);
	write(1, &base[nbr % lenbase], 1);
	return (count++);
}

int	handler_p(void *ptr)
{
    if (!ptr)
		return write(1, "(nil)", 5);
	handler_s("0x");
	return (putnbr_base_len((uintptr_t)ptr, "0123456789abcdef", 16) + 2);
}
