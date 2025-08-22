/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:30:42 by flturbou          #+#    #+#             */
/*   Updated: 2024/10/19 19:02:10 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *find, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (find[0] == 0)
		return (str);
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] == find[j] && find[j] && i + j < n)
			j++;
		if (find[j] == 0)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
