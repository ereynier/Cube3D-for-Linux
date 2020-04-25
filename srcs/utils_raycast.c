/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_3.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/01 14:14:45 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 15:03:29 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

double	get_y(t_ray *ray, t_scene *elem, char c)
{
	double y;

	y = 0;
	if (c == 'y')
	{
		if (ray->angle > M_PI / 2 && ray->angle < (3 * M_PI) / 2)
			y = elem->y + (elem->x - (double)(int)elem->x) *
				tan(ray->angle);
		else
			y = elem->y - ((double)(int)elem->x + 1 - elem->x) *
				tan(ray->angle);
	}
	else
	{
		if (ray->angle < M_PI)
			y = (double)(int)elem->y;
		else
			y = (double)(int)elem->y + 1;
	}
	return (y);
}

double	get_x(t_ray *ray, t_scene *elem, char c)
{
	double x;

	x = 0;
	if (c == 'x')
	{
		if (ray->angle < M_PI)
			x = elem->x + (elem->y - (double)(int)elem->y) /
				tan(ray->angle);
		else
			x = elem->x - ((double)(int)elem->y + 1 - elem->y) /
				tan(ray->angle);
	}
	else
	{
		if (ray->angle > M_PI / 2 && ray->angle < (3 * M_PI) / 2)
			x = (double)(int)elem->x;
		else
			x = (double)(int)elem->x + 1;
	}
	return (x);
}

void	setup_ray(t_scene *elem, t_ray *ray)
{
	ray->xy = get_y(ray, elem, 'x');
	ray->xx = get_x(ray, elem, 'x');
	ray->x_xa = fabs(tan(ray->angle - M_PI / 2));
	ray->x_ya = 1;
	ray->yy = get_y(ray, elem, 'y');
	ray->yx = get_x(ray, elem, 'y');
	ray->y_xa = 1;
	ray->y_ya = fabs(tan(ray->angle));
}

int		wall_hit(t_scene *elem, t_ray *ray, char c, char hit)
{
	if (c == 'x')
	{
		if (ray->angle < M_PI)
		{
			if (elem->map[(int)ray->xy - 1][(int)ray->xx] == hit)
				return (1);
		}
		else
		{
			if (elem->map[(int)ray->xy][(int)ray->xx] == hit)
				return (1);
		}
	}
	else
		return (wall_hit_2(elem, ray, hit));
	return (0);
}

void	calc_dist(double *dist_x, double *dist_y, t_scene *elem, t_ray *ray)
{
	*dist_x = sqrt(pow(fabs(ray->xx - elem->x), 2) +
			pow(fabs(ray->xy - elem->y), 2));
	*dist_y = sqrt(pow(fabs(ray->yx - elem->x), 2) +
			pow(fabs(ray->yy - elem->y), 2));
}
