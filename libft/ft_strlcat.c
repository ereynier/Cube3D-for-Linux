/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 19:35:58 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 21:16:14 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	k = i;
	if (i > size)
		k = size;
	while (i < size - 1 && size > 0 && src[j] != 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	j = 0;
	while (src[j])
		j++;
	k = k + j;
	dst[i] = 0;
	return (k);
}
