/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advasseu <advasseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 09:16:08 by advasseu          #+#    #+#             */
/*   Updated: 2026/11/26 09:42:14 by advasseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_conv(char spec, va_list vars)
{
	if (spec == 'c')
		return (handler_c((char)va_arg(vars, int)));
	else if (spec == 's')
		return (handler_s(va_arg(vars, char *)));
	else if (spec == 'p')
		return (handler_p(va_arg(vars, void *)));
	else if (spec == 'd' || spec == 'i')
		return (putnbr_base(va_arg(vars, int), "0123456789"));
	else if (spec == 'u')
		return (putnbr_ubase(va_arg(vars, unsigned int), "0123456789"));
	else if (spec == 'x')
		return (putnbr_ubase(va_arg(vars, unsigned int), "0123456789abcdef"));
	else if (spec == 'X')
		return (putnbr_ubase(va_arg(vars, unsigned int), "0123456789ABCDEF"));
	else if (spec == '%')
		return (write(1, "%", 1));
	return (-1);
}

int	ft_printf(const char *base, ...)
{
	va_list	vars;
	int		count;
	int		ret;

	if (!base)
		return (-1);
	count = 0;
	va_start(vars, base);
	while (*base)
	{
		if (*base == '%')
		{
			base++;
			if (!*base)
				return (va_end(vars), -1);
			ret = handle_conv(*base, vars);
		}
		else
			ret = write(1, base, 1);
		if (ret < 0)
			return (va_end(vars), -1);
		count += ret;
		base++;
	}
	return (va_end(vars), count);
}

// int	main(void)
// {
// 	char	*c = "test";
// 	unsigned int i = 42;
// 	// int count1 = ft_printf("%u\n", 42);
// 	// int count2 = printf("%u\n", 42);
// 	int count1 = ft_printf("CHAR %c\nSTRING %s\nPTR %p\nDEC %d\nINT \
// %i\nUNS DEC %u\nLoHEX %x\nUpHEX %X\nPERC %%\n\n", 'c', "str", &c, \
// i, -42, i, 0xFF, 0xFF);
// 	int count2 = printf("CHAR %c\nSTRING %s\nPTR %p\nDEC %d\nINT \
// %i\nUNS DEC %u\nLoHEX %x\nUpHEX %X\nPERC %%\n\n", 'c', "str", &c, \
// i, -42, i, 0xFF, 0xFF);

// 	ft_printf("%d - %d", count1, count2);
// 	return (0);
// }
