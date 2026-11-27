/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrpetr <andrpetr@marvin.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:46:17 by andrpetr          #+#    #+#             */
/*   Updated: 2026/11/27 21:32:06 by andrpetr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/ft_printf.h"

int	size_of_int_in_chars(long long nb)
{
	int	size;

	size = 1;
	while (nb / 10 != 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

int	size_of_hex_in_chars(unsigned long long nb)
{
	int	size;

	size = 1;
	while (nb / 16 != 0)
	{
		nb /= 16;
		size++;
	}
	return (size);
}

int	size_of_phex_in_chars(unsigned long long nb)
{
	int	size;

	size = 1;
	while (nb / 16 != 0)
	{
		nb /= 16;
		size++;
	}
	return (size);
}

int	check_char(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
