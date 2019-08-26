/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:48:07 by wahasni           #+#    #+#             */
/*   Updated: 2019/08/26 17:29:44 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rtdata.h"
#include "libft.h"
#include <string.h> // Le temps de coder atod
#include <stdio.h> // Juste pour tester

static void	ft_assign_cam(t_object *obj, char **tab, int value)
{
	// Si la valeur est superieur au double -> 0 à la variable
	if (value == 1)
	{
		obj->u_fig.cam.pos.x = atof(tab[0]);
		obj->u_fig.cam.pos.y = atof(tab[1]);
		obj->u_fig.cam.pos.z = atof(tab[2]);
	}
	if (value == 2)
	{
		obj->u_fig.cam.vecdir.x = atof(tab[0]);
		obj->u_fig.cam.vecdir.y = atof(tab[1]);
		obj->u_fig.cam.vecdir.z = atof(tab[2]);
	}
	if (value == 3)
	{
		obj->u_fig.cam.upvec.x = atof(tab[0]);
		obj->u_fig.cam.upvec.y = atof(tab[1]);
		obj->u_fig.cam.upvec.z = atof(tab[2]);
	}
	if (value == 4)
	{
		obj->u_fig.cam.rightvec.x = atof(tab[0]);
		obj->u_fig.cam.rightvec.y = atof(tab[1]);
		obj->u_fig.cam.rightvec.z = atof(tab[2]);
	}
	// free_tab(tab);
}

static int	ft_get_data(t_object *obj, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) > 0 && i < 4)
	{
		if (ft_count_word(line, ',') == 2 && ft_last_word(line) == ')')
		{
			if (!i)
				if (ft_strnequ(line, "\tpos(", 5))
					ft_assign_cam(obj, ft_split(&line[5], ',', 1));
			else if (i == 1)
				if (ft_strnequ(line, "\tvecdir(", 8))
					ft_assign_cam(obj, ft_split(&line[8], ',', 2));
			else if (i == 2)
				if (ft_strnequ(line, "\tupvec(", 7))
					ft_assign_cam(obj, ft_split(&line[7], ',', 3));
			else if (i == 3)
				if (ft_strnequ(line, "\trightvec(", 10))
					ft_assign_cam(obj, ft_split(&line[10], ',', 4));
			else
				free_line(line, 1);
		}
		ft_strdel(&line);
	}
	return (0);
}

void	ft_parse_cam(t_object *obj, int fd, int type)
{
	int		i;
	char	*line;

	i = 0;
	obj->type = type;
	if (ft_parse_bracket(fd, 0))
		ft_error("Not a bracket");
	if (ft_parse_color(obj, fd))
		ft_error("Bad color");
	if (ft_get_data(obj, fd))
		ft_error("Bad data");
	if (ft_parse_bracket(fd, 1))
		ft_error("Not a bracket");
}