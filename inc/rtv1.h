/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:55:16 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/07/29 08:07:03 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
#include "rtdata.h"

typedef struct	s_fmlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*screen;
}				t_fmlx;


/*
**	======================== /(  )\ =========================
**	                         EVENTS
**	======================== \(  )/ =========================
*/

int				deal_key(int key, t_fmlx *mlx);
int				mouse_roll(int button, int x, int y, t_fmlx *mlx);
int				mouse_move(int x, int y, t_fmlx *mlx);

/*
**	========================== /( )\ ========================
**	                           TOOLS
**	========================== \( )/ ========================
*/

void			rtv_exit(t_fmlx *mlx);
void			fill_pxl(char *image, int x, int y, int color);

/*
**	========================== /( )\ ========================
**	                    VECTOR OPERATIONS
**	========================== \( )/ ========================
*/

t_vector	vector_sub(t_vector a, int nbr);
t_vector	vector_mult(t_vector a, int nbr);
t_vector	add_vectors(t_vector a, t_vector b);
t_vector	sub_vectors(t_vector a, t_vector b);
t_vector	init_vector(double x, double y, double z);
void		get_viewplane(t_viewplane *vp, t_camera cam);
t_vector	get_dir(t_viewplane vp, t_camera cam, t_point indent, t_point coords);
t_point		get_indent(t_viewplane vp);
void		rt(t_fmlx *mlx);

#endif
