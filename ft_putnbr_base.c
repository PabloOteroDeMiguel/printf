/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:23:14 by potero-d          #+#    #+#             */
/*   Updated: 2021/10/27 15:58:05 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	m;
	unsigned int	n;
	char			c;
	int				i;

	m = ft_strlen(base);
	i = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
		i++;
	}
	n = nbr;
	if (n >= m)
		i += ft_putnbr_base((n / m), base);
	c = base[n % m];
	i++;
	write(1, &c, 1);
	return (i);
}
