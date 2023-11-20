/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:45:56 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/18 19:27:56 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_UTIL_H
# define FT_STRING_UTIL_H

# include "ft_string_struct.h"
# include <stdlib.h>

# ifndef DEFAULT_FT_STRING_SIZE
#  define DEFAULT_FT_STRING_SIZE 100
# endif

// member functions
char		ft_str_at(t_ft_string *this, size_t idx);
char		ft_str_front(t_ft_string *this);
char		ft_str_back(t_ft_string *this);
int			ft_str_empty(t_ft_string *this);
int			ft_str_compare(t_ft_string *this);
void		ft_str_clear(t_ft_string *this);
void		ft_str_push_back(t_ft_string *this, char c);
void		ft_str_resize(t_ft_string *this, size_t size);
t_ft_string	*ft_str_join(t_ft_string *this, t_ft_string *ftstr);
t_ft_string	*ft_str_substr(t_ft_string *this, size_t start, size_t size);
char		*ft_str_c_str(t_ft_string *this);
void		*ft_str_getline(t_ft_string *this, int fd);

// utility functions

#endif
