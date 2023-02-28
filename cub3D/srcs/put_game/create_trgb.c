/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_trgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:27:53 by tibernot          #+#    #+#             */
/*   Updated: 2023/02/28 14:47:08 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

uint32_t	create_trgb(unsigned char t, unsigned char r, unsigned char g,
	unsigned char b)
{
	return (*(int *)(unsigned char [4]){t, r, g, b});
}
