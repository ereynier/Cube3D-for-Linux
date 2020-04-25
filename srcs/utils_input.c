/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:56:21 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 14:56:26 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void	back(t_scene *elem)
{
	if (elem->map[(int)elem->y][(int)(elem->x - cos(elem->angle) * 0.2)] !=
			'1')
		elem->x -= cos(elem->angle) * 0.1;
	if (elem->map[(int)(elem->y + sin(elem->angle) * 0.2)][(int)elem->x] !=
			'1')
		elem->y += sin(elem->angle) * 0.1;
}

void	forward(t_scene *elem)
{
	if (elem->map[(int)elem->y][(int)(elem->x + cos(elem->angle) * 0.2)] !=
			'1')
		elem->x += cos(elem->angle) * 0.1;
	if (elem->map[(int)(elem->y - sin(elem->angle) * 0.2)][(int)elem->x] !=
			'1')
		elem->y -= sin(elem->angle) * 0.1;
}

void	strafl(t_scene *elem)
{
	if (elem->map[(int)elem->y][(int)(elem->x - sin(elem->angle) * 0.2)] !=
			'1')
		elem->x -= sin(elem->angle) * 0.08;
	if (elem->map[(int)(elem->y - cos(elem->angle) * 0.2)][(int)elem->x] !=
			'1')
		elem->y -= cos(elem->angle) * 0.08;
}

void	strafr(t_scene *elem)
{
	if (elem->map[(int)elem->y][(int)(elem->x + sin(elem->angle) * 0.2)] !=
			'1')
		elem->x += sin(elem->angle) * 0.08;
	if (elem->map[(int)(elem->y + cos(elem->angle) * 0.2)][(int)elem->x] !=
			'1')
		elem->y += cos(elem->angle) * 0.08;
}
