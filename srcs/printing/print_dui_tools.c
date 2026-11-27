/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dui_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrpetr <andrpetr@marvin.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 13:18:46 by andrpetr          #+#    #+#             */
/*   Updated: 2026/11/27 21:32:32 by andrpetr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/ft_printf.h"

int	ft_putnbr_llong(long long n)
{
	int	len;

	len = 0;
	if (n == LLONG_MIN)
	{
		len = write (1, "-9223372036854775808", 20);
		return (len);
	}
	if (n < 0)
		n = -n;
	if (n <= 9)
		len += ft_putchar_unsigned(n + '0');
	if (n > 9)
	{
		len += ft_putnbr_llong(n / 10);
		len += ft_putchar_unsigned(n % 10 + '0');
	}
	return (len);
}
