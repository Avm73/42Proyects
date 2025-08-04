/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:20:21 by anvilla-          #+#    #+#             */
/*   Updated: 2025/07/24 20:03:07 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iter, int max_iter)
{
	int		r;
	int		g;
	int		b;
	double	t;

	t = (double)iter / (double)max_iter;
	r = (9 * (1 - t) * t * t * t * 255);
	g = (15 * (1 - t) * (1 - t) * t * t * 255);
	b = (8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

void	rescaling(t_struct *s)
{
	s->re = s->min_x + (s->px / (double)WIDTH) * (s->max_x - s->min_x);
	s->im = s->max_y - (s->py / (double)HEIGHT) * (s->max_y - s->min_y);
}

void	put_pixel(t_struct *s)
{
	int	pos;

	pos = (s->py * s->line_bts) + (s->px * (s->bpp / 8));
	s->data[pos + 2] = s->color & 0xFF;
	s->data[pos + 1] = (s->color >> 8) & 0xFF;
	s->data[pos + 0] = (s->color >> 16) & 0xFF;
}

void	set_window(t_struct *s)
{
	s->mlx_ptr = mlx_init();
	if (!s->mlx_ptr)
		exit(EXIT_FAILURE);
	s->win_ptr = mlx_new_window(s->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	if (!s->win_ptr)
		exit(EXIT_FAILURE);
	s->img_ptr = mlx_new_image(s->mlx_ptr, WIDTH, HEIGHT);
	if (!s->img_ptr)
		exit(EXIT_FAILURE);
	s->data = mlx_get_data_addr(s->img_ptr, &s->bpp, &s->line_bts, &s->endian);
}
