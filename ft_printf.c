/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:46:22 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/15 18:21:38 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//-printf retorna a qunatidade de caracteries impressos;
//-ft_args verifica qual flag foi passada e especifica a funcao de impressao; 

#include "ft_printf.h"

int	ft_form(const char *str, va_list args, size_t i)
{
	int	count;

	count = 0;
	if (str[i + 1] == '%')
		count += (ft_print_chr(str[i + 1]));
	else if (str[i + 1] == 'c')
		count += (ft_print_chr(va_arg(args, int)));
	else if (str[i + 1] == 's')
		count += (ft_print_str(va_arg(args, char *)));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		count += (ft_print_nbr(va_arg(args, int)));
	else if (str[i + 1] == 'u')
		count += (ft_print_unsig(va_arg(args, unsigned int)));
	else if (str[i + 1] == 'p')
		count += (ft_print_pointer(va_arg(args, unsigned long)));
	else if (str[i + 1] == 'x' || str[i + 1] == 'X')
		count += (ft_print_hex(va_arg(args, unsigned int), str[i + 1]));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			ret += ft_form(str, args, i);
			i++;
		}
		else
		{
			ft_print_chr(str[i]);
			ret++;
		}
		i++;
	}
	va_end(args);
	return (ret);
}
