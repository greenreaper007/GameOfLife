/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:30:42 by flturbou          #+#    #+#             */
/*   Updated: 2024/10/19 23:29:34 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char				*ptr1;
	char				*ptr2;
	unsigned int		i;

	if (!src)
		return (NULL);
	if (!((dest < src && dest + n >= src) || (dest > src && dest - n <= src)))
		return (ft_memcpy(dest, src, n));
	ptr1 = (char *)src;
	ptr2 = malloc(n * sizeof(char));
	i = 0;
	while (i < n)
	{
		ptr2[i] = ptr1[i];
		i++;
	}
	ptr1 = (char *)dest;
	i = 0;
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	free(ptr2);
	return (dest);
}
