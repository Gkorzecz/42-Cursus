/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkorzec <gkorzecz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:57:29 by gkorzec           #+#    #+#             */
/*   Updated: 2024/05/31 12:33:58 by gkorzec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_write(char *s, int i, long nbr)
{
	if (nbr < 0)
	{
		s[0] = '-';
		nbr = -nbr;
	}
	while (i >= 0 && s[i] != '-')
	{
		s[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*s;
	long	nbr;

	nbr = n;
	i = intlen(n) - 1;
	s = (char *)malloc((sizeof(char) * i) + 2);
	if (s == NULL)
		return (NULL);
	s[i + 1] = '\0';
	ft_write(s, i, nbr);
	return (s);
}
