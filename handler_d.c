/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blume <blume@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 09:20:49 by advasseu          #+#    #+#             */
/*   Updated: 2026/11/06 18:24:56 by blume            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int putnbr_len(long nbr)
{
    int count = 0;

    if (nbr < 0)
    {
        handler_c('-');
        count++;
        nbr = -nbr;
    }
    
    if (nbr >= 10)
    {
        count += putnbr_len(nbr / 10);
    }
    handler_c((nbr % 10) + '0');
    count++;

    return (count);
}

int	handler_d(int n)
{
	long nb;
    int count;

    nb = (long)n;
    count = putnbr_len(nb);

    return (count);
}
