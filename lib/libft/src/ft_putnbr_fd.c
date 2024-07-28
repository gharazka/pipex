/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:50:27 by gharazka          #+#    #+#             */
/*   Updated: 2023/10/18 14:04:41 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int nb, int fd, int len)
{
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		len = ft_putnbr_fd(147483648, fd, 2);
		return (len);
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		len = ft_putnbr_fd(-nb, fd, 1);
		return (len);
	}
	if (nb > 9)
	{
		len++;
		len = ft_putnbr_fd(nb / 10, fd, len);
		ft_putnbr_fd(nb % 10, fd, len);
	}
	if (nb <= 9)
		len += ft_putchar_fd(nb + 48, fd);
	return (len);
}
