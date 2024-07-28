/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:54:51 by gharazka          #+#    #+#             */
/*   Updated: 2023/10/18 14:06:09 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int free_s1)
{
	char	*full;
	int		i;
	int		j;

	if (!s2)
		return (s1);
	full = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		full[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		full[i + j] = s2[j];
		j++;
	}
	full[i + j] = 0;
	if (s1 && free_s1)
		free(s1);
	return (full);
}
