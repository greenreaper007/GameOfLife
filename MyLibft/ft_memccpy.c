/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:30:42 by flturbou          #+#    #+#             */
/*   Updated: 2024/10/19 18:40:50 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char				*ptr1;
	char				*ptr2;
	unsigned int		i;

	ptr1 = (char *)src;
	ptr2 = (char *)dest;
	i = 0;
	while (ptr1[i] != c && i < n)
		i++;
	n = i;
	i = 0;
	while (n > i)
	{
		ptr2[i] = ptr1[i];
		i++;
	}
	if (ptr1[i] == c)
		return (ptr2[i] = ptr1[i], &ptr2[i + 1]);
	return (NULL);
}
