/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrpetr <andrpetr@marvin.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:40:23 by andrpetr          #+#    #+#             */
/*   Updated: 2026/11/27 22:28:11 by andrpetr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/ft_printf.h"

static char	*print_argument(t_data *data, char *input)
{
	if (*input == 'd' || *input == 'u' || *input == 'i')
		data->total_size += print_diu(data, *input);
	else if (*input == 'x' || *input == 'X')
		data->total_size += print_hex(data, *input);
	else if (*input == 'p')
		data->total_size += print_p(data);
	else if (*input == 's')
		data->total_size += print_s(data);
	else if (*input == 'c')
		data->total_size += print_c(data);
	else if (*input == '%')
	{
		data->total_size += write(1, "%", 1);
	}
	if (*input)
		input++;
	return (input);
}

char	*process_arg(t_data *data, char *input, va_list args)
{
	input = update_flags(data, input);
	update_format(data, input, args);
	input = print_argument(data, input);
	return (input);
}
