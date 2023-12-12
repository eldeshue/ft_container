/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:33:10 by dogwak            #+#    #+#             */
/*   Updated: 2023/12/12 14:10:43 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_H
# define FT_DEQUE_H

# include "ft_deque_struct.h"

/*
class t_ft_deque
{
	void			*front(struct s_ft_deque *this);
	void			*back(struct s_ft_deque *this);
	int				empty(struct s_ft_deque *this);
	void			clear(struct s_ft_deque *this);
	int				push_front(struct s_ft_deque *this, void *elem);
	int				push_back(struct s_ft_deque *this, void *elem);
	int				pop_front(struct s_ft_deque *this);
	int				pop_back(struct s_ft_deque *this);
}
*/

// default constructor
t_ft_deque	construct_ftdeque(
				int (*cd)(void *paddr, void *pparam),
				void (*dd)(void *paddr),
				size_t s);

// copy constructor
t_ft_deque	construct_ftdeque_copy(
				t_ft_deque *src,
				int (*copy)(void *pdst_data, void *psrc_data));

// destructor
void		destruct_ftdeque(t_ft_deque *this);

// default constructor
t_ft_deque	*new_ftdeque(
				int (*cd)(void *paddr, void *pparam),
				void (*dd)(void *paddr),
				size_t s);

// copy constructor
t_ft_deque	*new_ftdeque_copy(
				t_ft_deque *src,
				int (*copy)(void *pdst_data, void *psrc_data));

// destructor
void		delete_ftdeque(t_ft_deque *this);
#endif
