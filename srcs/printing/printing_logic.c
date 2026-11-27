/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_logic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrpetr <andrpetr@marvin.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 20:42:44 by andrpetr          #+#    #+#             */
/*   Updated: 2026/11/27 21:32:44 by andrpetr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/ft_printf.h"

int	print_diu(t_data *data, char type)
{
	int	len;

	len = 0;
	if (!data->flags.left)
		len += print_spaces(data->format.spaces);
	if ((type == 'i' || type == 'd'))
	{
		if (data->arg.number < 0)
			len += write(1, "-", 1);
		else if (data->flags.sign)
			len += write(1, "+", 1);
		else if (data->flags.space)
			len += write(1, " ", 1);
	}
	len += print_zeros((data->format.zeros));
	if (!(data->flags.precision && !data->flags.p_size
			&& !data->arg.number))
		len += ft_putnbr_llong(data->arg.number);
	if (data->flags.left)
		len += print_spaces(data->format.spaces);
	return (len);
}

int	print_hex(t_data *data, char type)
{
	int		len;
	char	hex[17];

	len = 0;
	if (!data->flags.left)
		len += print_spaces(data->format.spaces);
	if (data->flags.prefix && data->arg.address_or_hex)
	{
		if (type == 'x')
			len += write(1, "0x", 2);
		else if (type == 'X')
			len += write(1, "0X", 2);
	}
	len += print_zeros((data->format.zeros));
	if (!(data->flags.precision && !data->flags.p_size
			&& !data->arg.address_or_hex))
	{
		convert_to_hex(data->arg.address_or_hex, type, hex);
		len += ft_putstr(hex);
	}
	if (data->flags.left)
		len += print_spaces(data->format.spaces);
	return (len);
}

int	print_s(t_data *data)
{
	int	len;

	len = 0;
	if (!data->flags.left)
		len += print_spaces(data->format.spaces);
	if (data->flags.precision)
		len += write(1, data->arg.string,
				strlen_len(data->arg.string, data->flags.p_size));
	else
		len += ft_putstr(data->arg.string);
	if (data->flags.left)
		len += print_spaces((data->format.spaces));
	return (len);
}

int	print_p(t_data *data)
{
	int		len;
	char	hex[17];

	len = 0;
	if (!data->flags.left)
		len += print_spaces(data->format.spaces);
	if (!data->arg.address_or_hex)
		len += write(1, "(nil)", 5);
	if (data->arg.address_or_hex)
	{
		len += write(1, "0x", 2);
		convert_to_hex(data->arg.address_or_hex, 'x', hex);
		len += ft_putstr((hex));
	}
	if (data->flags.left)
		len += print_spaces((data->format.spaces));
	return (len);
}

int	print_c(t_data *data)
{
	int	len;

	len = 0;
	if (!data->flags.left)
		len += print_spaces((data->format.spaces));
	len += ft_putchar_unsigned(data->arg.number);
	if (data->flags.left)
		len += print_spaces((data->format.spaces));
	return (len);
}
