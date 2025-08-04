/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:55:37 by anvilla-          #+#    #+#             */
/*   Updated: 2025/02/24 19:52:33 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printptr(unsigned long long ptr);
int	ft_printdigit(int n);
int	ft_printunsigned(unsigned int n);
int	ft_printhex(unsigned int n, char format);

#endif
