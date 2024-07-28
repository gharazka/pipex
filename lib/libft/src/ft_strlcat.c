/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:39:01 by gharazka          #+#    #+#             */
/*   Updated: 2023/10/27 00:05:47 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (i < size - 1 && size > 0)
	{
		while (src[j] && i + j < size - 1)
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = 0;
	}
	if (size <= i)
		i = size;
	return (i + ft_strlen(src));
}
