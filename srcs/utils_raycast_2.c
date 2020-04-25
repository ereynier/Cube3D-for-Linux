/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_raycast_2.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:46:58 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 15:04:39 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

int		wall_hit_2(t_scene *elem, t_ray *ray, char hit)
{
	if (ray->angle < M_PI / 2 || ray->angle > (3 * M_PI) / 2)
	{
		if (elem->map[(int)ray->yy][(int)ray->yx] == hit)
			return (1);
	}
	else
	{
		if (elem->map[(int)ray->yy][(int)ray->yx - 1] == hit)
			return (1);
	}
	return (0);
}

void	ray_casting_2(t_scene *elem, t_ray *ray, double *dist_x, double *dist_y)
{
	while (ray->col < elem->res[0] / 2)
	{
		ray->angle = (elem->angle - (ray->col * ray->decallage));
		if (ray->angle > 2 * M_PI)
			ray->angle = ray->angle - 2 * M_PI;
		else if (ray->angle < 0)
			ray->angle = ray->angle + 2 * M_PI;
		setup_ray(elem, ray);
		calc_dist(dist_x, dist_y, elem, ray);
		while (!get_wall_hit(elem, ray, *dist_x, *dist_y))
			calc_dist(dist_x, dist_y, elem, ray);
		display_col(elem, ray, *dist_y, *dist_x);
		ray->col = ray->col + 1;
	}
}
