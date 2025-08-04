/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:30:19 by anvilla-          #+#    #+#             */
/*   Updated: 2025/07/12 19:23:41 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_message(void)
{
	write(1, "./fractol <Mandelbrot> or <Julia (2 to -2)(2 to -2)>\n", 54);
	exit(0);
}

void	error_mandelbrot(void)
{
	write(1, "Use: ./fractol Mandelbrot\n", 27);
	exit(0);
}

void	error_julia(void)
{
	write(1, "Use: ./fractol Julia (2 to -2) (2 to -2)\n", 42);
	write(1, "ex: -0.7 0.27015\n", 18);
	write(1, "ex: -0.76 -0.06\n", 16);
	write(1, "ex: -0.8 0.156\n", 16);
	write(1, "ex: 0.285 0.011\n", 17);
	write(1, "ex: 0.355 0.355\n", 17);
	exit(0);
}

void	check_number(const char *str)
{
	double	nbr;

	nbr = ft_atod(str);
	if (nbr > 2.0 || nbr < -2.0)
		error_julia();
}

int	check_name(int argc, char **argv, t_struct *s)
{
	if (argc < 2)
		error_message();
	if (!ft_strcmp(argv[1], "Mandelbrot"))
	{
		if (argc > 2)
			error_mandelbrot();
		return (1);
	}
	if (!ft_strcmp(argv[1], "Julia"))
	{
		if ((!argv[2] || !argv[3]) || argc > 4)
			error_julia();
		check_number(argv[2]);
		check_number(argv[3]);
		s->os_x = ft_atod(argv[2]);
		s->os_y = ft_atod(argv[3]);
		return (2);
	}
	else
		error_message();
	return (0);
}
