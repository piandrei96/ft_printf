/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_and_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrpetr <andrpetr@marvin.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 20:31:08 by andrpetr          #+#    #+#             */
/*   Updated: 2026/11/27 21:32:17 by andrpetr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/ft_printf.h"

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

char	*update_flags(t_data *data, char *input)
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

void	update_format(t_data *data, char *input, va_list args)
{
	if (*input == 'd' || *input == 'i' || *input == 'u')
		format_diu(data, *input, args);
	else if (*input == 'x' || *input == 'X')
		format_hex(data, args);
	else if (*input == 'p')
		format_p(data, args);
	else if (*input == 's')
		format_s(data, args);
	else if (*input == 'c')
		format_c(data, args);
}
