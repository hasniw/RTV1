/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:29:56 by wahasni           #+#    #+#             */
/*   Updated: 2019/08/20 18:38:22 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtdata.h"
#include "rtv1.h"
#include "libft.h"

/*
    t_vector	pos;
	t_vector	dir;
	double		radius;
	double		height;
*/

int ft_check_cone(t_object *obj, char *str)
{
    if (ft_count_word(str, ',') == 2)
	{
        if (ft_strnequ(str, "\tpos(", 5))
            ft_assign_pos2(obj, str);
        else if (ft_strnequ(str, "\tdir(", 5))
            ft_assign_dir2(obj, str);
    }
    else if (!ft_count_word(str, ','))
    {
        if (ft_strnequ(str, "\tradius(", 5))
			obj->u_fig.cone.radius = atof(&str[8]);
        else if (ft_strnequ(str, "\tradius(", 5))
            obj->u_fig.cone.height = atof(&str[8]);
    }
    else
}