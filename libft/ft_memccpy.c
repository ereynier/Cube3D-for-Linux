/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 16:05:55 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 16:15:23 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
		int c, size_t n)
{
	size_t i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (((unsigned char*)src)[i] == (unsigned char)(c))
		{
			((unsigned char*)dst)[i] = ((char*)src)[i];
			i++;
			return (dst + i);
		}
		((char*)dst)[i] = ((char*)src)[i];
		i++;
	}
	return (NULL);
}
