/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advasseu <advasseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:34:35 by advasseu          #+#    #+#             */
/*   Updated: 2026/11/02 11:20:07 by advasseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!s || !f)
		return (NULL);
	res = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// static char test_mapping(unsigned int index, char c)
// {
//     if (index % 2 == 0 && c >= 'a' && c <= 'z')
//         return (c - 32);
//     return (c);
// }

// int main(void)
// {
//     const char *src = "hello 42";

//     char *result = ft_strmapi(src, test_mapping);

//     printf("ft_strmapi : \"%s\" (adresse : %p)\n", 
// 		result ? result : "NULL", (void *)result);

//     if (result)
//         free(result);

//     return (0);
// }
