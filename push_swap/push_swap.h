/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fylez <fylez@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:19:15 by liam              #+#    #+#             */
/*   Updated: 2023/12/27 17:04:08 by fylez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
//# include "include/libftfin/libft.h"

typedef struct s_list {
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

void	ft_lstprint(t_list *lst);

#endif