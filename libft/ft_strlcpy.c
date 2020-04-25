/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 19:00:19 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 10:14:26 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (size != 0 && i < size - 1 && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (size != 0)
		dst[i] = 0;
	i = 0;
	while (src[i])
		i++;
	return (i);
}
