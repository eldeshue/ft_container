/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_generate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:27:58 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/20 13:55:13 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_member.h"

// copy constructor for ft_string
t_ft_string	*ft_str_copy(t_ft_string *this)
{
	t_ft_string		*new_string;
	char			*tmp_buffer;
	int				idx;

	new_string = (t_ft_string *)malloc(sizeof(t_ft_string));
	tmp_buffer = (char *)malloc(this->capacity);
	if (new_string == NULL || tmp_buffer == NULL)
	{
		free(new_string);
		free(tmp_buffer);
		return (NULL);
	}
	new_string->capacity = this->capacity;
	new_string->size = this->size;
	set_member_function(new_string);
	idx = -1;
	while (idx < new_string->size)
		new_string->pbuffer[idx] = this->pbuffer[idx];
	return (new_string);
}

t_ft_string	*ft_str_substr(t_ft_string *this, size_t start, size_t size)
{
	t_ft_string		*new_string;
	char			*tmp_buffer;
	int				idx;

	new_string = (t_ft_string *)malloc(sizeof(t_ft_string));
	tmp_buffer = (char *)malloc(this->capacity);
	if (new_string == NULL || tmp_buffer == NULL)
	{
		free(new_string);
		free(tmp_buffer);
		return (NULL);
	}
	new_string->capacity = this->capacity;
	new_string->size = size;
	set_member_function(new_string);
	idx = -1;
	while (idx < new_string->size)
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
