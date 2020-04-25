/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_sprite_2.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 15:07:49 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 15:08:34 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void		calc_dist_sp(double *dist_x, double *dist_y, t_ray *ray)
{
	*dist_x = sqrt(pow(fabs(ray->xx - ray->spx), 2) +
			pow(fabs(ray->xy - ray->spy), 2));
	*dist_y = sqrt(pow(fabs(ray->yx - ray->spx), 2) +
			pow(fabs(ray->yy - ray->spy), 2));
}

static void	get_ydist_sp(t_ray *ray)
{
	if (ray->angle < M_PI)
		ray->yy -= ray->y_ya;
	else
		ray->yy += ray->y_ya;
	if (ray->angle < M_PI / 2 || ray->angle > (3 * M_PI) / 2)
		ray->yx += 1;
	else
		ray->yx -= 1;
	ray->y_dist -= sqrt(pow(ray->y_xa, 2) + pow(ray->y_ya, 2));
}

static void	get_xdist_sp(t_ray *ray)
{
	if (ray->angle < M_PI / 2 || ray->angle > (3 * M_PI) / 2)
		ray->xx += ray->x_xa;
	else
		ray->xx -= ray->x_xa;
	if (ray->angle < M_PI)
		ray->xy -= 1;
	else
		ray->xy += 1;
	ray->x_dist -= sqrt(pow(ray->x_xa, 2) + pow(ray->x_ya, 2));
}

void		get_wall_hit_sp(t_scene *elem, t_ray *ray, double dist_x,
		double dist_y)
{
	if (dist_y < dist_x)
	{
		if (wall_hit(elem, ray, 'y', '2'))
			disp_sprite(elem, ray, dist_x, dist_y);
		get_ydist_sp(ray);
	}
	else
	{
		if (wall_hit(elem, ray, 'x', '2'))
			disp_sprite(elem, ray, dist_x, dist_y);
		get_xdist_sp(ray);
	}
}
