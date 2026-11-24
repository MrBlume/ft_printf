/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advasseu <advasseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 09:16:08 by advasseu          #+#    #+#             */
/*   Updated: 2026/11/10 09:45:39 by advasseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *base, ...)
{
	va_list	vars;
	int		count;

	count = 0;
	va_start(vars, base);
	while (*base)
	{
		if (*base == '%')
		{
			base++;
			if (*base == 'c')
				count += handler_c((char)va_arg(vars, int));
			if (*base == 's')
				count += handler_s(va_arg(vars, char *));
			if (*base == 'p')
				count += handler_p((void *)va_arg(vars, char *));
			if (*base == 'd' || *base == 'i')
				count += handler_d((int)va_arg(vars, int));
			if (*base == 'u')
				count += putnbr_base((int)va_arg(vars, int), "0123456789");
			if (*base == 'x')
				count += putnbr_base((int)va_arg(vars, int), "0123456789abcdef");
			if (*base == 'X')
				count += putnbr_base((int)va_arg(vars, int), "0123456789ABCDEF");
			if (*base == '%')
				count += write(1, "%", 1);
		}
		else
			count += write(1, base, 1);
		base++;
	}
	va_end(vars);
	return (count);
}

// int	main(void)
// {
// 	char	*c = "test";
// 	unsigned int i = 42;
// 	// int count1 = ft_printf("%u\n", 42);
// 	// int count2 = printf("%u\n", 42);
// 	int count1 = ft_printf("CHAR %c\nSTRING %s\nPTR %p\nDEC %d\nINT %i\nUNS DEC %u\nLoHEX %x\nUpHEX %X\nPERC %%\n\n", 'c', "str", &c, i, -42, i, 0xFF, 0xFF);
// 	int count2 = printf("CHAR %c\nSTRING %s\nPTR %p\nDEC %d\nINT %i\nUNS DEC %u\nLoHEX %x\nUpHEX %X\nPERC %%\n\n", 'c', "str", &c, i, -42, i, 0xFF, 0xFF);

// 	ft_printf("%d - %d", count1, count2);
// 	return (0);
// }
