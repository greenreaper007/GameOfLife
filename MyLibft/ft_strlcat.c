/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:30:42 by flturbou          #+#    #+#             */
/*   Updated: 2024/10/19 18:41:55 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *restrict src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	lendest;

	i = 0;
	j = 0;
	lendest = ft_strlen(dest);
	while (dest[i])
	{
		i++;
	}
	if (size == 0 || size <= lendest)
		return (ft_strlen(src) + size);
	while (src[j] && j < size - lendest - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (lendest + ft_strlen(src));
}
