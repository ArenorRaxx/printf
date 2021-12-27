/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:44:27 by mcorso            #+#    #+#             */
/*   Updated: 2021/12/27 14:02:53 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		count(int mod);
int		ft_printf(const char *format, ...);
int		is_in_set(char c, const char *charset);
int		ft_print_format(const char c, va_list args);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_format(char c, va_list args);
void	ft_putnbr_base(long num, char *base);

#endif