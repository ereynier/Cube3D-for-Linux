/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 15:19:51 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 14:46:45 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_ydist(t_ray *ray)
{
	if (ray->angle < M_PI)
		ray->yy -= ray->y_ya;
	else
		ray->yy += ray->y_ya;
	if (ray->angle < M_PI / 2 || ray->angle > (3 * M_PI) / 2)
		ray->yx += 1;
	else
		ray->yx -= 1;
	ray->y_dist += sqrt(pow(ray->y_xa, 2) + pow(ray->y_ya, 2));
}

void	get_xdist(t_ray *ray)
{
	if (ray->angle < M_PI / 2 || ray->angle > (3 * M_PI) / 2)
		ray->xx += ray->x_xa;
	else
		ray->xx -= ray->x_xa;
	if (ray->angle < M_PI)
		ray->xy -= 1;
	else
		ray->xy += 1;
	ray->x_dist += sqrt(pow(ray->x_xa, 2) + pow(ray->x_ya, 2));
}

int		get_wall_hit(t_scene *elem, t_ray *ray, double dist_x, double dist_y)
{
	int w;

	if (dist_y < dist_x)
	{
		if ((w = wall_hit(elem, ray, 'y', '1')))
			return (w);
		get_ydist(ray);
	}
	else
	{
		if ((w = wall_hit(elem, ray, 'x', '1')))
			return (w);
		get_xdist(ray);
	}
	return (w);
}

void	ray_casting(t_scene *elem)
{
	t_ray	ray;
	double	dist_x;
	double	dist_y;

	if (!(elem->img_ptr = mlx_new_image(elem->mlx_ptr, elem->res[0],
					elem->res[1])))
		ft_close(elem);
	if (elem->x == (double)(int)elem->x)
		elem->x += 0.0001;
	if (elem->y == (double)(int)elem->y)
		elem->y += 0.0001;
	ray.col = 0 - elem->res[0] / 2;
	ray.decallage = ((FOV / 2) * M_PI / 180) / (elem->res[0] / 2);
	ray_casting_2(elem, &ray, &dist_x, &dist_y);
	mlx_put_image_to_window(elem->mlx_ptr, elem->win_ptr, elem->img_ptr, 0, 0);
	mlx_destroy_image(elem->mlx_ptr, elem->img_ptr);
	elem->img_ptr = 0;
}

int		init_window(t_scene *elem)
{
	if (elem->res[0] > MAX_SCREEN_L)
		elem->res[0] = MAX_SCREEN_L;
	if (elem->res[1] > MAX_SCREEN_H)
		elem->res[1] = MAX_SCREEN_H;
	if (elem->res[0] < MIN_SCREEN_L)
		elem->res[0] = MIN_SCREEN_L;
	if (elem->res[1] < MIN_SCREEN_H)
		elem->res[1] = MIN_SCREEN_H;
	get_spawn(elem);
	get_screen_dist(elem);
	elem->mlx_ptr = mlx_init();
	elem->win_ptr = mlx_new_window(elem->mlx_ptr, elem->res[0],
			elem->res[1], "Cub3D");
	init_variables(elem);
	ray_casting(elem);
	mlx_loop_hook(elem->mlx_ptr, apply_input, elem);
	mlx_hook(elem->win_ptr, 2, 1L << 0, holdinput, elem);
	mlx_hook(elem->win_ptr, 3, 1L << 1, releaseinput, elem);
	mlx_hook(elem->win_ptr, 17, 1L << 17, ft_close, elem);
	mlx_loop(elem->mlx_ptr);
	return (0);
}
