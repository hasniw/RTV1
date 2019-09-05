/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:10:34 by wahasni           #+#    #+#             */
/*   Updated: 2019/09/05 04:44:29 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rtdata.h"
#include <fcntl.h> // Open
#include "libft.h"
#include <stdio.h> // Juste pour tester

static int	ft_check_node(t_object *chill) //Tcheck si au moins un objet a ete insere
{
	t_object *obj = chill;

	while (obj->prev)
		obj = obj->prev;
	while (obj->next)
	{
		if (obj->type == RT_CYL || obj->type == RT_CONE
		|| obj->type == RT_PLANE || obj->type == RT_SPHERE)
			return (0);
		obj = obj->next;
	}
	return (1);
}

int			parser(t_fmlx *rtv, char *file)
{
	int			fd;
	int			error;
	char		*line;
	t_object	*obj;

	if ((fd = open(file, 0)) < 0)
		return (ft_error("Opening file failed."));
	while (get_next_line(fd, &line) >= 0)
	{
		if (!rtv->obj)
		{
			rtv->obj = ft_create_list();
			obj = rtv->obj;
		}
		else // Je cree un maillon en trop
		{
			ft_list_add_last(&rtv->obj, ft_create_list());
			while (obj->next)
				obj = obj->next;
		}
		if (ft_strnequ(line, "plane: ", 7))
			error = ft_parse_objs(obj, fd, RT_PLANE, line);
		else if (ft_strnequ(line, "sphere: ", 8))
			error = ft_parse_objs(obj, fd, RT_SPHERE, line);
		else if (ft_strnequ(line, "cylinder: ", 10))
			error = ft_parse_objs(obj, fd, RT_CYL, line);
		else if (ft_strnequ(line, "cone: ", 6))
			error = ft_parse_objs(obj, fd, RT_CONE, line);
		else if (ft_strnequ(line, "light: ", 7))
			error = ft_parse_objs(obj, fd, RT_LIGHT, line);
		else if (ft_check_node(obj) || error)
			return (ft_error("missing object")); //free_all()
		else
			return (0);
		// if (variable cree test erreur dans parse_objs)
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
