/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 11:49:07 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 14:24:40 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_line(char *line, t_scene *elem)
{
	int i;

	i = -2;
	if (line[0] == 'R')
		i = 0;
	else if (line[0] == 'N' && line[1] == 'O')
		i = 1;
	else if (line[0] == 'S' && line[1] == 'O')
		i = 2;
	else if (line[0] == 'W' && line[1] == 'E')
		i = 3;
	else if (line[0] == 'E' && line[1] == 'A')
		i = 4;
	else if (line[0] == 'S')
		i = 5;
	else if (line[0] == 'F')
		i = 6;
	else if (line[0] == 'C')
		i = 7;
	if (1 <= i && i <= 5)
		i = check_texture(i, line, elem);
	else if (i != -2)
		i = i == 0 ? check_res(line, elem, i) : check_rgb(i, line, elem);
	i == -2 ? ft_putstr("Error\nElement inconnu") : i;
	return (i);
}

int		check_elements(char **scene, t_scene *elem)
{
	int i;
	int k;
	int check[8];

	i = 8;
	while (i > 0)
		check[--i] = 0;
	k = 0;
	while (scene[i] && scene[i][0] != '1')
	{
		if ((k = check_line(scene[i], elem)) < 0)
			return (-1);
		if (check[k] != 0)
		{
			ft_putstr("Error\nElement en double");
			return (-1);
		}
		check[k] = ++i;
	}
	if (i != 8)
	{
		ft_putstr("Error\nElement manquant");
		return (-1);
	}
	return (1);
}

int		get_scene(int fd, char ***out)
{
	char c;
	char *tmp;

	if (!(tmp = ft_calloc(1, 1)))
		return (0);
	while (read(fd, &c, 1))
	{
		if (!append(&tmp, c))
			return (0);
	}
	*out = ft_split(tmp, '\n');
	free(tmp);
	return (1);
}

int		check_map(char **scene, char ***map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (scene[i][0] != '1')
		i++;
	while (scene[i++])
		j++;
	if (!(*map = ft_calloc(j + 1, sizeof(char*))))
	{
		ft_putstr("Error\nProbleme lors de la lecture");
		return (free_scene(*map));
	}
	i -= j + 1;
	j = -1;
	while (scene[i])
	{
		if (!(map[0][++j] = mapdup(scene[i++])))
		{
			ft_putstr("Error\nProbleme lors de la lecture de la map");
			return (-1);
		}
	}
	return (valid_map(map[0]));
}

int		parsing(int fd, char ***map, t_scene *elem)
{
	char **scene;

	if (!get_scene(fd, &scene))
	{
		ft_putstr("Error\nProbleme de lecture du .cub");
		return (free_scene(scene));
	}
	if (check_elements(scene, elem) < 0)
	{
		free_scene(scene);
		return (free_elem(elem));
	}
	if (check_map(scene, map) < 0)
	{
		free_scene(scene);
		free_elem(elem);
		return (free_scene(*map));
	}
	return (free_scene(scene) * 0 + 1);
}
