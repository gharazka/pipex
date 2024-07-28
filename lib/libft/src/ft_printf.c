/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:40:54 by gharazka          #+#    #+#             */
/*   Updated: 2023/11/16 21:11:24 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sign(char c, va_list args)
{
	int		len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		len = ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'i' || c == 'd')
		len = ft_putnbr_fd(va_arg(args, int), 1, 0);
	else if (c == 'u')
		len += ft_putunbr_fd(va_arg(args, unsigned int), 1, 0);
	else if (c == 'x')
		len += ft_puthex_fd(va_arg(args, unsigned int), 0, 0);
	else if (c == 'p')
		len += ft_putmemory_fd(va_arg(args, unsigned long long int));
	else if (c == 'X')
		len += ft_putcaphex_fd(va_arg(args, unsigned int), 0, 0);
	else
		len += ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += check_sign(str[i + 1], args);
			i += 2;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
			len++;
		}
	}
	va_end(args);
	return (len);
}
