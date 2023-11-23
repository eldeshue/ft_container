/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_access.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:04:45 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/23 21:37:51 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_member.h"

char	*ft_str_at(t_ft_string *this, size_t idx)
{
	if (this->size >= idx)
	{
		if (this->capacity >= idx)
		{
			while (this->capacity >= idx)
				if (!ft_str_resize(this, this->capacity * 2))
					return (NULL);
		}
		while (this->size <= idx)
			this->pbuffer[this->size++] = ' ';
	}
	return (this->pbuffer + idx);
}

char	*ft_str_front(t_ft_string *this)
{
	if (this->size == 0)
		return (NULL);
	return (this->pbuffer);
}

char	*ft_str_back(t_ft_string *this)
{
	if (this->size == 0)
		return (NULL);
	return (this->pbuffer + (this->size - 1));
}

int	ft_str_empty(t_ft_string *this)
{
	return (this->size != 0);
}
