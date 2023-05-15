/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:06:44 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/15 18:18:49 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_print_chr(char c);
int	ft_print_str(char *str);
int	ft_print_nbr(int nbr);
int	ft_nbrlen(unsigned int nbr, unsigned int base);
int	ft_print_unsig(unsigned int nbr);
int	ft_print_pointer(unsigned long ptr);
int	ft_print_hex(unsigned int n, const char form);

#endif