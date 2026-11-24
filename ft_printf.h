/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advasseu <advasseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 09:11:47 by advasseu          #+#    #+#             */
/*   Updated: 2026/11/03 14:37:28 by advasseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

# include "libft/libft.h"

int		ft_printf(const char *base, ...);

int handler_c(char c);
int handler_s(char *str);
int	handler_p(void *ptr);
int	handler_d(int n);
int	handler_u(unsigned int n);

int putnbr_base(int nbr, char *base);

#endif
