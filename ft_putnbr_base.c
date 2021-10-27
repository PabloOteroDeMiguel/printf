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

int	ft_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_check_base(char *str)
{
	int	i;
	int	j;
	int	n;

	n = ft_len(str);
	i = 0;
	if (n < 2)
		return (0);
	else if (n >= 2)
	{
		while (str[i] != '\0')
		{
			if ((str[i] == '+') || (str[i] == '-'))
				return (0);
			j = i + 1;
			while (str[j] != '\0')
			{
				if (str[i] == str[j])
					return (0);
				j++;
			}
			i++;
		}
	}
	return (1);
}

int	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	m;
	unsigned int	n;
	char			c;
	int				i;
	int				a;

	m = ft_len(base);
	a = ft_check_base(base);
	i = 0;
    if (nbr == 0)
        write(1, &base[0], 1);
	else if (a == 1)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = nbr * -1;
			i++;
		}
		n = nbr;
		if (n >= m)
			ft_putnbr_base((n / m), base);
		c = base[n % m];
		write(1, &c, 1);
		i++;
	}
	return (i);
}
