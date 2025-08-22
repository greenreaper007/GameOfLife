/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:30:42 by flturbou          #+#    #+#             */
/*   Updated: 2024/10/19 18:46:05 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *find)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (find[0] == 0)
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == find[j] && find[j])
			j++;
		if (find[j] == 0)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
