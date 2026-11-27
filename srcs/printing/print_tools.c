/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrpetr <andrpetr@marvin.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 20:21:12 by andrpetr          #+#    #+#             */
/*   Updated: 2026/11/27 21:32:39 by andrpetr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/ft_printf.h"

int	print_spaces(int howmany)
{
	int	i;

	i = 0;
	while (i < howmany)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int	print_zeros(int howmany)
{
	int	i;

	i = 0;
	while (i < howmany)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}

char	*convert_to_hex(unsigned long long nb, char type, char *hex)
{
	const char	*hextable;
	const char	*hextable_big;
	int			len;

	hextable = "0123456789abcdef";
	hextable_big = "0123456789ABCDEF";
	len = size_of_hex_in_chars(nb);
	hex[len] = '\0';
	len--;
	while (len >= 0)
	{
		if (type == 'x')
			hex[len] = hextable[nb % 16];
		else
			hex[len] = hextable_big[nb % 16];
		nb /= 16;
		len--;
	}
	return (hex);
}

int	putstr_len(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len && str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	strlen_len(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len && str[i])
		i++;
	return (i);
}
