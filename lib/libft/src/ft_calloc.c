/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:26:23 by gharazka          #+#    #+#             */
/*   Updated: 2023/10/26 20:20:03 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result_ptr;

	if (nmemb == 0 || size == 0)
	{
		result_ptr = malloc(0);
		return (result_ptr);
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	result_ptr = malloc(size * nmemb);
	if (!result_ptr)
		return (NULL);
	result_ptr = ft_bzero(result_ptr, nmemb * size);
	return (result_ptr);
}
