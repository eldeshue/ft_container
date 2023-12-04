/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:19:40 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/29 20:08:08 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_member.h"

void	ft_deque_clear(struct s_ft_deque *this)
{
	t_ft_dqnode		*ptmp_node;
	t_ft_dqnode		*ptarget_node;
	size_t			erase_cnt;

	ptarget_node = this->start_node;
	erase_cnt = this->size;
	while (erase_cnt--)
	{
		ptmp_node = ptarget_node->pnext;
		destruct_ftdqnode(ptarget_node, this->destruct_data);
		ptarget_node = ptmp_node;
	}
	this->size = 0;
	this->start_node = NULL;
	this->end_node = NULL;
}

int	ft_deque_pop_front(t_ft_deque *this)
{
	t_ft_dqnode		*ptmp_node;

	if (this->size == 0)
		return (0);
	else if (this->size == 1)
	{
		destruct_ftdqnode(this->start_node, this->destruct_data);
		this->start_node = NULL;
		this->end_node = NULL;
		return (1);
	}
	ptmp_node = this->start_node->pnext;
	destruct_ftdqnode(this->start_node, this->destruct_data);
	this->start_node = ptmp_node;
	this->start_node->pprev = NULL;
	return (1);
}

int	ft_deque_pop_back(t_ft_deque *this)
{
	t_ft_dqnode		*ptmp_node;

	if (this->size == 0)
		return (0);
	else if (this->size == 1)
	{
		destruct_ftdqnode(this->end_node, this->destruct_data);
		this->start_node = NULL;
		this->end_node = NULL;
		return (1);
	}
	ptmp_node = this->end_node->pprev;
	destruct_ftdqnode(this->end_node, this->destruct_data);
	this->end_node = ptmp_node;
	this->end_node->pnext = NULL;
	return (1);
}
