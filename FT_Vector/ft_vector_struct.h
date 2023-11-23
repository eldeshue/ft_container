/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:14:54 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/23 10:58:06 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_STRUCT_H
# define FT_VECTOR_STRUCT_H

typedef struct s_ft_vec
{
	void			*pdata;
	size_t			size;
	size_t			capacity;
	void			(*delete_data)(void *data);
	void			*(*at)(struct s_ft_vec *this, size_t idx);
	void			*(*front)(struct s_ft_vec *this);
	void			*(*back)(struct s_ft_vec *this);
	int				(*empty)(struct s_ft_vec *this);
	void			(*clear)(struct s_ft_vec *this);
	int				(*push_back)(struct s_ft_vec *this, void *elem);
	int				(*resize)(struct s_ft_vec *this, size_t size);
	struct s_ft_vec	*(*copy)(struct s_ft_vec *this);
}	t_ft_vector;

#endif
