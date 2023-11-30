/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:17:31 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/30 19:51:31 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_member.h"

static void	ft_push_first_node(t_ft_deque *this, t_ft_dqnode *node)
{
	this->start_node = node;
	this->end_node = node;
	this->size = 1;
}

int	ft_deque_push_front_node(t_ft_deque *this, t_ft_dqnode *node)
{
	if (this->size == 0)
	{
		ft_push_first_node(this, node);
		return (1);
	}
	node->pnext = this->start_node;
	this->start_node->pprev = node;
	this->start_node = node;
	this->size++;
	return (1);
}

int	ft_deque_push_front(t_ft_deque *this, void *pparam)
{
	t_ft_dqnode	*new_node;

	new_node = construct_ftdqnode(pparam, this->data_size,
			this->construct_data);
	if (new_node == NULL || !ft_deque_push_front_node(this, new_node))
	{
		destruct_ftdqnode(new_node, this->destruct_data);
		return (0);
	}
	return (1);
}

int	ft_deque_push_back_node(t_ft_deque *this, t_ft_dqnode *node)
{
	if (this->size == 0)
	{
		ft_push_first_node(this, node);
		return (1);
	}
	node->pprev = this->end_node;
	this->end_node->pnext = node;
	this->end_node = node;
	this->size++;
	return (1);
}

int	ft_deque_push_back(t_ft_deque *this, void *pparam)
{
	t_ft_dqnode	*new_node;

	new_node = construct_ftdqnode(pparam, this->data_size,
			this->construct_data);
	if (new_node == NULL || !ft_deque_push_back_node(this, new_node))
	{
		destruct_ftdqnode(new_node, this->destruct_data);
		return (0);
	}
	return (1);
}
