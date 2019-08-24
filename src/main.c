/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 00:26:11 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/24 18:54:25 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "rtv1.h"
#include "rtdata.h"
#include "libft.h"

void	rtv(void)
{
	t_fmlx		ptr;
	int			tools[3];

	if (!(ptr.mlx = mlx_init()))
		rtv_exit(&ptr);
	if (!(ptr.win = mlx_new_window(ptr.mlx, SWIN_X,
					SWIN_Y, "RTv1 by mpivet-p and wahasni")))
		rtv_exit(&ptr);
	if (!(ptr.img = mlx_new_image(ptr.mlx, SIMG_X, SIMG_Y)))
		rtv_exit(&ptr);
	if (!(ptr.screen = mlx_get_data_addr(ptr.img, &(tools[0]),
					&(tools[1]), &(tools[2]))))
		rtv_exit(&ptr);
	mlx_hook(ptr.win, 2, 0, deal_key, &ptr);
	mlx_hook(ptr.win, 4, 0, mouse_press, &ptr);
//	mlx_hook(ptr.win, 6, 0, mouse_move, &ptr);
	rt(&ptr);
	mlx_loop(ptr.mlx);
}

int		main(int argc, char **argv)
{
	t_fmlx	ptr;

	if (argc != 2)
	{
		ft_putstr_fd("usage: rtv1 <file>\n", 2);
		return (1);
	}
	// TEST ATOD : 
	printf("Double max : %lf", DBL_MAX);
	printf("TEST ATOD\n");
	char *str = "";
	char *str2 = "    153.556";
	char *str3 = "153.556.1";
	char *str4 = "153";
	char *str5 = "ab153";
	printf("str : %lf\n", ft_atod(str));
	printf("str2 : %lf\n", ft_atod(str2));
	printf("str3 : %lf\n", ft_atod(str3));
	printf("str4 : %lf\n", ft_atod(str4));
	printf("str5 : %lf\n", ft_atod(str5));
	parser(&ptr, argv[1]);
	rtv();
	return (0);
}
