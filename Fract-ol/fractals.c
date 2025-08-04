/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:34:14 by anvilla-          #+#    #+#             */
/*   Updated: 2025/07/14 19:11:30 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	f_mandelbrot(t_struct *s)
{
	int		iter;
	double	tmp;

	iter = 0;
	while (((s->x * s->x + s->y * s->y) <= 4) && (iter < s->max_iter))
	{
		tmp = s->x * s->x - s->y * s->y + s->re;
		s->y = 2 * s->x * s->y + s->im;
		s->x = tmp;
		iter++;
	}
	return (iter);
}

void	print_mandelbrot(t_struct *s)
{
	int	iter;

	s->py = 0;
	while (s->py < HEIGHT)
	{
		s->px = 0;
		while (s->px < WIDTH)
		{
			rescaling(s);
			s->x = 0;
			s->y = 0;
			iter = f_mandelbrot(s);
			s->color = get_color(iter, s->max_iter);
			put_pixel(s);
			s->px++;
		}
		s->py++;
	}
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 0);
}

int	f_julia(t_struct *s)
{
	int		iter;
	double	tmp;

	iter = 0;
	while (((s->re * s->re + s->im * s->im) <= 4) && (iter < s->max_iter))
	{
		tmp = s->re * s->re - s->im * s->im + s->os_x;
		s->im = 2 * s->re * s->im + s->os_y;
		s->re = tmp;
		iter++;
	}
	return (iter);
}

void	print_julia(t_struct *s)
{
	int	iter;

	s->py = 0;
	while (s->py < HEIGHT)
	{
		s->px = 0;
		while (s->px < WIDTH)
		{
			rescaling(s);
			iter = f_julia(s);
			s->color = get_color(iter, s->max_iter);
			put_pixel(s);
			s->px++;
		}
		s->py++;
	}
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 0);
}
