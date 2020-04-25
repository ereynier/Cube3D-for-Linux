/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   initVariables.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:20:03 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 14:20:05 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void	first_init(t_scene *elem)
{
	elem->so_path = 0;
	elem->no_path = 0;
	elem->we_path = 0;
	elem->ea_path = 0;
	elem->sprite_path = 0;
	elem->img_sp = 0;
	elem->img_ea = 0;
	elem->img_so = 0;
	elem->img_no = 0;
	elem->img_we = 0;
	elem->img_ptr = 0;
	elem->bits_per_pixel = 8 * 4;
	elem->size_line_texture = T_LENGTH * 4;
	elem->endian = 1;
	elem->size_line = elem->res[0] * 4;
	elem->strafr = 0;
	elem->strafl = 0;
	elem->back = 0;
	elem->forward = 0;
	elem->left = 0;
	elem->right = 0;
}

void	init_variables(t_scene *elem)
{
	int img_size;

	img_size = T_LENGTH;
	if (!(elem->img_ea = mlx_xpm_file_to_image(elem->mlx_ptr,
				elem->ea_path, &img_size, &img_size))
			|| !(elem->img_we = mlx_xpm_file_to_image(elem->mlx_ptr,
				elem->we_path, &img_size, &img_size))
			|| !(elem->img_so = mlx_xpm_file_to_image(elem->mlx_ptr,
				elem->so_path, &img_size, &img_size))
			|| !(elem->img_no = mlx_xpm_file_to_image(elem->mlx_ptr,
				elem->no_path, &img_size, &img_size))
			|| !(elem->img_sp = mlx_xpm_file_to_image(elem->mlx_ptr,
				elem->sprite_path, &img_size, &img_size)))
	{
		ft_putstr("Error\nUne textures n'est pas conforme.");
		ft_close(elem);
	}
}
