/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:47:43 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/17 17:17:12 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>
# include "ft_string_struct.h"

# ifndef DEFAULT_FT_STRING_SIZE
#  define DEFAULT_FT_STRING_SIZE 100
# endif

/*
typedef struct s_ft_str
{
	char			*pbuffer;
	size_t			size;
	size_t			capacity;
	char			(*at)(struct s_ft_str *this, size_t idx);
	char			(*front)(struct s_ft_str *this);
	char			(*back)(struct s_ft_str *this);
	int				(*empty)(struct s_ft_str *this);
	int				(*compare)(struct s_ft_str *this);
	void			(*clear)(struct s_ft_str *this);
	void			(*push_back)(struct s_ft_str *this, char c);
	void			(*resize)(struct s_ft_str *this, size_t size);
	struct s_ft_str	*(*join)(struct s_ft_str *this, struct s_ft_str *ftstr);
	struct s_ft_str	*(*substr)(struct s_ft_str *this, size_t strt, size_t size);
	char			*(*c_str)(struct s_ft_str *this);
}	t_ft_string;
*/

t_ft_string	*construct_ftstr(void);
t_ft_string	*construct_ftstr_len(size_t len);
t_ft_string	*construct_ftstr_cstr(char *cstr);
void		destruct_ftstr(t_ft_string *this);

#endif
