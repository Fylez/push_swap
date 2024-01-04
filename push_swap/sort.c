/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:17:47 by lzaengel          #+#    #+#             */
/*   Updated: 2024/01/03 16:46:32 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdel(t_list *lst)
{
	t_list	*prev;
	t_list	*next;

	lst = ft_lstlast(lst);
	if (lst -> index != 1)
	{
		prev = lst -> prev;
		next = lst -> next;
		prev -> next = next;
		next -> prev = prev;
		lst -> prev = NULL;
		lst -> next = NULL;
	}
}

void	sasb(t_list *lst)
{
	t_list	*next;
	int		c;

	next = lst -> next;
	c = lst -> content;
	lst -> content = next -> content;
	next -> content = c;
}

void	pa(t_list *lst, t_list **lst2)
{
	t_list	*topush;

	topush = ft_lstlast(lst);
	ft_printf("%s\n", "TEST1");
	ft_lstdel(lst);
	ft_printf("%s\n", "TEST2");
	ft_lstadd_back(lst2, topush);
	//ft_printf("%d\n", topush->content );
	//ft_lstprint(lst2);
}
