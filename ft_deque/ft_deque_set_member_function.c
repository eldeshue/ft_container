/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_set_deque_member_function.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:07:45 by dogwak            #+#    #+#             */
/*   Updated: 2023/12/12 14:08:09 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_member.h"

void	set_deque_member_function(t_ft_deque *this)
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
