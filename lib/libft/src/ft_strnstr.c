/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:14:16 by gharazka          #+#    #+#             */
/*   Updated: 2023/10/26 23:46:16 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big[i] != 0 && i < len)
	{
		while (big[i + j] == little[j] && i + j < len)
		{
			j++;
			if (little[j] == 0)
				return ((char *)(&big[i]));
		}
		j = 0;
		i++;
	}
	return (0);
}
