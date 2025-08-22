/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:12:37 by flturbou          #+#    #+#             */
/*   Updated: 2024/10/20 17:28:06 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_recitoa(char *res, long nbr, int i)
{
	if (nbr > 9)
		ft_recitoa(res, nbr / 10, i - 1);
	res[i] = (nbr % 10) + '0';
}

int	sizeitoa(long nbr, int i)
{
	if (nbr < 0)
	{
		nbr = nbr * -1;
		return (sizeitoa(nbr, i + 1));
	}
	if (nbr > 9)
		return (sizeitoa(nbr / 10, i + 1));
	return (i + 2);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nbr;
	long	test;
	int		i;

	nbr = n;
	i = 0;
	res = (char *)malloc(sizeitoa(nbr, 0) * sizeof(char));
	if (!res)
		return (NULL);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		res[0] = '-';
		i++;
	}
	test = nbr;
	while (test > 9)
	{
		test = test / 10;
		i++;
	}
	return (res[i + 1] = 0, ft_recitoa(res, nbr, i), res);
}
