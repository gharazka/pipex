/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:02:53 by gharazka          #+#    #+#             */
/*   Updated: 2023/10/28 20:20:59 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (check_set(s1[i], set) && s1[i])
	{
		i++;
	}
	return (i);
}

static int	end(char const *s1, char const *set)
{
	int	len;

	len = ft_strlen(s1) - 1;
	while (check_set(s1[len], set) && s1[len])
	{
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_i;
	int		end_i;
	int		j;
	char	*result;

	start_i = start(s1, set);
	end_i = end(s1, set);
	if (start_i > end_i)
	{
		result = malloc(1);
		result[0] = 0;
		return (result);
	}
	result = (char *)malloc(sizeof(char) * (end_i - start_i + 2));
	if (!result)
		return (NULL);
	j = 0;
	while (start_i <= end_i)
	{
		result[j] = s1[start_i];
		j++;
		start_i++;
	}
	result[j] = 0;
	return (result);
}
