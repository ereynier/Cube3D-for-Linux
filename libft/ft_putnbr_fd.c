/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 14:57:16 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 15:49:32 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	j;
	char		c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		j = -n;
		write(fd, "-", 1);
	}
	else
		j = n;
	if ((j / 10) != 0)
	{
		ft_putnbr_fd((j / 10), fd);
		c = j % 10 + '0';
		write(fd, &c, 1);
		return ;
	}
	c = j % 10 + '0';
	write(fd, &c, 1);
	return ;
}
