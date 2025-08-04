/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:20:50 by anvilla-          #+#    #+#             */
/*   Updated: 2025/07/24 19:57:37 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	struct_init(t_struct *s)
{
	s->max_iter = 50;
	s->x = 0;
	s->y = 0;
	s->os_x = 0;
	s->os_y = 0;
	s->px = 0;
	s->py = 0;
	s->min_x = -2.0;
	s->max_x = 2.0;
	s->min_y = -2.0;
	s->max_y = 2.0;
}

int	free_close(void *param)
{
	t_struct	*tmp;

	tmp = (t_struct *)param;
	if (tmp->img_ptr)
		mlx_destroy_image(tmp->mlx_ptr, tmp->img_ptr);
	if (tmp->win_ptr)
		mlx_destroy_window(tmp->mlx_ptr, tmp->win_ptr);
	if (tmp->mlx_ptr)
	{
		mlx_destroy_display(tmp->mlx_ptr);
		free(tmp->mlx_ptr);
	}
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_struct	s;

	struct_init(&s);
	s.name = check_name(argc, argv, &s);
	set_window(&s);
	if (s.name == 1)
		print_mandelbrot(&s);
	if (s.name == 2)
		print_julia(&s);
	mlx_hook(s.win_ptr, 17, 0, free_close, &s);
	mlx_key_hook(s.win_ptr, handler_key, &s);
	mlx_mouse_hook(s.win_ptr, handler_mouse, &s);
	mlx_loop(s.mlx_ptr);
	return (0);
}
