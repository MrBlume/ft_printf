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
# include <unistd.h>
# include <stdarg.h>

# include "libft/libft.h"

int		ft_printf(const char *base, ...);

void	handler_c(char c);
void	handler_s(char *str);
void	handler_p(char *ptr);
void	handler_d(int n);
void	handler_i(int n);
void	handler_u(unsigned int n);
void	handler_x(int n);
void	handler_X(int n);

#endif