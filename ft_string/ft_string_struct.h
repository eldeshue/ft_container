/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:30:01 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/18 19:24:07 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_STRUCT_H
# define FT_STRING_STRUCT_H

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
	void			(*getline)(struct s_ft_str *this, int fd);
}	t_ft_string;

#endif
