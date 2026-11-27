/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrpetr <andrpetr@marvin.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:57:25 by andrpetr          #+#    #+#             */
/*   Updated: 2026/11/27 22:11:16 by andrpetr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/ft_printf.h"

// nb_len is used for precision calculation since "-+ "
// aren't taken into account (yes even the - from a negative number)
// sign_len is used as a boolean to be used in the calculation
// of the width
void	format_diu(t_data *data, char type, va_list args)
{
	int			nb_len;
	int			sign_len;
	int			padding;

	if (type == 'u')
		data->arg.number = va_arg(args, unsigned int);
	else
		data->arg.number = va_arg(args, int);
	nb_len = size_of_int_in_chars(data->arg.number);
	sign_len = 0;
	if (data->flags.precision == 1 && data->flags.p_size == 0
		&& data->arg.number == 0)
		nb_len = 0;
	if ((data->flags.sign || data->arg.number < 0 || data->flags.space)
		&& type != 'u')
		sign_len = 1;
	if ((data->flags.precision == 1 || data->flags.left) && data->flags.zero)
		data->flags.zero = 0;
	if (data->flags.precision && data->flags.p_size - nb_len > 0)
		data->format.zeros = data->flags.p_size - nb_len;
	padding = data->flags.width - data->format.zeros - nb_len - sign_len;
	if (padding > 0 && data->flags.zero)
		data->format.zeros = padding;
	else if (padding > 0)
		data->format.spaces = padding;
}

void	format_hex(t_data *data, va_list args)
{
	int	hex_len;
	int	prefix_len;
	int	padding;

	data->arg.address_or_hex = va_arg(args, unsigned int);
	hex_len = size_of_hex_in_chars(data->arg.address_or_hex);
	prefix_len = 0;
	if (data->flags.precision == 1 && data->flags.p_size == 0
		&& data->arg.address_or_hex == 0)
		hex_len = 0;
	if (data->flags.prefix && data->arg.address_or_hex > 0)
		prefix_len = 2;
	if ((data->flags.precision == 1 || data->flags.left) && data->flags.zero)
		data->flags.zero = 0;
	if (data->flags.precision && data->flags.p_size - hex_len > 0)
		data->format.zeros = data->flags.p_size - hex_len;
	padding = data->flags.width - data->format.zeros - hex_len - prefix_len;
	if (padding > 0 && data->flags.zero)
		data->format.zeros = padding;
	else if (padding > 0)
		data->format.spaces = padding;
}

void	format_s(t_data *data, va_list args)
{
	int	len;
	int	padding;

	data->arg.string = va_arg(args, char *);
	if (data->flags.precision)
		len = strlen_len(data->arg.string, data->flags.p_size);
	else
		len = ft_strlen((data->arg.string));
	padding = data->flags.width - len;
	if (padding > 0)
		data->format.spaces = padding;
}

void	format_p(t_data *data, va_list args)
{
	int		hex_len;
	void	*p;
	int		padding;

	p = va_arg(args, void *);
	data->arg.address_or_hex = (unsigned long long) p;
	hex_len = size_of_hex_in_chars(data->arg.address_or_hex);
	if (data->arg.address_or_hex == 0)
		hex_len = 5;
	else
		hex_len += 2;
	padding = data->flags.width - hex_len;
	if (padding > 0)
		data->format.spaces = padding;
}

void	format_c(t_data *data, va_list args)
{
	int	padding;

	data->arg.number = va_arg(args, int);
	padding = data->flags.width - 1;
	if (padding > 0)
		data->format.spaces = padding;
}
