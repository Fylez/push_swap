/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:12:26 by lzaengel          #+#    #+#             */
/*   Updated: 2024/01/04 17:41:23 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkdup(t_list *lst)
{
	t_list	*tocheck;
	t_list	*next;

	tocheck = lst;
	while (tocheck)
	{
		next = tocheck -> next;
		while (next)
		{
			if (tocheck -> content == next->content)
				ft_exit(lst, "Duplicate numbers");
			next = next->next;
		}
		tocheck = tocheck -> next;
	}
}
