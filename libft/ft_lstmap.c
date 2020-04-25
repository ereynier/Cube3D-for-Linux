/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap_bonus.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 13:50:22 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 11:12:23 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	**out;
	t_list	*new;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	if (!(out = malloc(sizeof(t_list))))
		return (NULL);
	while (lst)
	{
		if (!(new = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(out, del);
			return (NULL);
		}
		ft_lstadd_back(out, new);
		lst = lst->next;
	}
	return (*out);
}
