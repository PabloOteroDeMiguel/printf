/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:23:39 by potero-d          #+#    #+#             */
/*   Updated: 2021/10/27 14:12:08 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"ft_printf.h"

int	main(void)
{
/*	printf("u -90: %u\n", -90);
	ft_printf("No soy un robot\n");
	printf("cont: %d\n", ft_printf("No soy un robot\n"));*/

	ft_printf("Hola %s\n", "Robot");
	ft_printf("%c\n", 'p');
	ft_printf("d: %p\n", "Robot");
	ft_printf("%d  %d\n", -48, 300595);
	

	printf("d -30000595: %d\n", -30000595);
	printf("i -30000595: %i\n", -30000595);
	printf("u -30000595: %u\n", -30000595);
}
