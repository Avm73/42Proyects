/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:42:02 by anvilla-          #+#    #+#             */
/*   Updated: 2025/07/14 19:09:50 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 600

# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_ESC 65307
# define WHEEL_UP 4
# define WHEEL_DOWN 5

# include "./minilibx-linux/mlx.h"
# include "./Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_struct
{
	int		name;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data;
	int		color;
	int		bpp;
	int		line_bts;
	int		endian;
	int		max_iter;
	int		px;
	int		py;
	double	x;
	double	y;
	double	re;
	double	im;
	double	os_x;
	double	os_y;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	center_cx;
	double	center_cy;
}	t_struct;

// *** MAIN *** //
int		main(int argc, char **argv);
int		free_close(void *param);
void	set_window(t_struct *s);

// *** NAME *** //
int		check_name(int argc, char **argv, t_struct *s);
void	error_message(void);
void	error_julia(void);

// *** MANDELBROT *** //
int		f_mandelbrot(t_struct *s);
void	print_mandelbrot(t_struct *s);

// *** JULIA *** //
int		f_julia(t_struct *s);
void	print_julia(t_struct *s);

// *** WINDOW *** //
void	rescaling(t_struct *s);
int		get_color(int iter, int max_iter);
void	put_pixel(t_struct *s);
double	complex_x(t_struct *s);
double	complex_y(t_struct *s);
void	ft_zoom(t_struct *s, double zoom);

// *** KEY *** //
int		handler_key(int keycode, void *param);
void	move_left(t_struct *s);
void	move_up(t_struct *s);
void	move_right(t_struct *s);
void	move_down(t_struct *s);

// *** MOUSE *** //
int		handler_mouse(int button, int x, int y, void *param);

// *** UTILS *** //
int		ft_strcmp(char *s1, char *s2);
double	ft_atod(const char *str);

#endif