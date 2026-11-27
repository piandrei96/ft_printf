/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrpetr <andrpetr@marvin.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 16:35:31 by andrpetr          #+#    #+#             */
/*   Updated: 2026/11/27 21:33:02 by andrpetr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/ft_printf.h"

int	ft_putchar_unsigned(unsigned char c)
{
	return (write(1, &c, 1));
}
