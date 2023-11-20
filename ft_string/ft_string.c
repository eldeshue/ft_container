/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:43:19 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/18 19:27:51 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_util.h"

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
	this->join = ft_str_join;
	this->substr = ft_str_substr;
	this->c_str = ft_str_c_str;
	this->getline = ft_str_getline;
}

t_ft_string	*construct_ftstr(void)
{
	t_ft_string		*this;
	char			*tmp_buffer;

	this = (t_ft_string *)malloc(sizeof(t_ft_string));
	tmp_buffer = (char *)mallco(DEFAULT_FT_STRING_SIZE);
	if (this == NULL || tmp_buffer == NULL)
	{
		free(this);
		free(tmp_buffer);
		return (NULL);
	}
	this->capacity = DEFAULT_FT_STRING_SIZE;
	this->size = 0;
	set_member_function(this);
	return (this);
}

t_ft_string	*construct_ftstr_len(size_t len)
{
	t_ft_string		*this;
	char			*tmp_buffer;

	this = (t_ft_string *)malloc(sizeof(t_ft_string));
	tmp_buffer = (char *)mallco(len);
	if (this == NULL || tmp_buffer == NULL)
	{
		free(this);
		free(tmp_buffer);
		return (NULL);
	}
	this->capacity = len;
	this->size = 0;
	set_member_function(this);
	return (this);
}

t_ft_string	*construct_ftstr_cstr(char *cstr)
{
	t_ft_string		*this;
	size_t			idx;

	this = construct_ftstr();
	if (this == NULL)
		return (NULL);
	idx = -1;
	while (cstr[++idx] != '\0')
	{
		if (idx == this->capacity)
		{
			ft_str_resize(this, 2 * this->capacity);
			if (this == NULL)
				return (NULL);
		}
		this->pbuffer[idx] = cstr[idx];
		this->size++;
	}
	return (this);
}

void	destruct_ftstr(t_ft_string *ftstr)
{
	if (ftstr != NULL)
		free(ftstr->pbuffer);
	free(ftstr);
	ftstr = NULL;
}
