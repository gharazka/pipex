/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:15:23 by gharazka          #+#    #+#             */
/*   Updated: 2023/10/24 19:15:24 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	int		i;
	char	*dest;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	dest = (char *)malloc(size + 1);
	while (s[i] != 0)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
