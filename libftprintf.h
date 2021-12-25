/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:44:27 by mcorso            #+#    #+#             */
/*   Updated: 2021/12/25 12:00:12 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
	int 	ft_printf(const char *format, ...);
	int		is_in_set(char c, const char *charset);
	int		ft_print_format(const char **format, va_list args);
	void	ft_putchar(char c);
	void	ft_format(char c, va_list args);
#endif