/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_member.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:18:27 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/24 15:45:55 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_MEMBER_H
# define FT_VECTOR_MEMBER_H

# include "ft_vector_struct.h"

# ifndef DEFAULT_FT_VECTOR_SIZE
#  define DEFAULT_FT_VECTOR_SIZE 256
# endif

// vector contents access functions
void		*ft_vec_at(t_ft_vector *this, size_t idx);
void		*ft_vec_front(t_ft_vector *this);
void		*ft_vec_back(t_ft_vector *this);
int			ft_vec_empty(t_ft_vector *this);

// vector control functions
void		ft_vec_clear(t_ft_vector *this);
int			ft_vec_push_back(t_ft_vector *this, void *param);
int			ft_vec_resize(t_ft_vector *this, size_t new_size);

#endif
