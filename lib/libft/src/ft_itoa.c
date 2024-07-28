/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:23:15 by gharazka          #+#    #+#             */
/*   Updated: 2023/10/25 18:23:22 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*num_str;
	int		len;
	int		sign;

	len = numlen(n);
	sign = 1;
	num_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!num_str)
		return (0);
	num_str[len] = 0;
	len--;
	if (n < 0)
	{
		num_str[0] = '-';
		sign = -1;
	}
	if (n == 0)
		num_str[len] = '0';
	while (n != 0)
	{
		num_str[len] = (n % 10 * sign) + '0';
		n /= 10;
		len--;
	}
	return (num_str);
}
