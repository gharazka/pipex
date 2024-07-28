/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:24:00 by gharazka          #+#    #+#             */
/*   Updated: 2023/10/17 22:25:36 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
	{
		i = ft_putstr_fd("(null)", 1);
		return (i);
	}
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}
