/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advasseu <advasseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 09:33:03 by advasseu          #+#    #+#             */
/*   Updated: 2026/11/26 09:53:57 by advasseu         ###   ########.fr       */
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
int	putnbr_ubase(unsigned long nbr, const char *base);

#endif
