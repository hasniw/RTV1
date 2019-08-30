/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cyl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:50:19 by wahasni           #+#    #+#             */
/*   Updated: 2019/08/30 05:04:07 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rtdata.h"
#include "libft.h"
#include <stdio.h>

int ft_parse_cyl(t_object *obj, int fd)
{
    char	*line;
	int		i;

	i = 0;
	while (i < 3 && get_next_line(fd, &line) > 0)
	{
		printf("LINE - parse_data : %s\n", line);
		if (ft_count_word(line, ',') == 2 && ft_last_word(line) == ')')
		{
			if (!i)
			{
				if (ft_strnequ(line, "\tpos(", 5))
					ft_assign_pos2(obj, &line[5]);
			}
			else if (i == 1)
			{
				if (ft_strnequ(line, "\tdir(", 5))
					ft_assign_dir2(obj, &line[5]);
			}
			else if (i == 2)
			{
				if (ft_strnequ(line, "\tradius(", 8))
					obj->u_fig.cyl.radius = atof(&line[8]);
			}
			else
				free_line(line, 1);
		}
		ft_strdel(&line);
		i++;
	}
	return (0);
}
