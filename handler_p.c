/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advasseu <advasseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 09:20:49 by advasseu          #+#    #+#             */
/*   Updated: 2026/11/26 10:17:56 by advasseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handler_p(void *ptr)
{
	int	count;
	int	ret;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = 0;
	ret = handler_s("0x");
	if (ret < 0)
		return (-1);
	count += ret;
	ret = putnbr_ubase((uintptr_t)ptr, "0123456789abcdef");
	if (ret < 0)
		return (-1);
	count += ret;
	return (count);
}
