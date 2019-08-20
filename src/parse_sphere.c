/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:30:03 by wahasni           #+#    #+#             */
/*   Updated: 2019/08/20 17:16:07 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtdata.h"
#include "rtv1.h"
#include "libft.h"

int	ft_check_sphere(t_object *obj, char *str)
{
	if (ft_count_word(str, ',') == 2)
	{
		if (ft_strnequ(str, "\tpos(", 5))
			ft_assign_pos(obj, *str);
		else
			return (ERROR);
	}
	else if (!ft_count_word(str, ','))
		if (ft_strnequ(str, "\tradius(", 5))
			obj->u_fig.sphere.radius = atof(&str[8]);
	else
		// ft_error("Bad value sphere");
		// Return error value
}