/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:58:57 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/15 18:30:35 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int nbr)
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

void	hex_str(unsigned int n, const char form)
{
	if (n >= 16)
	{
		hex_str(n / 16, form);
		hex_str(n % 16, form);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (form == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			else if (form == 'X')
				ft_putchar_fd((n -10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int n, const char form)
{
	int		len;

	len = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	hex_str(n, form);
	len += ft_hex_len(n);
	return (len);
}
