/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 12:53:19 by wahasni           #+#    #+#             */
/*   Updated: 2019/08/21 18:23:24 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rtdata.h"
#include <fcntl.h> // Open
#include "libft.h"
#include <stdio.h> // Juste pour tester

int		ft_strpos(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == c)
		return (i);
	return (0);
}

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

static int	ft_parse_name(t_object *obj, char *str)
{
	int i;

	if ((i = ft_strpos(str, ':')) < 2)
		return (1);
	printf("POUAH : %s, i : %d\n", &str[i + 2], i);
	// ft_bzero(obj->name, 15);
	printf("WHY \n");
	if (str[i + 1] == ' ')
	{
		// printf("hekdsgvdvhsdjv\n");
		// printf("WHY %p \n", obj->name);
		// obj->name[2] = 'e';
		ft_strcpy(obj->name, &str[i + 2]); // Pas sur
		printf("PAPAPA\n");	
	}
	if (str[i + 3] == '(' && ft_count_word(str, ')'))
	{
		// Handle of colors
	}
	return (0);
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
		// printf("Value : %d\n", ft_strnequ(line, "camera", 4));
		// printf("Value : %d\n", ft_strnequ(line, "camera", 5));
		// printf("Value : %d\n", ft_strnequ(line, "camera", 6));
		// printf("Value : %d\n", ft_strnequ(line, "camera", 7));
		// printf("Value : %d\n", ft_strnequ(line, "camera", 8));
		if (ft_parse_name(rtv->obj, line))
			ft_error("Bad name/type");
		if (ft_strnequ(line, "camera", 6))
			ft_parse_camera(rtv->obj, fd);
		// else if (!ft_strequ(line, "plane"))
		// 	ft_parse_objs(rtv->obj, fd, RT_PLANE);
		// else if (!ft_strequ(line, "sphere"))
		// 	ft_parse_objs(rtv->obj, fd, RT_SPHERE);
		// else if (!ft_strequ(line, "cyl"))
		// 	ft_parse_objs(rtv->obj, fd, RT_CYL);
		// else if (!ft_strequ(line, "cone"))
		// 	ft_parse_objs(rtv->obj, fd, RT_CONE);
		// else if (!ft_strequ(line, "light"))
		// 	ft_parse_objs(rtv->obj, fd, RT_LIGHT);
		else if (line)
		{
			printf("NAME OF TYPE : %s\n", rtv->obj->name);
			ft_error("Bad type.");
		}
		ft_strdel(&line);
		}
	close(fd);
}

// Pour mon atod return -1 si c'est pas un double