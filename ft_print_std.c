/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_std.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:19:45 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/13 17:38:58 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_print_chr eh uma personalizacao da putchar();
// ft_print_str eh uma personalizacao da putstr();

#include "ft_printf.h"

//I need to understand better the function below
int	ft_nbrlen(unsigned int nbr, unsigned int base)
{
	int	i;

	i = 0;
	if (nbr == 0)
	{
		i = 1;
		return (i);
	}
	while (nbr)
	{
		i++;
		nbr /= base;
	}
	return (i);
}

int	ft_print_chr(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	len;

	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write (1, str, len);
	return (len);
}

int	ft_print_nbr(int nbr)
{
	char	*str;
	int		len;

	str = ft_itoa(nbr);
	len = ft_print_str(str);
	free(str);
	return (len);
}
