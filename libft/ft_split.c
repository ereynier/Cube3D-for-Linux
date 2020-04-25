/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 11:21:51 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 16:51:26 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countsep(char const *s, char c)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s == c && *(s + 1) != c)
			i++;
		s++;
	}
	return (i);
}

static int	ft_dup(char const *s, char *dst, int start, char sep)
{
	int i;

	i = 0;
	while (s[start + i] != sep && s[start + i] != 0)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = 0;
	return (i);
}

char		**ft_clear(char **out, int k)
{
	if (!k)
		return (NULL);
	k--;
	while (k)
	{
		free(out[k]);
		k--;
	}
	free(out);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**out;
	int		i;
	int		k;
	int		j;

	k = 0;
	i = ft_countsep(s, c);
	if (!(out = (char**)malloc((i + 2) * sizeof(char*))))
		return (0);
	i = 0;
	while (i < (int)ft_strlen((char*)s))
	{
		j = 0;
		while (s[i + j] != c && s[i + j] != 0)
			j++;
		if (!(out[k] = (char*)malloc(j * sizeof(char) + 1)))
			return (ft_clear(out, k));
		i = i + ft_dup(s, out[k], i, c) + 1;
		if (out[k][0] != 0)
			k++;
		else
			free(out[k]);
	}
	out[k] = 0;
	return (out);
}
