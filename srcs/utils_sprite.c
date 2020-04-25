/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_sprite.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 15:05:34 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 15:07:29 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

static void		is_on_player_2(t_ray *ray, double *x, double *y)
{
	if (ray->angle > M_PI / 2 && ray->angle < (3 * M_PI) / 2)
	{
		*x = (double)(int)ray->yx - 0.5;
		*y = (double)(int)ray->yy + 0.5;
	}
	else
	{
		*x = (double)(int)ray->yx + 0.5;
		*y = (double)(int)ray->yy + 0.5;
	}
}

int				is_on_player(t_scene *elem, t_ray *ray, double dist_x,
		double dist_y)
{
	double x;
	double y;

	if (dist_x < dist_y)
	{
		if (ray->angle > M_PI)
		{
			x = (double)(int)ray->xx + 0.5;
			y = (double)(int)ray->xy + 0.5;
		}
		else
		{
			x = (double)(int)ray->xx + 0.5;
			y = (double)(int)ray->xy - 0.5;
		}
	}
	else
		is_on_player_2(ray, &x, &y);
	if ((int)x == (int)elem->x && (int)y == (int)elem->y)
		return (1);
	return (0);
}

static double	get_y_sp(t_ray *ray, char c, double dist_x, double dist_y)
{
	double y;

	y = 0;
	if (c == 'y')
	{
		if (ray->angle > M_PI / 2 && ray->angle < (3 * M_PI) / 2)
			y = ray->spy + (ray->spx - (double)(int)ray->spx) *
				tan(ray->angle);
		else if (dist_x > dist_y)
			y = ray->spy;
		else
			y = ray->spy - ((double)(int)ray->spx + 1 - ray->spx) *
				tan(ray->angle);
	}
	else
	{
		if (ray->angle < M_PI)
			y = (double)(int)ray->spy;
		else if (dist_x > dist_y)
			y = (double)(int)ray->spy + 1;
		else
			y = (double)(int)ray->spy;
	}
	return (y);
}

static double	get_x_sp(t_ray *ray, char c, double dist_x, double dist_y)
{
	double x;

	x = 0;
	if (c == 'x')
	{
		if (ray->angle < M_PI)
			x = ray->spx + (ray->spy - (double)(int)ray->spy) /
				tan(ray->angle);
		else if (dist_y > dist_x)
			x = ray->spx;
		else
			x = ray->spx - ((double)(int)ray->spy + 1 - ray->spy) /
				tan(ray->angle);
	}
	else
	{
		if (ray->angle > M_PI / 2 && ray->angle < (3 * M_PI) / 2)
			x = (double)(int)ray->spx;
		else if (dist_y > dist_x)
			x = (double)(int)ray->spx + 1;
		else
			x = (double)(int)ray->spx;
	}
	return (x);
}

void			setup_ray_sp(t_ray *ray, double dist_x, double dist_y)
{
	ray->xy = get_y_sp(ray, 'x', dist_x, dist_y);
	ray->xx = get_x_sp(ray, 'x', dist_x, dist_y);
	ray->yy = get_y_sp(ray, 'y', dist_x, dist_y);
	ray->yx = get_x_sp(ray, 'y', dist_x, dist_y);
}
