/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 16:18:34 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 16:38:09 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i++;
		}
	}
	else
	{
		i = len - 1;
		while ((int)i >= 0)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i--;
		}
	}
	return (dst);
}
