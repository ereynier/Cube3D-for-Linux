/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:09:29 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 14:18:49 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void		put_sprite(char *data_addr, char *out_data_addr, t_scene *elem,
	t_ray *ray)
{
	int i;

	i = 0;
	while (i < ray->top)
		i++;
	while (i < elem->res[1] && i < ray->height + ray->top)
	{
		if (data_addr[(int)(((i - ray->top) / ray->height) * 64) *
			elem->size_line_texture] != 0 && data_addr[(int)(((i - ray->top)
			/ ray->height) * 64) * elem->size_line_texture + 1] != 0 &&
			data_addr[(int)(((i - ray->top) / ray->height) * 64) *
			elem->size_line_texture + 2] != 0)
		{
			out_data_addr[i * elem->size_line] =
				data_addr[(int)(((i - ray->top) / ray->height) * 64)
				* elem->size_line_texture];
			out_data_addr[i * elem->size_line + 1] =
				data_addr[(int)(((i - ray->top) / ray->height) * 64)
				* elem->size_line_texture + 1];
			out_data_addr[i * elem->size_line + 2] =
				data_addr[(int)(((i - ray->top) / ray->height) * 64)
				* elem->size_line_texture + 2];
		}
		i++;
	}
}

void		disp_sprite2(t_scene *elem, t_ray *ray, t_sprite *sp)
{
	char	*out_data_addr;
	char	*data_addr;

	out_data_addr = mlx_get_data_addr(elem->img_ptr,
			&elem->bits_per_pixel, &elem->size_line, &elem->endian);
	data_addr = mlx_get_data_addr(elem->img_sp, &elem->bits_per_pixel,
			&elem->size_line_texture, &elem->endian);
	if (sqrt(pow((sp->x - sp->centre[0]), 2) + pow((sp->y - sp->centre[1]), 2))
			< 0.5)
	{
		ray->dist = sqrt(pow((sp->x - elem->x), 2) + pow((sp->y - elem->y), 2));
		ray->height = T_LENGTH * (elem->screen_dist / 2) / (ray->dist * 30);
		ray->top = (elem->res[1] / 2) - (int)(ray->height / 2);
		out_data_addr += 4 * (ray->col + elem->res[0] / 2);
		data_addr += (int)((sqrt(pow((sp->x2 - sp->x), 2) +
						pow((sp->y2 - sp->y), 2)) - 0.5) * T_LENGTH) * 4;
	}
	put_sprite(data_addr, out_data_addr, elem, ray);
}

void		disp_sprite(t_scene *elem, t_ray *ray, double dist_x, double dist_y)
{
	t_sprite	sp;

	sp.angle = elem->angle + (M_PI / 2);
	if (sp.angle < 0)
		sp.angle -= 2 * M_PI;
	if (dist_x < dist_y)
		calc_centre(&sp.x, &sp.y, &sp.centre, ray);
	else
		calc_centre_2(&sp.x, &sp.y, &sp.centre, ray);
	if (ray->angle == (3 * M_PI / 2) || ray->angle == M_PI / 2)
		sp.y = sp.centre[1];
	else
	{
		sp.p = -(((sp.y - elem->y) / (sp.x - elem->x)) * sp.x - sp.y);
		sp.x2 = sp.centre[0] - cos(sp.angle);
		sp.y2 = sp.centre[1] + sin(sp.angle);
		sp.p2 = -(((sp.y2 - sp.centre[1]) / (sp.x2 - sp.centre[0])) *
			sp.centre[0] - sp.centre[1]);
		sp.x = (sp.p - sp.p2) / (((sp.y2 - sp.centre[1]) /
			(sp.x2 - sp.centre[0])) - ((sp.y - elem->y) / (sp.x - elem->x)));
		sp.y = ((sp.y2 - sp.centre[1]) /
			(sp.x2 - sp.centre[0])) * sp.x + sp.p2;
	}
	disp_sprite2(elem, ray, &sp);
}

static void	dislay_sprite_2(t_scene *elem, t_ray *ray, double dist_x,
		double dist_y)
{
	if (ray->xy == 0)
		ray->xy += 1;
	while (1)
	{
		if (dist_y < dist_x)
		{
			if (wall_hit(elem, ray, 'y', '1'))
				break ;
		}
		else
		{
			if (wall_hit(elem, ray, 'x', '1'))
				break ;
		}
		if (is_on_player(elem, ray, dist_x, dist_y))
			break ;
		get_wall_hit_sp(elem, ray, dist_x, dist_y);
		calc_dist_sp(&dist_x, &dist_y, ray);
	}
}

void		display_sprite(t_scene *elem, t_ray *ray, double dist_x,
		double dist_y)
{
	if (dist_y < dist_x)
	{
		ray->spx = ray->yx;
		ray->spy = ray->yy;
	}
	else
	{
		ray->spx = ray->xx;
		ray->spy = ray->xy;
	}
	ray->angle = ray->angle + M_PI;
	if (ray->angle > 2 * M_PI)
		ray->angle -= 2 * M_PI;
	setup_ray_sp(ray, dist_x, dist_y);
	calc_dist_sp(&dist_x, &dist_y, ray);
	dislay_sprite_2(elem, ray, dist_x, dist_y);
}
