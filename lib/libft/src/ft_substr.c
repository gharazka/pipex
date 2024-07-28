/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:21:01 by gharazka          #+#    #+#             */
/*   Updated: 2023/10/25 18:43:31 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	size_t			size;
	char			*substr;

	i = 0;
	j = 0;
	while (s[i] && i < start)
		i++;
	if (ft_strlen(&s[i]) > len)
		size = len;
	else
		size = ft_strlen(&s[i]);
	substr = (char *)malloc(sizeof(char) * size + 1);
	if (!substr)
		return (NULL);
	while (s[i + j] && j < len)
	{
		substr[j] = s[i + j];
		j++;
	}
	substr[j] = 0;
	return (substr);
}
