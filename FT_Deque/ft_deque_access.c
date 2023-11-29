/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:36:12 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/29 19:43:57 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_member.h"

void	*ft_deque_front(t_ft_deque *this)
{
	if (this->size == 0)
		return (NULL);
	return (this->start_node->pdata);
}

void	*ft_deque_back(t_ft_deque *this)
{
	if (this->size == 0)
		return (NULL);
	return (this->end_node->pdata);
}

int	ft_deque_empty(t_ft_deque *this)
{
	if (this->size == 0)
		return (1);
	return (0);
}
