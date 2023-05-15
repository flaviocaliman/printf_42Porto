/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:32:58 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/13 18:04:46 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_point_len(unsigned long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		i++;
		nbr /= 16;
	}
	return (i);
}

void	hex_to_str(unsigned long nbr)
{
	if (nbr >= 16)
	{
		hex_to_str(nbr / 16);
		hex_to_str(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), 1);
		else
			ft_putchar_fd((nbr - 10 + 'a'), 1);
	}
}

int	ft_print_pointer(unsigned long ptr)
{
	unsigned int	len;

	len = 0;
	if (ptr == 0)
		len = ft_print_str("(nil)");
	else
	{
		len = ft_print_str("0x");
		hex_to_str(ptr);
		len += ft_point_len(ptr);
	}
	return (len);
}
