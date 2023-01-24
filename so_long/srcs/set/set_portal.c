/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_portal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:19:43 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/18 18:28:37 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_portal(t_mlx *mlx)
{
	mlx->portal[0] = "Adventurer-xpm/portal/portal_00.xpm";
	mlx->portal[1] = "Adventurer-xpm/portal/portal_01.xpm";
	mlx->portal[2] = "Adventurer-xpm/portal/portal_02.xpm";
	mlx->portal[3] = "Adventurer-xpm/portal/portal_03.xpm";
	mlx->portal[4] = "Adventurer-xpm/portal/portal_04.xpm";
	update_portal(mlx, mlx->portal[0]);
}
