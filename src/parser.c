/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 12:53:19 by wahasni           #+#    #+#             */
/*   Updated: 2019/08/18 18:28:07 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rtdata.h"
#include <fcntl.h> // Open
#include "libft.h"
#include <stdio.h> // Juste pour tester

void    free_split(char **tab)
{
	int     i;

	i = 0;
    while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_error(char *error)
{
    ft_putendl(error);
    exit (1);
}

void	parser(t_fmlx *rtv, char *file)
{
	int		fd;
	char	*line;

	if ((fd = open(file, 0)) < 0)
		ft_error("Opening file failed.");
	printf("File oppened\n");
    while ((get_next_line(fd, &line)) > 0)
    {
		printf("line-type : %s\n", line);
        if (ft_strequ(line, "camera"))
			ft_parse_camera(rtv, fd);
		// else if (!ft_strequ(line, "plane"))
		// 	ft_parse_plane(rtv, fd);
		// else if (!ft_strequ(line, "sphere"))
		// 	ft_parse_sphere(rtv, fd);
		// else if (!ft_strequ(line, "cyl"))
		// 	ft_parse_cyl(rtv, fd);
		// else if (!ft_strequ(line, "cone"))
		// 	ft_parse_cone(rtv, fd);
		// else if (!ft_strequ(line, "light"))
		// 	ft_parse_light(rtv, fd);
		else if (line)
			ft_error("Bad type.");
        ft_strdel(&line);
    }
	close(fd);
}