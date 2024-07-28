/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:23:34 by gharazka          #+#    #+#             */
/*   Updated: 2023/10/27 00:08:52 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	ft_issign(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	return (0);
}

static int	get_result(const char *str, int result, int i)
{
	while ((str[i] != 0 && ft_isdigit(str[i])))
	{
		result += (str[i] - 48);
		if (!(result > 1000000000 || result < -1000000000))
			result *= 10;
		i++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 0;
	while (str[i] != 0 && !ft_isdigit(str[i]))
	{
		if ((!ft_isspace(str[i]) && !ft_issign(str[i]))
			|| ((ft_issign(str[i]) || ft_isspace(str[i])) && sign != 0))
			return (0);
		if (ft_issign(str[i]) != 0)
			sign = ft_issign(str[i]);
		i++;
	}
	result = get_result(str, result, i);
	if (result < 1000000000 && result > -1000000000)
		result /= 10;
	if (sign)
		result *= sign;
	return (result);
}
