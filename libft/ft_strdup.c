/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 20:35:22 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 20:53:25 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	if ((dup = (char*)malloc(i * sizeof(char) + 1)) == 0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
