/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 13:44:08 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 13:47:50 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_texture2(t_scene *elem, t_ray *ray)
{
	char *data_addr;

	if (ray->angle < M_PI)
	{
		data_addr = mlx_get_data_addr(elem->img_no, &elem->bits_per_pixel,
				&elem->size_line_texture, &elem->endian);
		data_addr += (int)(fabs(ray->xx - (double)(int)ray->xx) *
				T_LENGTH) * 4;
	}
	else
	{
		data_addr = mlx_get_data_addr(elem->img_so, &elem->bits_per_pixel,
				&elem->size_line_texture, &elem->endian);
		data_addr += (int)(fabs(ray->xx - (double)(int)ray->xx) *
				T_LENGTH) * 4;
	}
	return (data_addr);
}

char	*get_texture(t_scene *elem, t_ray *ray, double dist_x, double dist_y)
{
	char *data_addr;

	if (dist_y < dist_x)
	{
		if (ray->angle > M_PI / 2 && ray->angle < (3 * M_PI) / 2)
		{
			data_addr = mlx_get_data_addr(elem->img_we, &elem->bits_per_pixel,
					&elem->size_line_texture, &elem->endian);
			data_addr += (int)(fabs(ray->yy - (double)(int)ray->yy) *
					T_LENGTH) * 4;
		}
		else
		{
			data_addr = mlx_get_data_addr(elem->img_ea, &elem->bits_per_pixel,
					&elem->size_line_texture, &elem->endian);
			data_addr += (int)(fabs(ray->yy - (double)(int)ray->yy) *
					T_LENGTH) * 4;
		}
	}
	else
		data_addr = get_texture2(elem, ray);
	return (data_addr);
}

int		display_col2(t_scene *elem, t_ray *ray, char *data_addr,
			char *out_data_add)
{
	int i;

	i = 0;
	while (i < ray->top)
	{
		out_data_add[i * elem->size_line] = (char)elem->c_rgb[2];
		out_data_add[i * elem->size_line + 1] = (char)elem->c_rgb[1];
		out_data_add[i * elem->size_line + 2] = (char)elem->c_rgb[0];
		i++;
	}
	while (i < elem->res[1] && i < ray->height + ray->top)
	{
		out_data_add[i * elem->size_line] = data_addr[(int)(((i - ray->top)
					/ ray->height) * 64) * elem->size_line_texture];
		out_data_add[i * elem->size_line + 1] = data_addr[(int)(((i - ray->top)
					/ ray->height) * 64) * elem->size_line_texture + 1];
		out_data_add[i * elem->size_line + 2] = data_addr[(int)(((i - ray->top)
					/ ray->height) * 64) * elem->size_line_texture + 2];
		i++;
	}
	return (i);
}

void	display_col(t_scene *elem, t_ray *ray, double dist_y, double dist_x)
{
	char	*data_addr;
	char	*out_data_addr;
	int		i;

	ray->dist = dist_x < dist_y ? dist_x : dist_y;
	ray->height = T_LENGTH * (elem->screen_dist / 2) / (ray->dist * 30);
	ray->top = (elem->res[1] / 2) - (int)(ray->height / 2);
	out_data_addr = mlx_get_data_addr(elem->img_ptr, &elem->bits_per_pixel,
			&elem->size_line, &elem->endian);
	out_data_addr += 4 * (ray->col + elem->res[0] / 2);
	data_addr = get_texture(elem, ray, dist_x, dist_y);
	i = display_col2(elem, ray, data_addr, out_data_addr);
	while (i < elem->res[1] - 1)
	{
		out_data_addr[i * elem->size_line] = (char)elem->f_rgb[2];
		out_data_addr[i * elem->size_line + 1] = (char)elem->f_rgb[1];
		out_data_addr[i * elem->size_line + 2] = (char)elem->f_rgb[0];
		i++;
	}
	display_sprite(elem, ray, dist_x, dist_y);
}
