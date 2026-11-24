/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrpetr <andrpetr@marvin.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:14:15 by andrpetr          #+#    #+#             */
/*   Updated: 2026/11/24 01:33:23 by andrpetr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_data	data;
	char	*input_cast;

	va_start(args, str);
	ft_bzero(&data, sizeof(data));
	data.flags.width = -1;
	input_cast = (char *) str;
	while (*input_cast)
	{
		if (*input_cast == '%')
			input_cast = process_arg(&data, ++input_cast, args);
		else
			data.total_size += write (1, input_cast++, 1);
	}
	va_end(args);
	return (data.total_size);
}