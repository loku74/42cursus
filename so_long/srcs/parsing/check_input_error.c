/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:57:33 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/18 17:34:46 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_input_error(int argc, char **argv, t_mlx *mlx)
{
	if (argc == 1)
		errexit(mlx,
			"You must pass as an argument a .ber file formatted the map to load"
			);
	else if (argc > 2)
		errexit(mlx,
			"You must only pass a single .ber file formatted as the map to load"
			);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == 0)
		errexit(mlx,
			"The argument must be a .ber file formatted as the map to load");
	mlx->map_fd = open(argv[1], O_RDONLY);
	if (mlx->map_fd == -1)
		errexit(mlx, strerror(errno));
}
