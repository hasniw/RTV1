/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:50:05 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/07/30 07:01:09 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "rtdata.h"
#include "rtv1.h"
#include "stdio.h"

void	rt_init(t_camera *cam, t_viewplane *vp)
{
	vp->height = SIMG_Y;
	vp->width = SIMG_X;
	vp->dist = 1000;
	cam->pos = init_vector(0, 0, 0);
	cam->vecdir = init_vector(0, 0, 1);
	cam->upvec = init_vector(0, 1, 0);
	cam->rightvec = init_vector(1, 0, 0);
}

int		rt_render(t_fmlx *mlx, t_camera cam, t_ray ray, t_viewplane *vp)
{
	int x;
	int y;

	x = 0;
	y = 0;
	(void)cam;
	(void)vp;
	while (x < SIMG_X)
	{
		while (y < SIMG_Y)
		{
			ray.dir = get_dir(*vp, cam, ray, get_indent(*vp, init_point(x, y, 0)));
			printf("%f", solve_sphere(ray, init_vector(0, 0, 0), 0.05));
			if (solve_sphere(ray, init_vector(0, 0, 0), 0.05) > 0.0)
				fill_pxl(mlx->screen, x, y, 0xFF0000);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

void	rt(t_fmlx *mlx)
{
	t_viewplane	vp;
	t_camera	cam;
	t_ray		ray;

	ray.origin.x = 0;
	ray.origin.y = 0;
	ray.origin.z = 0;
	rt_init(&cam, &vp);
	get_viewplane(&vp, cam);
	rt_render(mlx, cam, ray, &vp);
}
