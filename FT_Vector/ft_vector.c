/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:27:44 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/24 19:49:37 by dogwak           ###   ########.fr       */
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
t_ft_vector	*construct_ftvec(
				int (*cd)(void *paddr, void *pparam),
				void (*dd)(void *pparam),
				size_t s)
{
	t_ft_vector	*this;
	void		*tmp_buffer;

	this = (t_ft_vector *)malloc(sizeof(t_ft_vector));
	tmp_buffer = malloc(s * DEFAULT_FT_VECTOR_SIZE);
	if (this == NULL || tmp_buffer == NULL)
	{
		free(this);
		free(tmp_buffer);
		return (NULL);
	}
	this->pbuffer = tmp_buffer;
	this->construct_data = cd;
	this->delete_data = dd;
	this->capacity = DEFAULT_FT_VECTOR_SIZE;
	this->size = 0;
	this->data_size = s;
	set_member_function(this);
	return (this);
}

void	destruct_ftvec(t_ft_vector *this)
{
	size_t		idx;

	idx = -1;
	if (this->pbuffer != NULL)
	{
		while (++idx < this->size)
			this->delete_data(this->pbuffer + idx * this->data_size);
		free(this->pbuffer);
	}
	free(this);
}

// copy constructor, deep
// only works for level 1 deep copy.
// operation at object with more than level 1 is undefined.
t_ft_vector	*construct_ftvec_copy(
				t_ft_vector *src,
				int (*copy)(void *pdst_node, void *psrc_node))
{
	t_ft_vector		*this;

	this = construct_ftvec(src->construct_data, src->delete_data,
			src->data_size);
	if (this == NULL)
		return (NULL);
	if (!this->resize(this, src->capacity))
	{
		destruct_ftvec(this);
		return (NULL);
	}
	this->size = 0;
	while (this->size < src->size)
	{
		if (copy(this->at(this, this->size), src->at(src, this->size)))
		{
			this->size++;
			destruct_ftvec(this);
			return (NULL);
		}
		this->size++;
	}
	return (this);
}
