/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 10:40:49 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 10:55:55 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*out;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = (int)ft_strlen((char*)(s1)) + (int)ft_strlen((char*)(s2) + 1);
	if (!(out = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		out[i + j] = s2[j];
		j++;
	}
	out[i + j] = '\0';
	return (out);
}
