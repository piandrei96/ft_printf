/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrpetr <andrpetr@marvin.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:13:33 by andrpetr          #+#    #+#             */
/*   Updated: 2026/11/27 21:35:42 by andrpetr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

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

typedef union u_arg
{
	long long				number;
	unsigned long long		address_or_hex;
	char					*string;
}	t_arg;

typedef struct s_data
{
	t_flags		flags;
	t_format	format;
	int			total_size;
	t_arg		arg;
	long long	arg_total_len;
}	t_data;

int		ft_printf(const char *str, ...);
char	*process_arg(t_data *data, char *input, va_list args);

// FLAGS

char	*set_flags(t_data *data, char *input);
char	*update_flags(t_data *data, char *input);

// FORMAT

void	update_format(t_data *data, char *input, va_list args);
void	format_diu(t_data *data, char type, va_list args);
void	format_hex(t_data *data, va_list args);
void	format_s(t_data *data, va_list args);
void	format_p(t_data *data, va_list args);
void	format_c(t_data *data, va_list args);

// PRINT

int		print_diu(t_data *data, char type);
int		print_hex(t_data *data, char type);
int		print_s(t_data *data);
int		print_p(t_data *data);
int		print_c(t_data *data);

	//PRINT TOOLS
int		print_spaces(int howmany);
int		print_zeros(int howmany);
int		ft_putnbr_llong(long long n);
char	*convert_to_hex(unsigned long long nb, char type, char *hex);

// TOOLS

int		check_char(char c, char const *set);
int		size_of_int_in_chars(long long nb);
int		size_of_hex_in_chars(unsigned long long nb);
// It checks if a \0 is before the end of the precision count
int		strlen_len(char *str, int len);

// MINILIB

void	ft_bzero(void *s, size_t n);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *str);
int		ft_putchar_unsigned(unsigned char c);
int		ft_putstr(char *str);

#endif
