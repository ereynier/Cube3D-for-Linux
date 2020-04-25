/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 10:56:40 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 19:21:17 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charcomp(char const c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		finish;
	int		i;
	char	*out;

	start = 0;
	finish = 0;
	i = 0;
	if (!(s1) || !(set))
		return (NULL);
	while (s1[i] && ft_charcomp(s1[i], set))
		i++;
	start = i;
	while (s1[i])
		i++;
	i--;
	while (i > 0 && ft_charcomp(s1[i], set))
		i--;
	finish = i;
	if (!(out = ft_substr(s1, start, finish - start + 1)))
		return (NULL);
	return (out);
}
