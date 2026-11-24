/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blume <blume@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 09:33:03 by advasseu          #+#    #+#             */
/*   Updated: 2026/11/24 17:32:33 by blume            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *base, ...);

int	handler_c(char c);
int	handler_s(char *str);
int	handler_p(void *ptr);

int	putnbr_base(long nbr, char *base);
int	putnbr_unsigned_base(unsigned long nbr, const char *base);

#endif
