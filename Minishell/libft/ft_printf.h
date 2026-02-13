/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:34:36 by jonamart          #+#    #+#             */
/*   Updated: 2024/10/16 15:22:59 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_reader
{
	int		space;
	int		dot;
	int		hash;
	int		minus;
	int		zero;
	int		plus;
	int		number;
	char	*min_w;
	char	*max_w;
}	t_reader;

void			number_convert_hex(unsigned long long int num,
					char *s, int cap);
int				count_number_hex(unsigned long long int num);
int				ft_putstring(char *s);
int				ft_print_string(char *str, t_reader *rd);
long long int	manage_neg_hex(long long int i);
int				ft_print_pointer(void *p, t_reader *rd);
int				print_format(char format, va_list ap, t_reader *rd);
int				ft_printf(char const *format, ...);
int				ft_putchar(int c);
int				ft_print_char(int c, t_reader *rd);
int				ft_print_hex(unsigned long long int nbr, int cap, t_reader *rd);
int				ft_print_number(long long int lnb, t_reader *rd);
int				print_count_digit(long long int nb);
//int				ft_pow(int number);
int				ft_print_unsigned(unsigned int ui, t_reader *rd);
char			*ft_fill(char *s, int n, int c, int fin);
int				ft_mini_atoi(char *str);
char			*print_get_vector(int len);
t_reader		*new_reader(void);
void			free_reader(t_reader **rd);
//char			*ft_strdup(const char *s1);
//char			*ft_strjoin(char const *s1, char const *s2);
//int				ft_strlen(const char *str);
void			read_format(const char **format, t_reader *rd);
char			*ft_cut(char *s, int n);
char			*ft_itoa(int n);
void			clear_reader(t_reader **rd);
int				ft_print_percent(int c, t_reader *rd);
#endif
