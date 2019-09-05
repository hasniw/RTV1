/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 04:58:55 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/09/03 00:58:12 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <strings.h>
#include <stdlib.h>
//DELETE
#include <stdio.h>

t_object	*get_prevlink(t_fmlx *mlx)
{
	t_object	*obj;

	obj = mlx->obj;
	if (mlx->current->prev != NULL)
		return (mlx->current->prev);
	while (obj && obj->next)
		obj = obj->next;
	return (obj);
}

void		rt_delist(t_fmlx *mlx)
{
	t_object	*obj;
	t_object	*next;

	obj = mlx->obj;
	mlx->obj = NULL;
	mlx->current = NULL;
	next = obj;
	while (next)
	{
		printf("%s %p\n", obj->name, obj);
		next = obj->next;
		ft_bzero(obj, sizeof(obj));
		free(obj);
		printf("%p\n", obj);
		obj = next;
	}
	while (1)
		;
}

void		ft_list_add_last(t_object **save, t_object *elem)
{
	t_object *list;

	list = *save;
	while (list->next)
		list = list->next;
	list->next = elem;
	elem->prev = list;
}


t_object	*ft_create_list(void)
{
	t_object *list;

	if (!(list = (t_object*)malloc(sizeof(t_object))))
		return (NULL);
	list->next = NULL;
	list->prev = NULL;
	return (list);
}
