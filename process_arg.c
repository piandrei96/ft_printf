/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrpetr <andrpetr@marvin.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:40:23 by andrpetr          #+#    #+#             */
/*   Updated: 2026/11/24 01:38:50 by andrpetr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*set_flags(t_data *data, char *input)
{
	while (check_char(*input, "#-+ 0") == 1)
	{
		if (*input == '#')
			data->flags.prefix = 1;
		else if (*input == '-')
			data->flags.left = 1;
		else if (*input == ' ')
			data->flags.space = 1;
		else if (*input == '0')
			data->flags.zero = 1;
		else if (*input == '+')
			data->flags.sign = 1;
		input++;
	}
	return (input);
}

char	*update_flags(t_data *data, char *input, va_list args)
{
	ft_bzero(&data->flags, sizeof(t_flags));
	ft_bzero(&data->format, sizeof(data->format));
	data->flags.width = -1;
	input = set_flags(data, input);
	if (ft_isdigit(*input))
	{
		data->flags.width = ft_atoi(input);
		while (ft_isdigit(*input))
			input++;
	}
	if (*input == '.')
	{
		data->flags.precision = 1;
		data->flags.p_size = ft_atoi(++input);
		while (ft_isdigit(*input))
			input++;
	}
	return (input);
}

char	*update_format(t_data *data, char *input, va_list args)
{
	if (*input == 'd' || *input == 'i' || *input == 'u')
		format_diu(data, *input, args);
	else if (*input == 'x' || *input == 'X')
		
	else if (*input == 'p')

	else if (*input == 's')

	else if (*input == 'c')

}

char	*process_arg(t_data *data, char *input, va_list args)
{
	input = update_flags(data, input, args);
	update_format(data, input, args);
	print_format(data, args);
	input = print_argument(data, args);
	if (data->flags.left)
		print_spaces();
	return (input);	
}
