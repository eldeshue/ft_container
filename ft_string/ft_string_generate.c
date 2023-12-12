/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_generate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:27:58 by dogwak            #+#    #+#             */
/*   Updated: 2023/12/12 11:20:17 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_member.h"

// using static keyword, can evade double definition
static void	set_member_function(t_ft_string *this)
{
	this->at = ft_str_at;
	this->front = ft_str_front;
	this->back = ft_str_back;
	this->empty = ft_str_empty;
	this->compare = ft_str_compare;
	this->clear = ft_str_clear;
	this->push_back = ft_str_push_back;
	this->resize = ft_str_resize;
	this->copy = ft_str_copy;
	this->join = ft_str_join;
	this->substr = ft_str_substr;
	this->append = ft_str_append;
	this->add = ft_str_add;
	this->c_str = ft_str_c_str;
	this->getline = ft_str_getline;
	this->getword = ft_str_getword;
}

// copy constructor for ft_string
t_ft_string	*ft_str_copy(t_ft_string *this)
{
	t_ft_string		*new_string;
	char			*tmp_buffer;
	size_t			idx;

	new_string = (t_ft_string *)malloc(sizeof(t_ft_string));
	tmp_buffer = (char *)malloc(this->capacity);
	if (new_string == NULL || tmp_buffer == NULL)
	{
		free(new_string);
		free(tmp_buffer);
		return (NULL);
	}
	new_string->pbuffer = tmp_buffer;
	new_string->capacity = this->capacity;
	new_string->size = this->size;
	set_member_function(new_string);
	idx = -1;
	while (++idx < new_string->size)
		new_string->pbuffer[idx] = this->pbuffer[idx];
	return (new_string);
}

t_ft_string	*ft_str_substr(t_ft_string *this, size_t start, size_t size)
{
	t_ft_string		*new_string;
	char			*tmp_buffer;
	size_t			idx;

	new_string = (t_ft_string *)malloc(sizeof(t_ft_string));
	tmp_buffer = (char *)malloc(this->capacity);
	if (new_string == NULL || tmp_buffer == NULL)
	{
		free(new_string);
		free(tmp_buffer);
		return (NULL);
	}
	new_string->pbuffer = tmp_buffer;
	new_string->capacity = this->capacity;
	new_string->size = size;
	set_member_function(new_string);
	idx = -1;
	while (++idx < new_string->size)
		new_string->pbuffer[idx] = this->pbuffer[start + idx];
	return (new_string);
}

t_ft_string	*ft_str_join(t_ft_string *this, t_ft_string *ftstr)
{
	t_ft_string		*new_string;

	new_string = ft_str_copy(this);
	if (new_string == NULL || !ft_str_add(new_string, ftstr))
		return (NULL);
	return (new_string);
}
