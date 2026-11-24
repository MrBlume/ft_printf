/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blume <blume@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 09:20:49 by advasseu          #+#    #+#             */
/*   Updated: 2026/11/24 17:32:48 by blume            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handler_p(void *ptr)
{
    if (!ptr)
		return write(1, "(nil)", 5);
	handler_s("0x");
	return (putnbr_unsigned_base((uintptr_t)ptr, "0123456789abcdef") + 2);
}
