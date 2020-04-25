/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 12:38:39 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 14:18:40 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int			ft_count(int i, int j)
{
	while (j)
	{
		j = j / 10;
		i++;
	}
	return (i);
}

static unsigned int	ft_conv(unsigned int n, char *out, int i)
{
	unsigned int j;

	j = n;
	if (j / 10 > 0)
	{
		i = ft_conv(j / 10, out, i) + 1;
		out[i] = (j % 10) + '0';
		return (i);
	}
	out[i] = (j % 10) + '0';
	return (i);
}

char				*ft_uitoa(unsigned int n)
{
	int		i;
	int		j;
	char	*out;

	j = n;
	i = 0;
	if (j == 0)
		i++;
	i = ft_count(i, j);
	if (!(out = (char*)malloc(i * sizeof(char) + 1)))
		return (NULL);
	i = 0;
	i = ft_conv(n, out, i);
	out[i + 1] = 0;
	return (out);
}
