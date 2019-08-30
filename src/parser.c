/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:10:34 by wahasni           #+#    #+#             */
/*   Updated: 2019/08/30 05:39:43 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rtdata.h"
#include <fcntl.h> // Open
#include "libft.h"
#include <stdio.h> // Juste pour tester

// t_list	*ft_lstnew(void const *content, size_t content_size)
// {
// 	t_list	*new;

// 	if (!(new = (t_list *)malloc(sizeof(t_list) * content_size)))
// 		return (NULL);
// 	if (!content)
// 	{
// 		new->content = NULL;
// 		new->content_size = 0;
// 	}
// 	else
// 	{
// 		if (!(new->content = (void *)malloc(content_size)))
// 			return (NULL);
// 		ft_memcpy(new->content, content, content_size);
// 		new->content_size = content_size;
// 	}
// 	new->next = NULL;
// 	return (new);
// }

// t_object	*ft_listnew(void)
// {
// 	t_object *new;

// 	if (!(new = (t_list *)malloc(sizeof(t_list))))
// 		return (NULL);
// 	new->next = NULL;
// }

void	ft_print_data(t_object *bip)
{
	t_object	*obj;
	int			i;

	i = 1;
	obj = (t_object *)bip;
	while (obj)
	{
		printf("Maillon %d : color : %lf\n", i, obj->color);
		i++;
		obj = obj->next;
	}
}

char	ft_last_word(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
		i++;
	return (str[i]);
}

int		free_line(char *line, int i)
{
	ft_strdel(&line);
	return (i);
}

void	ft_error(char *error)
{
	ft_putendl(error);
	exit (1);
}

void	parser(t_fmlx *rtv, char *file)
{
	int fd;
	char *line;

	if ((fd = open(file, 0)) < 0)
		ft_error("Opening file failed.");
	// Parse cam
	if (get_next_line(fd, &line) > 0)
	{
		if (ft_strnequ(line, "camera: ", 8))
		{
			rtv->obj = ft_memalloc(sizeof(rtv->obj));
			ft_parse_cam(rtv->obj, fd, RT_CAM);
			ft_strdel(&line);
		}
		else
		{
			ft_strdel(&line);
			ft_error("Without camera");
		}
	}
	// Creeation du new maillon
	printf("Parsing of camera is good\n");
	t_object *new;
	(new = (t_object *)malloc(sizeof(t_object)));
	rtv->obj->next = new;
	rtv->obj = rtv->obj->next;
	rtv->obj->next = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		// Parsing name -> Use strcat(obj->name, "Le nom")
		printf("NAME : %s\n", line);
		// printf("value compare1 : %d\n", ft_strnequ(line, "light: ", 6));
		// printf("value compare2 : %d\n", ft_strnequ(line, "light: ", 7));
		// printf("value compare3 : %d\n", ft_strnequ(line, "light: ", 8));
		// printf("value compare4 : %d\n", ft_strnequ(line, "light: ", 9));
		// parse name et cree un maillon
		if (ft_strnequ(line, "plane: ", 7)) // Check que l'obj n'existe pas deja
		    ft_parse_objs(rtv->obj, fd, RT_PLANE);
		else if (ft_strnequ(line, "sphere: ", 8)) // Check que l'obj n'existe pas deja
		    ft_parse_objs(rtv->obj, fd, RT_SPHERE);
		else if (ft_strnequ(line, "cylinder: ", 10)) // Check que l'obj n'existe pas deja
	        ft_parse_objs(rtv->obj, fd, RT_CYL);
		else if (ft_strnequ(line, "cone: ", 6)) // Check que l'obj n'existe pas deja
	        ft_parse_objs(rtv->obj, fd, RT_CONE);
		else if (ft_strnequ(line, "light: ", 7)) // Check que l'obj n'existe pas deja
	        ft_parse_objs(rtv->obj, fd, RT_LIGHT);
		// else if (On a pas ce qu on veut) --> pas un obj 
		//      erreur et free ce quil ya a free;
		// ft_print_data(rtv->obj);
		ft_strdel(&line);
        }
        close(fd);
}