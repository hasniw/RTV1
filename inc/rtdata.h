/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtdata.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 01:19:54 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/04 04:51:47 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTDATA_H
# define RTDATA_H
# define SWIN_X		1600
# define SWIN_Y		900
# define SIMG_X		1600
# define SIMG_Y		900
# define RT_WHITE	0xFFFFFF
# define RT_RED		0xFF0000
# define RT_GREEN	0x00FF00
# define RT_BLUE	0x0000FF
# define RT_YELLO	0xFFFF00
# define RT_CYAN	0x00FFFF
# define RT_PURPLE	0xFF00FF

/*
** ============================================================================
** FIGURES.....................................................................
** ============================================================================
*/

typedef struct	s_sphere
{
	t_vector	pos;
	double		radius;
	double		color;
}				t_sphere;

typedef struct	s_plane
{
	t_vector	pos;
	t_vector	dir;
	double		color;
}				t_plane;

typedef struct	s_cylinder
{
	t_vector	pos;
	t_vector	dir;
	double		radius;
	double		color;
}				t_cylinder;

typedef struct	s_cone
{
	t_vector	pos;
	t_vector	dir;
	double		radius;
	double		height;
	double		color;
}				t_cone;

typedef struct	s_light
{
	t_vector	pos;
	double		brightness;
	double		color;
}				t_light;

/*
** ============================================================================
** OBJECT LINKED LIST..........................................................
** ============================================================================
*/

typedef struct	s_object
{
	int				type;
	union
	{
		t_plane		plane;
		t_sphere	sphere;
		t_cylinder	cyl;
		t_cone		cone;
		t_light		light;
	}				u_fig;
	struct s_object	*next;
}				t_object;

/*
** ============================================================================
** MISC........................................................................
** ============================================================================
*/

enum	e_objs
{
	RT_CYL, RT_CONE, RT_PLANE, RT_SPHERE, RT_LIGHT
}

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
}				t_point;

typedef struct	s_viewplane
{
	t_vector	upleft;
	double		dist;
	double		height;
	double		width;
}				t_viewplane;

typedef struct	s_ray
{
	t_object	*hit_by;
	t_vector	origin;
	t_vector	dir;
	double		t;
	int			color;
}				t_ray;

typedef struct	s_camera
{
	t_vector	pos;
	t_vector	vecdir;
	t_vector	upvec;
	t_vector	rightvec;
}				t_camera;
#endif
