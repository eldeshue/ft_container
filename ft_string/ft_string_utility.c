/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:55:02 by dogwak            #+#    #+#             */
/*   Updated: 2023/12/22 15:19:01 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_member.h"
#include <unistd.h>

int	ft_str_compare(t_ft_string *this, t_ft_string *ftstr)
{
	size_t		cmp_size;
	size_t		idx;

	cmp_size = this->size;
	if (this->size > ftstr->size)
		cmp_size = ftstr->size;
	idx = -1;
	while (++idx < cmp_size)
	{
		if (this->pbuffer[idx] != ftstr->pbuffer[idx])
			return ((unsigned char)(this->pbuffer[idx])
				- (unsigned char)(ftstr->pbuffer[idx]));
	}
	return (0);
}

char	*ft_str_c_str(t_ft_string *this)
{
	if (!this || !ft_str_push_back(this, '\0'))
		return (NULL);
	this->size--;
	return (this->pbuffer);
}

int	ft_str_getline(t_ft_string *this, int fd)
{
	char		input_char;
	ssize_t		read_size;
	ssize_t		total_size;

	if (fd < 0)
		return (-1);
	this->size = 0;
	input_char = -1;
	total_size = 0;
	read_size = read(fd, &input_char, 1);
	while (read_size > 0 && input_char != '\n')
	{
		if (!ft_str_push_back(this, input_char))
			return (-1);
		read_size = read(fd, &input_char, 1);
		if (read_size < 0)
			return (-1);
		total_size += read_size;
	}
	return (total_size);
}

int	ft_str_getword(t_ft_string *this, int fd)
{
	char		input_char;
	ssize_t		read_size;
	ssize_t		total_size;

	if (fd < 0)
		return (-1);
	this->size = 0;
	input_char = -1;
	total_size = 0;
	read_size = read(fd, &input_char, 1);
	while (read_size > 0
		&& (input_char != ' ' || input_char != '\t' || input_char != '\n'
			|| input_char != '\v' || input_char != '\f' || input_char != '\r'))
	{
		if (!ft_str_push_back(this, input_char))
			return (-1);
		read_size = read(fd, &input_char, 1);
		if (read_size < 0)
			return (-1);
		total_size += read_size;
	}
	return (total_size);
}
