/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:20:16 by anvilla-          #+#    #+#             */
/*   Updated: 2025/07/12 19:05:51 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_left(t_struct *s)
{
	double	move;

	move = (s->max_x - s->min_x) * 0.05;
	s->min_x -= move;
	s->max_x -= move;
	if (s->name == 1)
		print_mandelbrot(s);
	if (s->name == 2)
		print_julia(s);
}

void	move_up(t_struct *s)
{
	double	move;

	move = (s->max_y - s->min_y) * 0.05;
	s->min_y += move;
	s->max_y += move;
	if (s->name == 1)
		print_mandelbrot(s);
	if (s->name == 2)
		print_julia(s);
}

void	move_right(t_struct *s)
{
	double	move;

	move = (s->max_x - s->min_x) * 0.05;
	s->min_x += move;
	s->max_x += move;
	if (s->name == 1)
		print_mandelbrot(s);
	if (s->name == 2)
		print_julia(s);
}

void	move_down(t_struct *s)
{
	double	move;

	move = (s->max_y - s->min_y) * 0.05;
	s->min_y -= move;
	s->max_y -= move;
	if (s->name == 1)
		print_mandelbrot(s);
	if (s->name == 2)
		print_julia(s);
}

int	handler_key(int keycode, void *param)
{
	if (keycode == KEY_LEFT)
		move_left(param);
	else if (keycode == KEY_UP)
		move_up(param);
	else if (keycode == KEY_RIGHT)
		move_right(param);
	else if (keycode == KEY_DOWN)
		move_down(param);
	else if (keycode == KEY_ESC)
		free_close(param);
	return (0);
}
