/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:51:40 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/24 19:52:26 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector_member.h"

void	ft_vec_clear(t_ft_vector *this)
{
	size_t			idx;

	idx = -1;
	while (++idx < this->size)
	{
		this->delete_data(this->at(this, idx));
	}
	this->size = 0;
}

int	ft_vec_resize(t_ft_vector *this, size_t new_size)
{
	void			*new_buffer;
	size_t			idx;

	if (new_size == 0 || new_size == this->size)
		return (0);
	new_buffer = malloc(this->data_size * new_size);
	if (new_buffer == NULL)
		return (0);
	if (new_size < this->size)
	{
		idx = -1;
		while (new_size + ++idx < this->size)
		{
			this->delete_data(this->at(this, new_size + idx));
		}
		this->size = new_size;
	}
	idx = -1;
	while (++idx < (this->size * this->data_size))
		((unsigned int *)new_buffer)[idx]
			= ((unsigned int *)this->pbuffer)[idx];
	free(this->pbuffer);
	this->pbuffer = new_buffer;
	return (1);
}

// how to detact malloc error?
int	ft_vec_push_back(t_ft_vector *this, void *param)
{
	if (this->size == this->capacity)
		if (!ft_vec_resize(this, this->capacity * 2))
			return (0);
	if (!this->construct_data(this->at(this, this->size++), param))
		return (0);
	return (1);
}
