/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:35:01 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/16 06:34:41 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "rtv1.h"
#include "libft.h"

double	diffuse_light(t_ray *ray, t_light *light, t_vector *position)
{
	double		angle;

	angle = dot_product(
			get_normal(ray, *position), vector_mult(light->dir, -1));
	if (angle > 0)
		return (angle);
	return (0);
}

double	specular_light(t_ray *ray, t_light *light, t_vector *position)
{
	t_vector	vec;
	double		spec;

	vec = bisector(vector_mult(light->dir, -1), ray->dir);
	spec = ft_max(0, dot_product(get_normal(ray, *position), vec));
	return (1.2 * pow(spec, 64));
}

double	is_lighted(t_vector *pos, t_light *light, t_object *obj)
{
	t_vector	nearest;
	t_ray		ray;

	ray.t = 0;
	ray.hit_by = NULL;
	ray.color = 0;
	ray.dir = normalize(vector_mult(light->dir, -1));
	ray.origin = *pos;
	get_intersection(&ray, obj);
	if (ray.t > 0)
	{
		nearest = ray_to_point(&ray);
		if (get_dist(pos, &light->pos) > get_dist(pos, &nearest))
			return (0);
		return (1);
	}
	return (1);
}

int		get_light_obj(t_light *light, t_vector *position, t_object *obj)
{
	while (obj)
	{
		if (obj->type == RT_LIGHT)
		{
			light->pos = obj->u_fig.light.pos;
			light->dir = normalize(sub_vectors(*position, light->pos));
			return (0);
		}
		obj = obj->next;
	}
	return (1);
}
t_vector	get_color(t_ray *ray, t_object *obj)
{
	t_vector	position;
	t_vector	color;
	t_light		light;
	double		coeff;

 	coeff = AMBIENT_STRENGTH;
	position = add_vectors(ray->origin, vector_mult(ray->dir, ray->t));
	position = add_vectors(position, vector_mult(get_normal(ray, position), 0.0000001));
	if (get_light_obj(&light, &position, obj) == 0 && is_lighted(&position, &light, obj) == 1)
		coeff += diffuse_light(ray, &light, &position) + specular_light(ray, &light, &position);
	color = mult_color(ray->hit_by->color, init_vector(coeff, coeff, coeff));
	return (color);
}
