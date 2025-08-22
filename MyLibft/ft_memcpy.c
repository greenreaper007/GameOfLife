/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:30:42 by flturbou          #+#    #+#             */
/*   Updated: 2024/10/19 23:29:26 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char				*ptr1;
	char				*ptr2;
	unsigned int		i;

	if (!src)
		return (NULL);
	if ((dest < src && dest + n >= src) || (dest > src && dest - n <= src))
		return (ft_memmove(dest, src, n));
	ptr1 = (char *)src;
	ptr2 = (char *)dest;
	i = 0;
	while (n > i)
	{
		ptr2[i] = ptr1[i];
		i++;
	}
	return (dest);
}
