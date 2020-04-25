/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 14:39:52 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 14:23:05 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void	right(t_scene *elem)
{
	elem->angle = elem->angle - 0.035;
	if (elem->angle < 0)
		elem->angle = elem->angle + 2 * M_PI;
}

void	left(t_scene *elem)
{
	elem->angle = elem->angle + 0.035;
	if (elem->angle > 2 * M_PI)
		elem->angle = elem->angle - 2 * M_PI;
}

int		apply_input(t_scene *elem)
{
	if (elem->left)
		left(elem);
	if (elem->right)
		right(elem);
	if (elem->back)
		back(elem);
	if (elem->forward)
		forward(elem);
	if (elem->strafl)
		strafl(elem);
	if (elem->strafr)
		strafr(elem);
	if (elem->strafr || elem->strafl || elem->left || elem->right ||
			elem->back || elem->forward)
	{
		//mlx_clear_window(elem->mlx_ptr, elem->win_ptr);
		ray_casting(elem);
	}
	return (1);
}

int		releaseinput(int key, t_scene *elem)
{
	if (key == LEFT)
		elem->left = 0;
	if (key == RIGHT)
		elem->right = 0;
	if (key == BACK)
		elem->back = 0;
	if (key == FORWARD)
		elem->forward = 0;
	if (key == STRAFL)
		elem->strafl = 0;
	if (key == STRAFR)
		elem->strafr = 0;
	return (1);
}

int		holdinput(int key, t_scene *elem)
{
	if (key == LEFT)
		elem->left = 1;
	if (key == RIGHT)
		elem->right = 1;
	if (key == BACK)
		elem->back = 1;
	if (key == FORWARD)
		elem->forward = 1;
	if (key == STRAFL)
		elem->strafl = 1;
	if (key == STRAFR)
		elem->strafr = 1;
	if (key == 65307)
		ft_close(elem);
	return (1);
}
