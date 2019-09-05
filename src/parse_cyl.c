/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cyl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:50:19 by wahasni           #+#    #+#             */
/*   Updated: 2019/08/31 03:35:28 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rtdata.h"
#include "libft.h"
#include <stdio.h>

static int	ft_assign_what(t_object *obj, char *line, int i)
{
	if (!i)
	{
		if (ft_strnequ(line, "\tpos(", 5))
			ft_assign_pos2(obj, &line[5]);
		return (0);
	}
	else if (i == 1)
	{
		if (ft_strnequ(line, "\tdir(", 5))
			ft_assign_dir2(obj, &line[5]);
		return (0);
	}
	else if (i == 2)
	{
		if (ft_strnequ(line, "\tradius(", 8))
			obj->u_fig.cyl.radius = atof(&line[8]);
		return (0);
	}
	return (1);
}

int			ft_parse_cyl(t_object *obj, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (i < 3 && get_next_line(fd, &line) > 0)
	{
		if (ft_count_word(line, ',') == 2 && ft_last_word(line) == ')')
		{
			if (ft_assign_what(obj, line, i))
				free_line(line, 1);
		}
		ft_strdel(&line);
		i++;
	}
	return (0);
}
