/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_access.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:04:45 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/20 13:54:48 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_member.h"

char	*ft_str_at(t_ft_string *this, size_t idx)
{
	return (this->pbuffer + idx);
}

char	*ft_str_front(t_ft_string *this)
{
	return (this->pbuffer);
}

char	*ft_str_back(t_ft_string *this)
{
	return (this->pbuffer + (this->size - 1));
}

int	ft_str_empty(t_ft_string *this)
{
	return (this->size != 0);
}
