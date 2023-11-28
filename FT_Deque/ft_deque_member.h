/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_member.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:53:58 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/28 21:39:54 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_MEMBER_H
# define FT_DEQUE_MEMBER_H

# include "ft_deque_struct.h"

// deque access
void		*ft_deque_front(struct s_ft_deque *this);
void		*ft_deque_back(struct s_ft_deque *this);
int			ft_deque_empty(struct s_ft_deque *this);

// deque control
void		ft_deque_clear(struct s_ft_deque *this);
int			ft_deque_push_front(struct s_ft_deque *this, void *elem);
int			ft_deque_push_back(struct s_ft_deque *this, void *elem);
int			ft_deque_pop_front(struct s_ft_deque *this);
int			ft_deque_pop_back(struct s_ft_deque *this);

// node

#endif
