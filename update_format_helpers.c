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
	if ((data->flags.sign || nb < 0 || data->flags.space) && type != 'u')
		sign_len = 1;
	if ((data->flags.precision == 1 || data->flags.left) && data->flags.zero)
		data->flags.zero = 0;
	if (data->flags.precision && data->flags.p_size - nb_len > 0)
		data->format.zeros = data->flags.p_size - nb_len;
	padding = data->flags.width - data->format.zeros;
	padding -= (nb_len + sign_len);
	if (padding > 0 && data->flags.zero)
		data->format.zeros = padding;
	else if (padding > 0)
		data->format.spaces = padding;
}

void	format_xX()
{
		data->arg.number = va_arg(args, unsigned int);
}

void	format_s()
{
	
}

void	format_p()
{
	
}

void	format_c()
{
	
}