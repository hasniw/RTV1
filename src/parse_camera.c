/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 15:34:06 by wahasni           #+#    #+#             */
/*   Updated: 2019/08/21 17:59:01 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rtdata.h"
#include "libft.h"
#include <string.h> // Le temps de coder atod
#include <stdio.h> // Juste pour tester

static void	ft_assign_value(t_object *obj, char **tab, int value)
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
}

static int	ft_check_line(char *str, int value)
{
	//Check nombre de nombre/virgule
	if (ft_strnequ(str, "\tpos(", 5))
		return (1);
	else if (ft_strnequ(str, "\tvec(", 5))
		return (2);
	else if (ft_strnequ(str, "\tupv(", 5))
		return (3);
	else if (ft_strnequ(str, "\trvec(", 5))
		return (4);
	(void)value;
	// CHANGER LES NOMS
	// else if (value)
	// 	ft_error("Bad value camera3");
	// Check si des valeurs ont pas deja ete attribue a pos ou dir
	// Check les derniers caracteres aussi
	return (0);
}

void	ft_parse_camera(t_object *obj, int fd)
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
        if (i == 5) // A gechan s'il y'a plus d'element dans la partie camera
			if (!ft_strequ(line, "}"))
				ft_error("Bad value camera2");
		if ((whos = ft_check_line(line, whos)))
			split = ft_strsplit(&line[5], ',');
		ft_assign_value(obj, split, whos);
		// free_split(split); // Voir pq sa crash
		i++;
		if (ft_strequ(line, "}"))
			break ;
	}
}