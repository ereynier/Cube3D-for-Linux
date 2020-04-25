/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 10:17:53 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 10:46:06 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*out;
	int		size;

	i = start;
	if (start > ft_strlen(s))
		size = 0;
	else if ((int)(len) < (int)ft_strlen((char*)(&s[start])))
		size = len;
	else
		size = (int)ft_strlen((char*)(&s[start]));
	if (!(out = malloc(size + 1)))
		return (0);
	if (size == 0)
	{
		out[0] = '\0';
		return (out);
	}
	while (s[i] != 0 && (i - start) < len)
	{
		out[i - start] = s[i];
		i++;
	}
	out[i - start] = 0;
	return (out);
}
