/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:12:02 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/23 21:44:07 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * C++ like, norminette compatible vector container
 * do not use this code with C++ runtime

	made by dogwak
*/

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "ft_vector_struct.h"

/*
class t_ft_vector
{
	size_t			size;
	void			*at(struct s_ft_vec *this, size_t idx);
	void			*front(struct s_ft_vec *this);
	void			*back(struct s_ft_vec *this);
	int				empty(struct s_ft_vec *this);
	void			clear(struct s_ft_vec *this);
	int				push_back(struct s_ft_vec *this, void *elem);
	int				resize(struct s_ft_vec *this, size_t size);
}
*/

t_ft_vector	*construct_ftvec(void *(*c)(void *p), void (*d)(void *d), size_t s);
t_ft_vector	*construct_ftvec_copy(t_ft_vector *origin);
void		destruct_ftvec(t_ft_vector *this);

#endif
