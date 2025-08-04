/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:20:14 by anvilla-          #+#    #+#             */
/*   Updated: 2025/07/12 19:08:47 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	complex_x(t_struct *s)
{
	return ((s->min_x + s->max_x) / 2);
}

double	complex_y(t_struct *s)
{
	return ((s->min_y + s->max_y) / 2);
}

void	ft_zoom(t_struct *s, double zoom)
{
	double	width;
	double	height;
	double	new_width;
	double	new_height;

	width = s->max_x - s->min_x;
	height = s->max_y - s->min_y;
	new_width = width / zoom;
	new_height = height / zoom;
	s->min_x = s->center_cx - new_width / 2;
	s->max_x = s->center_cx + new_width / 2;
	s->min_y = s->center_cy - new_height / 2;
	s->max_y = s->center_cy + new_height / 2;
}

int	handler_mouse(int button, int x, int y, void *param)
{
	t_struct	*s;

	(void)x;
	(void)y;
	s = (t_struct *)param;
	s->center_cx = complex_x(s);
	s->center_cy = complex_y(s);
	if (button == 4)
		ft_zoom(s, 1.2);
	else if (button == 5)
		ft_zoom(s, 1.0 / 1.2);
	if (s->name == 1)
		print_mandelbrot(s);
	else if (s->name == 2)
		print_julia(s);
	return (0);
}
