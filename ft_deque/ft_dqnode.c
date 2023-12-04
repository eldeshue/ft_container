/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dqnode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:05:09 by dogwak            #+#    #+#             */
/*   Updated: 2023/12/01 11:12:13 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_member.h"

t_ft_dqnode	*construct_ftdqnode(void *pparam, size_t data_size,
		int (*cd)(void *paddr, void *pparam))
{
	t_ft_dqnode	*this;

	this = (t_ft_dqnode *)malloc(sizeof(t_ft_dqnode));
	if (this == NULL)
		return (NULL);
	this->pdata = malloc(data_size);
	if (this->pdata == NULL || !cd(this->pdata, pparam))
	{
		free(this);
		return (NULL);
	}
	this->pnext = NULL;
	this->pprev = NULL;
	return (this);
}

t_ft_dqnode	*construct_ftdqnode_copy(t_ft_dqnode *src, size_t data_size,
		int (*copy)(void *pdst_data, void *psrc_data))
{
	t_ft_dqnode	*new_node;

	new_node = (t_ft_dqnode *)malloc(sizeof(t_ft_dqnode));
	if (new_node == NULL)
		return (NULL);
	new_node->pdata = malloc(data_size);
	if (new_node->pdata == NULL || !copy(new_node->pdata, src->pdata))
	{
		free(new_node);
		return (NULL);
	}
	return (new_node);
}

void	destruct_ftdqnode(t_ft_dqnode *pnode, void (*dd)(void *paddr))
{
	if (pnode == NULL)
		return ;
	dd(pnode->pdata);
	free(pnode->pdata);
	free(pnode);
}
