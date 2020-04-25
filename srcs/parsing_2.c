/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 13:36:02 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 14:39:19 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

static int	skip_char(char *line, int i)
{
	while (ft_isdigit(line[i]))
		i++;
	while (ft_iswspace(line[i]))
		i++;
	return (i);
}

int			check_res(char *line, t_scene *elem, int j)
{
	int i;

	i = 1;
	while (line[i])
	{
		if (line[i++] != ' ')
			break ;
		(elem)->res[0] = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]))
			i++;
		while (ft_iswspace(line[i]))
			i++;
		if (!ft_isdigit(line[i]))
			break ;
		(elem)->res[1] = ft_atoi(&line[i]);
		if ((elem)->res[0] <= 0 || (elem)->res[1] <= 0)
			break ;
		i = skip_char(line, i);
		if (line[i] != '\0')
			break ;
		return (j);
	}
	ft_putstr("Error\nResolution invalide");
	return (-1);
}

static int	check_rgb_roof(char *line, t_scene *elem, int i)
{
	int j;
	int k;

	k = 0;
	j = 1;
	while (line[j] && k++ <= 3)
	{
		if (line[1] != ' ' || 0 > ft_atoi(&line[j]) || ft_atoi(&line[j]) > 255)
			break ;
		(elem)->c_rgb[k - 1] = ft_atoi(&line[j]);
		while (ft_isdigit(line[j]) || ft_iswspace(line[j]))
			j++;
		if ((k != 3 && line[j++] != ',') || (k == 3 && line[j] != ' '))
			break ;
	}
	while (ft_iswspace(line[j]))
		j++;
	if (k < 3 || line[j] != '\0')
	{
		ft_putstr("Error\nCouleur plafond invalide");
		return (-1);
	}
	return (i);
}

int			check_rgb(int i, char *line, t_scene *elem)
{
	int j;
	int k;

	k = 0;
	j = 1;
	if (i == 7)
		i = check_rgb_roof(line, elem, i);
	while (i == 6 && line[j] && k++ <= 3)
	{
		if (line[1] != ' ' || 0 > ft_atoi(&line[j]) || ft_atoi(&line[j]) > 255)
			break ;
		(elem)->f_rgb[k - 1] = ft_atoi(&line[j]);
		while (ft_isdigit(line[j]) || ft_iswspace(line[j]))
			j++;
		if ((k != 3 && line[j++] != ',') || (k == 3 && line[j] != ' '))
			break ;
	}
	while (i == 6 && ft_iswspace(line[j]))
		j++;
	if (i == 6 && (k < 3 || line[j] != '\0'))
	{
		ft_putstr("Error\nCouleur sol invalide");
		return (-1);
	}
	return (i);
}

int			check_texture(int i, char *line, t_scene *elem)
{
	int		j;
	char	*tmp;

	j = i == 5 ? 1 : 2;
	while (ft_iswspace(line[j]))
		j++;
	tmp = ft_strtrim(&line[j], " ");
	if (i == 1)
		(elem)->no_path = tmp;
	else if (i == 2)
		(elem)->so_path = tmp;
	else if (i == 3)
		(elem)->we_path = tmp;
	if (i == 4)
		(elem)->ea_path = tmp;
	else
		(elem)->sprite_path = tmp;
	return (i);
}
