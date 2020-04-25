/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 11:49:20 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 14:54:23 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

int		append(char **s, char c)
{
	char	*out;
	int		i;

	i = 0;
	if (!(out = ft_calloc(ft_strlen(s[0]) + 2, sizeof(*out))))
		return (0);
	while (s[0][i])
	{
		out[i] = s[0][i];
		i++;
	}
	out[i] = c;
	free(s[0]);
	s[0] = out;
	return (1);
}

int		check_extension(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (i < 5)
		return (0);
	if (str[i - 1] != 'b' && str[i - 2] != 'u'
			&& str[i - 3] != 'c' && str[i - 4] != '.')
		return (0);
	return (1);
}

int		free_elem(t_scene *elem)
{
	if ((elem)->no_path)
		free((elem)->no_path);
	if ((elem)->so_path)
		free((elem)->so_path);
	if ((elem)->we_path)
		free((elem)->we_path);
	if ((elem)->ea_path)
		free((elem)->ea_path);
	if ((elem)->sprite_path)
		free((elem)->sprite_path);
	if ((elem)->img_sp)
		mlx_destroy_image((elem)->mlx_ptr, (elem)->img_sp);
	if ((elem)->img_ea)
		mlx_destroy_image((elem)->mlx_ptr, (elem)->img_ea);
	if ((elem)->img_we)
		mlx_destroy_image((elem)->mlx_ptr, (elem)->img_we);
	if ((elem)->img_no)
		mlx_destroy_image((elem)->mlx_ptr, (elem)->img_no);
	if ((elem)->img_so)
		mlx_destroy_image((elem)->mlx_ptr, (elem)->img_so);
	if ((elem)->img_ptr)
		mlx_destroy_image((elem)->mlx_ptr, (elem)->img_ptr);
	return (-1);
}

int		free_scene(char **scene)
{
	int i;

	i = 0;
	while (scene[i])
		free(scene[i++]);
	free(scene);
	return (-1);
}

char	*mapdup(char *line)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	j = 0;
	if (!(out = ft_calloc(ft_len_map(line) + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (!ft_iswspace(line[i]))
			out[j++] = line[i];
		i++;
	}
	return (out);
}
