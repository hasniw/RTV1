/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:10:34 by wahasni           #+#    #+#             */
/*   Updated: 2019/08/26 17:07:36 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rtdata.h"
#include <fcntl.h> // Open
#include "libft.h"
#include <stdio.h> // Juste pour tester

char	ft_last_word(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
		i++;
	return (str[i]);
}

int		free_line(char *line, int i)
{
	ft_strdel(&line);
	return (i);
}

void	ft_error(char *error)
{
	ft_putendl(error);
	exit (1);
}

void	parser(t_fmlx *rtv, char *file)
{
	int fd;
	char *line;

	if ((fd = open(file, 0)) < 0)
		ft_error("Opening file failed.");
	// Parse cam
	if (get_next_line(fd, &line) > 0)
	{
		if (ft_strequ(line, "camera"))
		{
			ft_parse_camera(rtv->obj, fd, RT_CAM);
			ft_strdel(&line);
		}
		else
		{
			ft_strdel(&line);
			ft_error("Without camera");
		}
	}
	while (get_next_line(fd, &line) > 0)
	{
		// Parsing couleur dans first line de l'objet
		// Parsing name
		if (ft_strequ(line, "plane"))
			ft_parse_objs(rtv->obj, fd, RT_PLANE);
		else if (ft_strequ(line, "sphere"))
			ft_parse_objs(rtv->obj, fd, RT_SPHERE);
		else if (ft_strequ(line, "cyl"))
			ft_parse_objs(rtv->obj, fd, RT_CYL);
		else if (ft_strequ(line, "cone"))
			ft_parse_objs(rtv->obj, fd, RT_CONE);
		else if (ft_strequ(line, "light"))
			ft_parse_objs(rtv->obj, fd, RT_LIGHT);
		else if (On a pas ce qu on veut)
			erreur et free ce quil ya a free;
		ft_strdel(&line);
	}
	close(fd);
}