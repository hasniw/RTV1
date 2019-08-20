/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:01:50 by wahasni           #+#    #+#             */
/*   Updated: 2019/08/20 18:41:38 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rtdata.h"
#include "libft.h"

int		ft_check_obj(t_object *obj, char *str, int type)
{
	// Check si toutes les valeurs sont entrer et qu'elles n'existent pas deja
	// Checker le nombre de virgule
	if (ft_count_word(str, '(') == 1 && ft_count_word(str, ')'))
	{
		if (type == RT_PLANE || type == RT_LIGHT)
		{
			if (ft_strnequ(str, "\tpos(", 5))
				return (ft_assign_pos(obj, str));
			else if (ft_strnequ(str, "\tdir(", 5))
				return (ft_assign_dir(obj, str));
			else
				return (ERROR); // Ou c'est }
		}
		else if (ft_check_sphere(obj, str))
			return (ERROR);
		else if (ft_check_cylinder(obj, str))
			return (ERROR);
		else if (ft_check_cone(obj, str))
			return (ERROR);
	}
	else if (ft_strequ(str, "}")) // Check si les objs ont ete rempli
		type = -1; // Pour quitter la boucle
}

void	ft_parse_objs(t_object *obj, int fd, int type)
{
	int		i;
	char	*line;

	i = 0;
	obj->type = type;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (i == 0)
			if (!ft_strequ(line, "{"))
				ft_error("Bad value object1");
		if (ft_check_obj(obj, line, type))
			ft_error("Bad value object2");
		if (type == -1)
			break ;
	}
}