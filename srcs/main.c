/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 11:49:02 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 14:23:50 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	int		fd;
	char	**map;
	t_scene	elem;

	first_init(&elem);
	if ((fd = open(av[1], O_RDONLY)) < 0 || !check_extension(av[1]))
	{
		write(1, "Error\n.cub introuvable", 22);
		return (1);
	}
	else if (parsing(fd, &map, &elem) < 0)
		return (1);
	elem.map = map;
	if (ac == 3 && !ft_strncmp(av[2], "-save", 6))
		save_bitmap("cub.bmp", &elem);
	else if (ac > 2)
	{
		ft_putstr("Error\nNombre de parametres incorrect");
		free_elem(&elem);
	}
	else
		init_window(&elem);
	return (0);
}
