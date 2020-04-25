/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itohex.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/01 11:34:46 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/01 11:34:47 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int i, long unsigned int j)
{
	while (j)
	{
		j = j / 16;
		i++;
	}
	return (i);
}

static int	ft_conv(long unsigned int n, char *out, int i)
{
	if (n / 16 > 0)
	{
		i = ft_conv(n / 16, out, i) + 1;
		out[i] = (n % 16) + '0';
		if (out[i] > '9')
			out[i] += 39;
		return (i);
	}
	out[i] = (n % 16) + '0';
	if (out[i] > '9')
		out[i] += 39;
	return (i);
}

char		*ft_itohex(long unsigned int n)
{
	int		i;
	char	*out;

	i = 0;
	if (n == 0)
		i++;
	i = ft_count(i, n);
	if (!(out = (char*)malloc(i * sizeof(char) + 1)))
		return (NULL);
	i = 0;
	i = ft_conv(n, out, i);
	out[i + 1] = 0;
	return (out);
}
