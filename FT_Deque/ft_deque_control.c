/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:19:40 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/28 21:27:00 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_member.h"

void	ft_deque_clear(struct s_ft_deque *this)
{
	t_ft_dqnode		*ptmp_node;
	t_ft_dqnode		*target_node;
	size_t			erase_cnt;

	target_node = this->start_node;
	erase_cnt = this->size;
	while (--erase_cnt)
	{
		ptmp_node = target_node->pnext;
		this->destruct_data(target_node->pdata);
		free(target_node);
		target_node = ptmp_node;
	}
	this->start_node = NULL;
	this->end_node = NULL;
}
