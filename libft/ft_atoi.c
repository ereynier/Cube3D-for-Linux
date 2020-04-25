/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   atoi.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 09:26:35 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 09:59:56 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long int	out;

	out = 0;
	i = 0;
	neg = 1;
	while (ft_iswspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		neg = 1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		out = out * 10 + str[i] - '0';
		i++;
	}
	return ((int)(out * neg));
}
