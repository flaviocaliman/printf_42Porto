/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:56:41 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/13 15:12:30 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//I didn't understand why "i - 1";
#include "ft_printf.h"

char	*ft_itoa_u(unsigned int u)
{
	char			*str;
	int				i;
	unsigned int	aux;

	i = ft_nbrlen(u, 10);
	aux = u;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (aux == 0)
		str[0] = '0';
	str[i--] = '\0';
	while (aux)
	{
		str[i--] = (aux % 10) + '0';
		aux = aux / 10;
	}
	return (str);
}

int	ft_print_unsig(unsigned int nbr)
{
	char	*str;
	int		len;

	str = ft_itoa_u(nbr);
	len = ft_print_str(str);
	free(str);
	return (len);
}
