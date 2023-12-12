/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_member.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:53:58 by dogwak            #+#    #+#             */
/*   Updated: 2023/12/12 14:22:14 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_MEMBER_H
# define FT_DEQUE_MEMBER_H

# include "ft_deque_struct.h"

// set member function
void		set_deque_member_function(t_ft_deque *this);

// deque access
void		*ft_deque_front(t_ft_deque *this);
void		*ft_deque_back(t_ft_deque *this);
int			ft_deque_empty(t_ft_deque *this);

// deque control
void		ft_deque_clear(t_ft_deque *this);
int			ft_deque_pop_front(t_ft_deque *this);
int			ft_deque_pop_back(t_ft_deque *this);

// deque push
int			ft_deque_push_front_node(t_ft_deque *this, t_ft_dqnode *node);
int			ft_deque_push_front(t_ft_deque *this, void *pparam);

int			ft_deque_push_back_node(t_ft_deque *this, t_ft_dqnode *node);
int			ft_deque_push_back(t_ft_deque *this, void *pparam);

// node
t_ft_dqnode	*construct_ftdqnode(void *pparam, size_t data_size,
				int (*cd)(void *paddr, void *pparam));
t_ft_dqnode	*construct_ftdqnode_copy(t_ft_dqnode *src, size_t data_size,
				int (*copy)(void *pdst_data, void *psrc_data));
void		destruct_ftdqnode(t_ft_dqnode *pnode, void (*dd)(void *paddr));

#endif
