/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dqnode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:05:09 by dogwak            #+#    #+#             */
/*   Updated: 2023/11/29 19:35:05 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_member.h"

t_ft_dqnode	*construct_ftdqnode(
				void *pparam,
				int (*cd)(void *paddr, void *pparam)
				)
{
	t_ft_dqnode		*this;

	this = (t_ft_dqnode *)malloc(sizeof(t_ft_dqnode));
	if (this == NULL || cd(this->pdata, pparam))
	{
		free(this);
		return (NULL);
	}
	return (this);
}

t_ft_dqnode	*construct_ftdqnode_copy(
				t_ft_dqnode *src,
				int (*copy)(void *pdst_data, void *psrc_data)
				)
{
	t_ft_dqnode		*this;

	this = (t_ft_dqnode *)malloc(sizeof(t_ft_dqnode));
	if (this == NULL || copy(this->pdata, src->pdata))
	{
		free(this);
		return (NULL);
	}
	return (this);
}

void	destruct_ftdqnode(t_ft_dqnode *pnode, void (*dd)(void *paddr))
{
	if (pnode == NULL)
		return ;
	dd(pnode->pdata);
	free(pnode);
}
