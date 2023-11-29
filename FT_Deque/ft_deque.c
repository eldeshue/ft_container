/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:55:07 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/29 19:11:03 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_member.h"

static void	set_member_function(t_ft_deque *this)
{
	this->front = ft_deque_front;
	this->back = ft_deque_back;
	this->empty = ft_deque_empty;
	this->clear = ft_deque_clear;
	this->push_front = ft_deque_push_front;
	this->push_back = ft_deque_push_back;
	this->pop_front = ft_deque_pop_front;
	this->pop_back = ft_deque_pop_back;
}

void	destruct_ftdeque(t_ft_deque *this)
{
	if (this == NULL)
		return (NULL);
	ft_deque_clear(this);
	free(this);
}

t_ft_deque	*construct_ftdeque(
				int (*cd)(void *paddr, void *pparam),
				void (*dd)(void *paddr),
				size_t s)
{
	t_ft_deque	*this;

	this = (t_ft_deque *)malloc(sizeof(t_ft_deque));
	if (this == NULL)
		return (NULL);
	this->size = 0;
	this->data_size = s;
	this->start_node = NULL;
	this->end_node = NULL;
	this->construct_data = cd;
	this->destruct_data = dd;
	set_member_function(this);
	return (this);
}

t_ft_deque	*construct_ftdeque_copy(
				t_ft_deque *src,
				int (*copy)(void *pdst_data, void *psrc_data))
{
	t_ft_deque	*this;
	t_ft_dqnode	*src_dqnode;
	t_ft_dqnode	*new_dqnode;

	this = construct_ftdeque(
			src->construct_data, src->destruct_data, src->data_size);
	if (this == NULL)
		return (NULL);
	src_dqnode = src->start_node;
	while (this->size < src->size)
	{
		new_dqnode = construct_ftdqnode_copy(src_dqnode, copy);
		if (new_dqnode == NULL || !ft_deque_push_back_node(this, new_dqnode))
		{
			destruct_ftdqnode(new_dqnode, this->destruct_data);
			destruct_ftdeque(this);
			return (NULL);
		}
		this->size++;
		src_dqnode = src_dqnode->pnext;
	}
	return (this);
}
