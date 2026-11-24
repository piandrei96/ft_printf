/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrpetr <andrpetr@marvin.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:13:33 by andrpetr          #+#    #+#             */
/*   Updated: 2026/11/24 01:55:45 by andrpetr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	int	prefix;
	int	left;
	int	sign;
	int	space;
	int	zero;	
	int	width;
	int	precision;
	int	p_size;
}	t_flags;

typedef struct s_format
{
	int		spaces;
	int		zeros;
}	t_format;

typedef union	u_arg
{
	long long	number;
	char		*string;
	char		xXp[17];
}	t_arg;

typedef struct s_data
{
	t_flags		flags;
	t_format	format;
	int			total_size;
	t_arg		arg;	
}	t_data;




char	*process_arg(t_data *data, char *input, va_list args);


// TOOLS

int		check_char(char c, char const *set);
int		size_of_int_in_chars(long long nb);

// MINILIB

void	ft_bzero(void *s, size_t n);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);

// FORMAT HELPERS

void	format_diu(t_data *data, char type, va_list args);

#endif