/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:35:37 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/28 20:25:37 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_STRUCT_H
# define FT_DEQUE_STRUCT_H

# include <stdlib.h>

typedef struct s_ft_deque_node
{
	void					*pdata;
	struct s_ft_deque_node	*pnext;
	struct s_ft_deque_node	*pprev;
}							t_ft_dqnode;

typedef struct s_ft_deque
{
	size_t		size;
	size_t		data_size;
	t_ft_dqnode	*start_node;
	t_ft_dqnode	*end_node;
	int			(*construct_data)(void *address, void *param);
	void		(*destruct_data)(void *data);
	void		*(*front)(struct s_ft_deque *this);
	void		*(*back)(struct s_ft_deque *this);
	int			(*empty)(struct s_ft_deque *this);
	void		(*clear)(struct s_ft_deque *this);
	int			(*push_front)(struct s_ft_deque *this, void *elem);
	int			(*push_back)(struct s_ft_deque *this, void *elem);
	int			(*pop_front)(struct s_ft_deque *this);
	int			(*pop_back)(struct s_ft_deque *this);
}				t_ft_deque;

#endif
