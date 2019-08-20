/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:16:25 by wahasni           #+#    #+#             */
/*   Updated: 2019/08/20 18:28:57 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rtdata.h"
#include "libft.h"

void	ft_assign_dir(t_object *obj, char *str)
{
	char	**tab;

	tab = ft_strsplit(&str[5], ',');
	if (obj->type == RT_PLANE)
	{
		obj->u_fig.plane.dir.x = atof(tab[0]);
		obj->u_fig.plane.dir.y = atof(tab[1]);
		obj->u_fig.plane.dir.z = atof(tab[2]);
	}
	else if (obj->type == RT_LIGHT)
	{
		obj->u_fig.light.dir.x = atof(tab[0]);
		obj->u_fig.light.dir.y = atof(tab[1]);
		obj->u_fig.light.dir.z = atof(tab[2]);
	}
	// free_split(tab);
}

void	ft_assign_dir2(t_object *obj, char *str)
{
	char	**tab;

	tab = ft_strsplit(&str[5], ',');
	if (obj->type == RT_CONE)
	{
		obj->u_fig.cone.dir.x = atof(tab[0]);
		obj->u_fig.cone.dir.y = atof(tab[1]);
		obj->u_fig.cone.dir.z = atof(tab[2]);
	}
	else if (obj->type == RT_CYL)
	{
		obj->u_fig.cyl.dir.x = atof(tab[0]);
		obj->u_fig.cyl.dir.y = atof(tab[1]);
		obj->u_fig.cyl.dir.z = atof(tab[2]);
	}
	// free_split(tab);
}

void	ft_assign_pos(t_object *obj, char *str)
{
	char	**tab;

	tab = ft_strsplit(&str[5], ',');
	if (obj->type == RT_PLANE)
	{
		obj->u_fig.plane.pos.x = atof(tab[0]);
		obj->u_fig.plane.pos.y = atof(tab[1]);
		obj->u_fig.plane.pos.z = atof(tab[2]);
	}
	else if (obj->type == RT_LIGHT)
	{
		obj->u_fig.light.pos.x = atof(tab[0]);
		obj->u_fig.light.pos.y = atof(tab[1]);
		obj->u_fig.light.pos.z = atof(tab[2]);
	}
	else if (obj->type == RT_SPHERE)
	{
		obj->u_fig.sphere.pos.x = atof(tab[0]);
		obj->u_fig.sphere.pos.y = atof(tab[1]);
		obj->u_fig.sphere.pos.z = atof(tab[2]);
	}
	// free_split(tab);
}

void	ft_assign_pos2(t_object *obj, char *str)
{
	char	**tab;

	tab = ft_strsplit(&str[5], ',');
	if (obj->type == RT_CONE)
	{
		obj->u_fig.cone.pos.x = atof(tab[0]);
		obj->u_fig.cone.pos.y = atof(tab[1]);
		obj->u_fig.cone.pos.z = atof(tab[2]);
	}
	else if (obj->type == RT_CYL)
	{
		obj->u_fig.cyl.pos.x = atof(tab[0]);
		obj->u_fig.cyl.pos.y = atof(tab[1]);
		obj->u_fig.cyl.pos.z = atof(tab[2]);
	}
	//free_split(tab);
}