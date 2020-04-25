/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lst_clear.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 17:41:58 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 20:45:16 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *ptr;

	ptr = *lst;
	if (!lst || !del)
		return ;
	while (ptr)
	{
		(*del)(ptr);
		*lst = ptr->next;
		free(ptr->next);
		free(ptr);
		ptr = *lst;
	}
}
