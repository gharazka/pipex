/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:44:09 by gharazka          #+#    #+#             */
/*   Updated: 2023/11/16 20:44:27 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int nb, int fd, int len)
{
	if (nb > 9)
	{
		len++;
		len = ft_putunbr_fd(nb / 10, fd, len);
		ft_putunbr_fd(nb % 10, fd, len);
	}
	if (nb <= 9)
	{
		len++;
		ft_putchar_fd(nb + 48, fd);
	}
	return (len);
}
