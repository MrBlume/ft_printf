/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advasseu <advasseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 09:16:08 by advasseu          #+#    #+#             */
/*   Updated: 2026/11/03 10:20:58 by advasseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *base, ...)
{
	va_list	vars;

	va_start(vars, base);
	while (*base)
	{
		if (*base == '%')
		{
			base++;
			if (*base == 'c')
				handler_c((char)va_arg(vars, int));
			if (*base == 's')
				handler_s(va_arg(vars, char *));
			if (*base == 'p')
				handler_p((void *)va_arg(vars, char *));
			if (*base == 'd' || *base == 'i')
				handler_i((int)va_arg(vars, int));
			if (*base == 'u')
				handler_u((int)va_arg(vars, int));
			// if (*base == 'x')
			// 	handler_x((int)va_arg(vars, int));
			// if (*base == 'X')
			// 	handler_X((int)va_arg(vars, int));
			if (*base == '%')
				write(1, "%", 1);
		}
		else
			write(1, base, 1);
		base++;
	}
	va_end(vars);
	return (0);
}

int	main(void)
{
	char	*c = "test";
	unsigned int i = 42;
	ft_printf("CHAR %c\nSTRING %s\nPTR %p\nDEC %d\nINT %i\nUNS DEC %u\nLoHEX %x\nUpHEX %X\nPERC %%\n\n", 'c', "str", &c, i, -42, i, 0xFF, 0xFF);
	printf("CHAR %c\nSTRING %s\nPTR %p\nDEC %d\nINT %i\nUNS DEC %u\nLoHEX %x\nUpHEX %X\nPERC %%\n\n", 'c', "str", &c, i, -42, i, 0xFF, 0xFF);
	return (0);
}
