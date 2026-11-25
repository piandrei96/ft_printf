/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_format_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrpetr <andrpetr@marvin.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:57:25 by andrpetr          #+#    #+#             */
/*   Updated: 2026/11/24 01:41:32 by andrpetr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	format_xX(t_data *data, va_list args)
{
	int	hex_len;
	int	prefix_len;
	int	padding;

	data->arg.number = va_arg(args, unsigned int);
	hex_len = size_of_hex_in_chars(data->arg.number);
	prefix_len = 0;
	if (data->flags.precision == 1 && data->flags.p_size == 0
		&& data->arg.number == 0)
		hex_len = 0;
	if (data->flags.prefix && data->arg.number > 0)
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
	len = ft_strlen(data->arg.string);
	if (data->flags.precision == 1 && data->flags.p_size == 0)
		len = 0;
	if (data->flags.precision && data->flags.p_size - len < 0)
		len = data->flags.precision;
	padding = data->flags.width - len;
	if (padding)
		data->format.spaces = padding;
}

void	format_p()
{
	
}

void	format_c()
{
	
}