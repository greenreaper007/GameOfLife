/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:30:42 by flturbou          #+#    #+#             */
/*   Updated: 2024/10/19 18:45:53 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *restrict src, size_t sz)
{
	unsigned int	i;

	i = 0;
	if (sizeof(dest) < sz)
		sz = sizeof(dest);
	printf("%d\n", sizeof(dest) < sz);
	while (i < sz)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
