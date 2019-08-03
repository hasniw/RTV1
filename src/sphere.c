/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 01:19:43 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/03 08:43:03 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

double	solve_sphere(t_ray ray, t_vector sphere, double radius)
{
	t_vector	base;
	double		a;
	double		b;
	double		c;

	base = sub_vectors(ray.origin, sphere);
	a = dot_product(ray.dir, ray.dir);
	b = 2.0 * dot_product(ray.dir, base);
	c = dot_product(base, base) - (radius * radius);
	return (ft_solve(a, b, c));
}
