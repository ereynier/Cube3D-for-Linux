/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_map.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 15:47:46 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 14:40:18 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_len_map(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] != ' ')
			i++;
		j++;
	}
	return (i);
}

static int	check_char(char **map)
{
	int i;
	int j;
	int player;

	player = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' ||
					map[i][j] == 'E')
				player++;
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '2' &&
					map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E' &&
					map[i][j] != 'W')
				return (0);
			j++;
		}
		i++;
	}
	if (player != 1)
		return (0);
	return (1);
}

static int	check_border(char **map)
{
	int i;
	int j;

	j = -1;
	i = -1;
	while (map[++j])
		if (map[j][0] != '1')
			return (0);
	while (map[j - 1][++i])
		if (map[j - 1][i] != '1')
			return (0);
	while (--j >= 0)
		if (map[j][i - 1] != '1')
			return (0);
	while (--i >= 0)
		if (map[0][i] != '1')
			return (0);
	j = 0;
	i = ft_len_map(map[0]);
	while (map[j])
		j++;
	if (j < 3 || i < 3)
		return (0);
	return (1);
}

int			valid_map(char **map)
{
	int i;
	int j;

	j = 0;
	i = ft_len_map(map[0]);
	while (map[j])
	{
		if (ft_len_map(map[j++]) != i)
		{
			ft_putstr("Error\nMap invalide : lignes de tailles differentes");
			return (-1);
		}
	}
	if (!check_border(map))
	{
		ft_putstr("Error\nMap invalide : la map doit etre entoure de mur");
		return (-1);
	}
	if (!check_char(map))
	{
		ft_putstr("Error\nMap invalide : caractere invalide ou \
				nombre de joueur different de 1");
		return (-1);
	}
	return (1);
}
