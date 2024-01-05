/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:19:15 by liam              #+#    #+#             */
/*   Updated: 2024/01/05 01:42:25 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
//# include "include/libftfin/libft.h"

typedef struct s_list {
	int				content;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;

}	t_list;

void	ft_lstprint(t_list *lst);
void	checkdup(t_list *lst);
void	ft_exit(t_list *lst, char *reason);
void	sasb(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdel(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	pa(t_list *lst, t_list **lst2);
void	ra(t_list **lst);
void	rra(t_list **lst);
#endif