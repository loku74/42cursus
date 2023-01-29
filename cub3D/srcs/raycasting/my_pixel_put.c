#include "../../includes/cub3D.h"

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
