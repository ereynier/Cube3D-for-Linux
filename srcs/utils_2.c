/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 11:33:52 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 14:55:44 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void		free_all(t_scene *elem)
{
	free_elem(elem);
	free_scene(elem->map);
}

int			ft_close(t_scene *elem)
{
	mlx_destroy_window(elem->mlx_ptr, elem->win_ptr);
	free_all(elem);
	exit(1);
}

static void	get_spawn_dir(int x, int y, t_scene *elem)
{
	if (elem->map[y][x] == 'N')
		elem->angle = M_PI / 2;
	else if (elem->map[y][x] == 'S')
		elem->angle = (3 * M_PI) / 2;
	else if (elem->map[y][x] == 'W')
		elem->angle = M_PI;
	else if (elem->map[y][x] == 'E')
		elem->angle = 0;
}

void		get_spawn(t_scene *elem)
{
	int x;
	int y;

	y = -1;
	while (elem->map[++y])
	{
		x = -1;
		while (elem->map[y][++x])
		{
			if (elem->map[y][x] == 'N' || elem->map[y][x] == 'S' ||
					elem->map[y][x] == 'W' || elem->map[y][x] == 'E')
			{
				get_spawn_dir(x, y, elem);
				elem->x = x + 0.5;
				elem->y = y + 0.5;
				elem->map[y][x] = '0';
				return ;
			}
		}
	}
}

void		get_screen_dist(t_scene *elem)
{
	double mid_length;

	mid_length = (double)elem->res[0] / 2;
	elem->screen_dist = mid_length / tan((FOV / 2) * M_PI / 180);
}
