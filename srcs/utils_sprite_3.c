/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_sprite_3.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 15:09:14 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 15:09:35 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void	calc_centre_2(double *x, double *y, double (*centre)[2], t_ray *ray)
{
	if (ray->angle > M_PI / 2 && ray->angle < (3 * M_PI) / 2)
	{
		centre[0][0] = (double)(int)ray->yx - 0.5;
		centre[0][1] = (double)(int)ray->yy + 0.5;
	}
	else
	{
		centre[0][0] = (double)(int)ray->yx + 0.5;
		centre[0][1] = (double)(int)ray->yy + 0.5;
	}
	*x = ray->yx;
	*y = ray->yy;
}

void	calc_centre(double *x, double *y, double (*centre)[2], t_ray *ray)
{
	{
		if (ray->angle > M_PI)
		{
			centre[0][0] = (double)(int)ray->xx + 0.5;
			centre[0][1] = (double)(int)ray->xy + 0.5;
		}
		else
		{
			centre[0][0] = (double)(int)ray->xx + 0.5;
			centre[0][1] = (double)(int)ray->xy - 0.5;
		}
		*x = ray->xx;
		*y = ray->xy;
	}
}
