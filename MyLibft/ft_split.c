/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:58:20 by flturbou          #+#    #+#             */
/*   Updated: 2024/10/19 23:23:53 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	if (c == 0)
		return (-1);
	if (s[0] == c)
	{
		count = 0;
		while (s[i] == c && s[i])
			i++;
	}
	while (s[i])
	{
		count++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c)
			i++;
	}
	return (count);
}

void	free_split(char **res, int wc)
{
	while (wc)
	{
		free(res[wc]);
		wc--;
	}
	free(res[wc]);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		wc;

	j = 0;
	wc = 0;
	res = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (s[j] == c && s[j])
		j++;
	while (s[j])
	{
		i = j;
		while (s[j] != c && s[j])
			j++;
		res[wc] = ft_strsub(s, i, j - i);
		if (!res[wc])
			return (free_split(res, wc), free(res), NULL);
		wc++;
		while (s[j] == c)
			j++;
	}
	return (res[wc] = NULL, res);
}
