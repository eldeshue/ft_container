/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_construct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:09:56 by dogwak            #+#    #+#             */
/*   Updated: 2023/12/12 14:18:27 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_member.h"

void	destruct_ftdeque(t_ft_deque *this)
{
	if (this == NULL)
		return ;
	ft_deque_clear(this);
}

t_ft_deque	construct_ftdeque(int (*cd)(void *paddr, void *pparam),
		void (*dd)(void *paddr), size_t s)
{
	t_ft_deque	this;

	this.size = 0;
	this.data_size = s;
	this.start_node = NULL;
	this.end_node = NULL;
	this.construct_data = cd;
	this.destruct_data = dd;
	set_deque_member_function(&this);
	return (this);
}

t_ft_deque	construct_ftdeque_copy(t_ft_deque *src,
		int (*copy)(void *pdst_data, void *psrc_data))
{
	t_ft_deque	this;
	t_ft_dqnode	*src_dqnode;
	t_ft_dqnode	*new_dqnode;

	this = construct_ftdeque(src->construct_data, src->destruct_data,
			src->data_size);
	src_dqnode = src->start_node;
	while (this.size < src->size)
	{
		new_dqnode = construct_ftdqnode_copy(src_dqnode, this.data_size, copy);
		if (new_dqnode == NULL || !ft_deque_push_back_node(&this, new_dqnode))
		{
			destruct_ftdqnode(new_dqnode, this.destruct_data);
			destruct_ftdeque(&this);
			return (this);
		}
		this.size++;
		src_dqnode = src_dqnode->pnext;
	}
	return (this);
}
