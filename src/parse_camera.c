/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 15:34:06 by wahasni           #+#    #+#             */
/*   Updated: 2019/08/20 12:54:19 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rtdata.h"
#include "libft.h"
#include <string.h> // Le temps de coder atod
#include <stdio.h> // Juste pour tester

static void	ft_assign_value(t_fmlx *rtv, char **tab, int value)
{
	// Si la valeur est superieur au double -> 0 à la variable
	if (value == 1)
	{
		rtv->cam.pos.x = atof(tab[0]);
		rtv->cam.pos.y = atof(tab[1]);
		rtv->cam.pos.z = atof(tab[2]);
	}
	if (value == 2)
	{
		rtv->cam.vecdir.x = atof(tab[0]);
		rtv->cam.vecdir.y = atof(tab[1]);
		rtv->cam.vecdir.z = atof(tab[2]);
	}
}

static int	ft_check_line(char *str, int value)
{
	if (ft_strnequ(str, "\tpos(", 5))
		return (1);
	else if (ft_strnequ(str, "\tdir(", 5))
		return (2);
	(void)value;
	// else if (value)
	// 	ft_error("Bad value camera3");
	// Check si des valeurs ont pas deja ete attribue a pos ou dir
	// Check les derniers caracteres aussi
	return (0);
}

void	ft_parse_camera(t_fmlx *rtv, int fd)
{
	int		i;
	int		whos;
	char	*line;
	char	**split;

	i = 0;
	whos = 0;
	printf("DOING parse camera\n");
	while ((get_next_line(fd, &line)) > 0)
	{
		printf("line-camera : %s\n", line);
		if (i == 0)
			if (!ft_strequ(line, "{"))
				ft_error("Bad value camera1");
        if (i == 4)
			if (!ft_strequ(line, "}"))
				ft_error("Bad value camera2");
		if ((whos = ft_check_line(line, whos)))
			split = ft_strsplit(&line[5], ',');
		printf("Before assign value\n");
		printf("value : %d\n", whos);
		ft_assign_value(rtv, split, whos);
		// free_split(split); // Voir pq sa crash
		i++;
		if (i == 4)
			break ;
		printf("<----------------------------->\n");
	}
	printf("parse-camera finish !\n");
	printf("x : %f\n", rtv->cam.pos.x);
}