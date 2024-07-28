/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:47:17 by gharazka          #+#    #+#             */
/*   Updated: 2023/11/16 20:47:36 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_fd(unsigned long long int n, unsigned long int temp, int len)
{
	while (n >= 16)
	{
		temp = n / 16;
		n = n - (16 * temp);
	}
	len++;
	if (temp > 0)
		len = ft_puthex_fd(temp, 0, len);
	if (n <= 9)
		ft_putnbr_fd(n, 1, 0);
	if (n > 9)
		ft_putchar_fd(n + 'W', 1);
	return (len);
}
