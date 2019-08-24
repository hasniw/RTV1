/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:11:54 by wahasni           #+#    #+#             */
/*   Updated: 2019/08/21 18:20:14 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double  ft_atod(const char *str)
{
    int i;
    int sign;

    while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
				|| str[i] == '\v' || str[i] == ' ' || str[i] == '\f'))
		i++;
    sign = (str[i] == '-') ? -1 : 1;
	if (sign == -1 || str[i] == '+')
		i++;
    
}