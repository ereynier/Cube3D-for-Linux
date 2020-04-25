/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bis.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lumeyer <lumeyer@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 21:53:13 by lumeyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 15:10:26 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

static void		ray_casting_save(t_scene *elem)
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
}

void			bitmap_image(t_scene *elem, int fd)
{
	int				x;
	int				y;
	int				ble;
	unsigned char	color[3];
	int				*ptr;

	ptr = (int *)mlx_get_data_addr(elem->img_ptr, &elem->bits_per_pixel,
		&elem->size_line, &elem->endian);
	y = elem->res[1] - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < elem->res[0])
		{
			ble = ptr[x + y * elem->res[0]];
			color[0] = ble % 256;
			ble /= 256;
			color[1] = ble % 256;
			ble /= 256;
			color[2] = ble % 256;
			write(fd, &color, sizeof(color));
			x++;
		}
		y--;
	}
}

void			save_2(t_scene *elem, int fd)
{
	get_spawn(elem);
	get_screen_dist(elem);
	elem->mlx_ptr = mlx_init();
	init_variables(elem);
	ray_casting_save(elem);
	bitmap_image(elem, fd);
	mlx_destroy_image(elem->mlx_ptr, elem->img_ptr);
}

void			save_bitmap(const char *filename, t_scene *elem)
{
	int			fd;
	t_header	bfh;
	t_header2	bih;

	ft_memcpy(&bfh.bitmap_type, "BM", 2);
	bfh.file_size = elem->res[0] * elem->res[1] * 4 + 54;
	bfh.reserved1 = 0;
	bfh.reserved2 = 0;
	bfh.offset_bits = 0;
	bih.size_header = sizeof(bih);
	bih.width = elem->res[0];
	bih.height = elem->res[1];
	bih.planes = 1;
	bih.bit_count = 24;
	bih.compression = 0;
	bih.image_size = elem->res[0] * elem->res[1] * 4 + 54;
	bih.ppm_x = 2;
	bih.ppm_y = 2;
	bih.clr_used = 0;
	bih.clr_important = 0;
	fd = open(filename, O_RDWR | O_CREAT, 0666);
	write(fd, &bfh, 14);
	write(fd, &bih, sizeof(bih));
	save_2(elem, fd);
	close(fd);
}
