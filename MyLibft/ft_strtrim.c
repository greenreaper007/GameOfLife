/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:43:22 by flturbou          #+#    #+#             */
/*   Updated: 2024/10/20 17:34:22 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isblanky(int c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (ft_strlen(s) == 0)
		return (res = ft_strnew(1), res);
	j = ft_strlen(s) - 1;
	while (isblanky(s[i], set))
		i++;
	while (j > 0 && isblanky(s[j], set))
		j--;
	if (j == 0)
	{
		if (isblanky(s[0], set))
			return (res = ft_strnew(1), res);
		return (res = ft_strnew(2), res[0] = s[0], res);
	}
	res = ft_strsub(s, i, j - i + 1);
	return (res);
}
