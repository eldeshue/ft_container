/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:27:44 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/23 22:20:20 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector_member.h"

static void	set_member_function(t_ft_vector *this)
{
	this->at = ft_vec_at;
	this->front = ft_vec_front;
	this->back = ft_vec_back;
	this->empty = ft_vec_empty;
	this->clear = ft_vec_clear;
	this->push_back = ft_vec_push_back;
	this->resize = ft_vec_resize;
}

// default constructor
t_ft_vector	*construct_ftvec(void *(*c)(void *p), void (*d)(void *d), size_t s)
{
	t_ft_vector	*this;
	void		*tmp_buffer;

	this = (t_ft_vector *)malloc(sizeof(t_ft_vector));
	tmp_buffer = (void *)malloc(sizeof(void *) * DEFAULT_FT_VECTOR_SIZE);
	if (this == NULL || tmp_buffer == NULL)
	{
		free(this);
		free(tmp_buffer);
		return (NULL);
	}
	this->pbuffer = tmp_buffer;
	this->capacity = DEFAULT_FT_VECTOR_SIZE;
	this->size = 0;
	this->data_size = s;
	set_member_function(this);
	return (this);
}

// copy constructor
// only works for level 1 deep copy.
// operation at object with more than level 1 is undefined.
t_ft_vector	*construct_ftvec_copy(t_ft_vector *origin)
{
	t_ft_vector	*this;
	size_t		local_idx;
	void		*cur_pos;

	this = construct_ftvec(origin->construct_data,
			origin->delete_data, origin->data_size);
	if (this == NULL)
		return (NULL);
	this->size = -1;
	while (++(this->size) < origin->size)
	{
		// implement further memory deep copy
	}
	return (this);
}

void	destruct_ftvec(t_ft_vector *this)
{
	size_t		idx;

	idx = -1;
	if (this->pbuffer != NULL)
	{
		while (++idx < this->size)
		{
			this->delete_data(this->pbuffer + (idx * this->data_size));
		}
		free(this->pbuffer);
	}
	free(this);
}
