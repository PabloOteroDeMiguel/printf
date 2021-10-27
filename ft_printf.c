/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:39:56 by potero-d          #+#    #+#             */
/*   Updated: 2021/10/27 16:02:27 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_character(char c, va_list ap, int *cont)
{
	if (c == 'c')
		*cont += ft_putchar_fd(va_arg(ap, int), 1);
	else if (c == 's')
		*cont += ft_putstr_fd(va_arg(ap, char*), 1);
/*	else if	(c == 'p')
		ft_putnbr_base(va_arg(ap, void*), "0123456789abcdef");*/
	else if (c == 'd')
		*cont += ft_putnbr_base(va_arg(ap, int), "0123456789");
	else if (c == 'i')
		*cont += ft_putnbr_base(va_arg(ap, int), "0123456789");
/*	else if (c == 'u')
		*cont += ft_putnbr_base(va_arg(ap,long int), "0123456789");*/
	else if (c == 'x')
		*cont += ft_putnbr_base(va_arg(ap, int), "0123456789abcdef");
	else if (c == 'X')
		*cont += ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
	else
		*cont += ft_putchar_fd(c, 1);
}

int	ft_printf(const char *str, ...)
{
	int		cont;
	int		i;
	va_list	ap;

	cont = 0;
	i = 0;
	if (!str)
		return (0);
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			ft_character(str[i], ap, &cont);
		}
		else
		{
			write(1, &str[i], 1);
			cont++;
		}
		i++;
	}
	va_end(ap);
	return (cont);
}
