/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrpetr <andrpetr@marvin.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:46:17 by andrpetr          #+#    #+#             */
/*   Updated: 2026/11/24 01:31:02 by andrpetr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
